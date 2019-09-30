// crcxx, a header-only library for computing CRCs written in modern C++
//
// Copyright (C) 2019 Andre Kugland
//
// This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation; either version 2.1 of the License, or (at your option)
// any later version.
//
// This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
// details.
//
// You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to
// the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

#ifndef CRCXX_CRC_ALGORITHM_HPP_A20D1FF5019FB76F3393B160AE4AD1216684C55C
#define CRCXX_CRC_ALGORITHM_HPP_A20D1FF5019FB76F3393B160AE4AD1216684C55C

#include <stdint.h>

#include "detail/base_type.hpp"

namespace crcxx {

  /// Representation of the parameters of a CRC algorithm.
  ///
  /// \tparam Width   width of the algorithm, i.e. the degree of its polynomial.
  /// \tparam Poly    polynomial coefficients represented as a bitmap.
  /// \tparam Init    initial value of the computation.
  /// \tparam Refin   true if its input should be least significant bit first.
  /// \tparam Refout  true if its output should be least significant bit first.
  /// \tparam Xorout  xor mask for the output.
  /// \tparam Check   value of CRC("123456789").
  /// \tparam Residue value of CRC(str + CRC(str)).
  template <
    unsigned  Width,
    uintmax_t Poly,
    uintmax_t Init,
    bool      Refin,
    bool      Refout,
    uintmax_t Xorout,
    uintmax_t Check,
    uintmax_t Residue
  >
  struct crc_algorithm
  {
    using base_type = typename ::crcxx::detail::base_type<Width>::type;

    static constexpr unsigned  width    = Width;
    static constexpr base_type poly     = base_type(Poly);
    static constexpr base_type init     = base_type(Init);
    static constexpr bool      refin    = Refin;
    static constexpr bool      refout   = Refout;
    static constexpr base_type xorout   = base_type(Xorout);
    static constexpr base_type check    = base_type(Check);
    static constexpr base_type residue  = base_type(Residue);

    static_assert(width   >= 1,       "Width must be >= 1");
    static_assert(width   <= 64,      "Width must be <= 64");
    static_assert(poly    == Poly,    "Poly doesn't fit the given Width");
    static_assert(poly    != 0,       "Poly can't be zero");
    static_assert(poly    %  2,       "Poly can't be an even number");
    static_assert(init    == Init,    "Init doesn't fit the given Width");
    static_assert(xorout  == Xorout,  "Xorout doesn't fit the given Width");
    static_assert(check   == Check,   "Check doesn't fit the given Width");
    static_assert(residue == Residue, "Residue doesn't fit the given Width");
  };

} // namespace crcxx

#endif // CRCXX_CRC_ALGORITHM_HPP_A20D1FF5019FB76F3393B160AE4AD1216684C55C
