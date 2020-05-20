#!/usr/bin/perl

# This script scraps data from CRC RevEng (by Greg Cook) catalogue of CRC algorithms and creates
# a json file containing a list of CRC algorithm parameters.

use strict;
use warnings 'all';

use constant URL       => 'http://reveng.sourceforge.net/crc-catalogue/all.htm';

sub fetch_algos {
  my @algos;
  my %algo;
  print STDERR "Downloading '${\URL}' ... ";
  my $html = `curl -s "${\URL}"`;                         # Download catalogue HTML from URL
  die("\nUnable to download CRC catalogue!") if $?;
  print STDERR "ok\nParsing ...";
  foreach (split /\n/, $html) {
    s#\s+# #g;                                            # Coalesce multiple spaces
    s#^\s+|\s+$##g;                                       # Remove spaces from BOL and EOL
    if (m#<CODE>(width=[^<]+)</CODE>#) {                  # Algorithm params line
      push @algos, { %algo } if %algo;                    # Push last %algo to @algos
      %algo = ();                                         # And start a new one
      m/
          width   =    (?<width>   [0-9]+       ) \s      # Parse algorithm params
          poly    = 0x (?<poly>    [0-9a-fA-F]+ ) \s
          init    = 0x (?<init>    [0-9a-fA-F]+ ) \s
          refin   =    (?<refin>   true | false ) \s
          refout  =    (?<refout>  true | false ) \s
          xorout  = 0x (?<xorout>  [0-9a-fA-F]+ ) \s
          check   = 0x (?<check>   [0-9a-fA-F]+ ) \s
          residue = 0x (?<residue> [0-9a-fA-F]+ ) \s
          name    =  " (?<name>    [^"]+        ) "
      /xn;
      %algo = %+;                                         # Set %algo with new params
    } elsif (m#<li>Alias: (?:<a name="[^"]+"><strong>[^<]+</strong></a>,?\s*)+</li>#i) {
                                                          # Algorithm aliases line
      s#</?(?:LI|STRONG|A)[^>]*>##g;                      # Remove HTML tags
      s#^Alias: ##g;                                      # Remove /^Alias: /
      my @aliases = split(/, /, $_);                      # Split aliases
      $algo{aliases} = \@aliases;                         # Add aliases to %algo
    }
  }
  push @algos, { %algo } if %algo;                        # Push last %algo to @algos
  die "\nI couldn't find any algorithm at ${\URL}!" if (!@algos);
  print STDERR " ok", "\n";
  return @algos;
}

my %used_identifiers = ( );

sub make_algo_identifier {
  my ($width, $name) = @_;
  for ($name) {
    s/[^0-9A-Za-z]+/_/g;
    s/CRC_?\d*//g;
    s/_(\d+)/$1/g;
    s/^_+//g;
    $_ = "CRC${width}_$_";
    s/__+/_/g;
    s/_+$//g;
  }
  return $name;
}

sub print_algos {
  my @algos = @_;
  print "// THIS FILE WAS AUTOMATICALLY GENERATED, DO NOT EDIT.

#ifndef CRCXX_CRC_CATALOGUE_HPP_
#define CRCXX_CRC_CATALOGUE_HPP_

#include \"crc_algorithm.hpp\"

namespace crcxx {

  namespace algorithms {
";
  foreach (@algos) {
    my $algo = $_;
    if (($algo->{width}+0) > 64) {
      print STDERR "Skipping algorithm $algo->{name}: width > 64\n";
      next
    }
    my $identifier = make_algo_identifier($algo->{width}, $algo->{name});
    if ($used_identifiers{$identifier}) {
      die "Identifier already used: $identifier\n";
    }
    $used_identifiers{$identifier} = 1;
    # Print algorithm data
    print "
    ///
    /// $algo->{name}
    ///
    using $identifier = ::crcxx::crc_algorithm<
      /* Width   = */ $algo->{width},
      /* Poly    = */ 0x$algo->{poly},
      /* Init    = */ 0x$algo->{init},
      /* Refin   = */ $algo->{refin},
      /* Refout  = */ $algo->{refout},
      /* Xorout  = */ 0x$algo->{xorout},
      /* Check   = */ 0x$algo->{check},
      /* Residue = */ 0x$algo->{residue}
    >;
    ";
    foreach my $alias (@{$algo->{aliases}}) {
      if ($alias) {
        # Print aliases
        my $alias_identifier = make_algo_identifier($algo->{width}, $alias);
        if ($alias_identifier =~ m/^CRC\d+$/) {
          print STDERR "Unspecific identifier discarded: $alias_identifier, alias for $identifier\n";
          next
        } elsif ($used_identifiers{$alias_identifier}) {
          print STDERR "Duplicate identifier discarded: $alias_identifier, alias for $identifier\n";
          next
        }
        $used_identifiers{$alias_identifier} = 1;
        print "
    ///
    /// $alias is an alias for $algo->{name}
    ///
    using ${alias_identifier} = $identifier;
    ";
      }
    }
  }
  print "
  }; // namespace algorithms

}; // namespace crcxx

#endif // CRCXX_CRC_CATALOGUE_HPP_
";
}

print_algos fetch_algos;
