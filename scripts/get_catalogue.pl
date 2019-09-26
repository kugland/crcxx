#!/usr/bin/perl

# This script scraps data from CRC RevEng (by Greg Cook) catalogue of CRC algorithms
# and creates a json file containing a list of CRC algorithm parameters.

use strict;
use warnings 'all';

use JSON::PP;

use constant URL       => "http://reveng.sourceforge.net/crc-catalogue/all.htm";
use constant JSON_FILE => "crc_catalogue.json";

my @algos;
my %algo;

print "Downloading '${\URL}' ... ";

my $html = `curl -s "${\URL}"`;                             # Download catalogue HTML from URL
die("\nUnable to download CRC catalogue!") if $?;

print "ok\nParsing ...";

foreach (split /\n/, $html) {
    s#\s+# #g;                                              # Coalesce multiple spaces
    s#^\s+|\s+$##g;                                         # Remove spaces from BOL and EOL

    if (m#<CODE>(width=[^<]+)</CODE>#) {                    # Algorithm params line

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
push @algos, { %algo } if %algo;                            # Push last %algo to @algos

die "\nI couldn't find any algorithm at ${\URL}!" if (!@algos);

my $json = JSON::PP->new->utf8                              # Encode @algos as JSON
    ->canonical(1)
    ->indent(1)
    ->indent_length(2)
    ->encode(\@algos);

print " ok\nSaving '${\JSON_FILE}' ...";                    # Save it to JSON_FILE
open(my $fh, '>', JSON_FILE) or die("\nUnable to open '${\JSON_FILE}'!");
print $fh $json or die("\nUnable to write to '${\JSON_FILE}'!");
close $fh;
print " ok\n";
