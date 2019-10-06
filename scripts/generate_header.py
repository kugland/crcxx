#!/usr/bin/env python3

# This script takes crc_catalogue.json and transforms it into crcxx_algorithms.hpp.

import re
import math
import json
import sys


numeric_params = ['poly', 'init', 'xorout', 'check', 'residue']
used_identifiers = set()  # Keep track of used identifiers to avoid collisions.


def cxx_identifier(algo, name):
    """
    Generate C++ identifier for an algorithm.

    >>> cxx_identifier(32, 'CRC-32/CASTAGNOLI')
    'CRC32_CASTAGNOLI'

    >>> cxx_identifier(32, 'PKZIP')
    'CRC32_PKZIP'
    """

    suffix_subs = [
        (r'[^0-9A-Za-z]', '_'),
        (r'CRC_?\d+', ''),
        (r'^_+', ''),
        (r'_+$', ''),
    ]
    prefix = "CRC{0}".format(algo['width'])
    suffix = name.upper()
    for regexp, replacement in suffix_subs:
        suffix = re.sub(regexp, replacement, suffix)

    return '_'.join(filter(lambda s: len(s) != 0, [prefix, suffix]))


def load_algos():
    """
    Load algorithms from crc_catalogue.json.

    :return: List of algorithms
    """
    algos = []
    for algo in json.load(open("crc_catalogue.json", "r")):
        algo['width']   = int(algo['width'])
        if algo['width'] > 64:  # Discard any algorithm with width > 64
            continue
        algo['identifier']  = cxx_identifier(algo, algo['name'])
        algo['refin']       = algo['refin'] == 'true'
        algo['refout']      = algo['refout'] == 'true'
        used_identifiers.add(algo['identifier'])
        for param in numeric_params:
            algo[param] = int(algo[param], 16)
        algos.append(algo)
    return algos


file_template = """
// THIS FILE WAS AUTOMATICALLY GENERATED, DO NOT EDIT.

#ifndef CRCXX_CRC_CATALOGUE_HPP_
#define CRCXX_CRC_CATALOGUE_HPP_

#include "crc_algorithm.hpp"

namespace crcxx {{

  namespace algorithms {{
{algorithms}
  }}

}}

#endif // CRCXX_CRC_CATALOGUE_HPP_
""".strip("\n")

algorithm_template = """
    ///
    /// {name}
    ///
    using {identifier} = ::crcxx::crc_algorithm<
      /* Width   = */ {width},
      /* Poly    = */ {poly},
      /* Init    = */ {init},
      /* Refin   = */ {refin},
      /* Refout  = */ {refout},
      /* Xorout  = */ {xorout},
      /* Check   = */ {check},
      /* Residue = */ {residue}
    >;
"""

alias_template = """
    ///
    /// {alias} is an alias for {name}
    ///
    using {alias_identifier} = {identifier};
"""


def format_algos(algos):
    result = []
    for algo in algos:
        algo['refin']   = algo['refin']  and 'true' or 'false'
        algo['refout']  = algo['refout'] and 'true' or 'false'
        for param in numeric_params:
            algo[param] = ('0x{0:0' + str(math.ceil(algo['width'] / 4)) + 'x}').format(algo[param])
        result.append(algorithm_template.format(**algo))
        used_identifiers.add(algo['identifier'])
        if 'aliases' in algo:
            for alias in sorted(algo['aliases']):
                alias_identifier = cxx_identifier(algo, alias)
                if alias_identifier == algo['identifier']:
                    continue
                if re.match(r'^CRC\d+$', alias_identifier):
                    print("Unspecific identifier discarded: {0}, alias for {1}"
                        .format(alias_identifier, algo['identifier']), file=sys.stderr)
                    continue
                if alias_identifier in used_identifiers:
                    print("Duplicate identifier discarded: {0}, alias for {1}"
                        .format(alias_identifier, algo['identifier']), file=sys.stderr)
                    continue
                result.append(alias_template.format(
                    alias=alias,
                    alias_identifier=alias_identifier,
                    **algo))
                used_identifiers.add(alias_identifier)
    return file_template.format(algorithms="".join(result))


print(format_algos(load_algos()))
