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

#ifndef CRCXX_DETAIL_CRC_PRIMITIVES_HPP_8C02F536252A0259D44EE35FFFF9865578428256
#define CRCXX_DETAIL_CRC_PRIMITIVES_HPP_8C02F536252A0259D44EE35FFFF9865578428256

#include <stdint.h>
#include <limits.h>

namespace crcxx {

  namespace detail {

    enum crc_method {
      BIT_BY_BIT,
      USE_TABLE,
      USE_SMALL_TABLE
    };

    template <typename Algorithm, crc_method Method>
    struct crc_primitives
    {

      ///////////////////////////////////////// Primitives for CRC computation ////////////////////////////////////////

      using base_type = typename Algorithm::base_type;

      // Shift a value forward, i.e. left when MSB first, right when LSB first.
      static constexpr base_type shift_forward(base_type value, int shift)
      {
        return forward ? (shift >= 0 ? value << shift : value >> shift)
                       : (shift >= 0 ? value >> shift : value << shift);
      }

      // Reverse bit order of value if cond == true, otherwise returns value.
      static constexpr base_type reflect_if(bool cond, base_type value, base_type result = 0, uint_fast8_t i = 0)
      {
        return cond ? (i < base_type_bits
                        ? reflect_if(cond, value >> 1, (result << 1) | (value & 1), i + 1)
                        : result)
                    : value;
      }

      // Adjust poly and init for computation, according to direction and base_type_width.
      static constexpr base_type adjusted_param(base_type value)
      {
        return shift_forward(reflect_if(!forward, value), base_type_bits - Algorithm::width);
      }

      // Adjust input for computation, according to direction and base_type_width.
      static constexpr base_type adjusted_input(uint8_t value)
      {
        return shift_forward(reflect_if(refin, value), forward ? base_type_bits - 8 : 0);
      }

      // Shift the checksum and xors poly when appropriate.
      static constexpr base_type shift_checksum(base_type checksum, unsigned bits)
      {
        return bits > 0
          ? shift_checksum(shift_forward(checksum, 1) ^ (checksum & next_bit_mask ? poly : 0), bits - 1)
          : checksum;
      }


      ///////////////////////////////////////////// Computation parameters ////////////////////////////////////////////

      // Algorithm parameters are statically adjusted in order to optimize the computation, thence avoiding (as far as
      // possible) shifting/reflecting input bytes and the final result.

      static constexpr unsigned base_type_bits = sizeof(base_type) * CHAR_BIT;

      // When method == BIT_BY_BIT, forward is set in order to avoid reflecting input bytes, otherwise, forward is set
      // in order to avoid reflecting the final result.
      static constexpr bool forward = Method != BIT_BY_BIT ? !Algorithm::refin : !Algorithm::refout;

      // refin and refout are adjusted according to the direction of the computation.
      static constexpr bool refin  = !forward ^ Algorithm::refin;
      static constexpr bool refout = !forward ^ Algorithm::refout;

      // Items in the lookup table must be reflected when refin != refout to avoid reflecting the final result.
      static constexpr bool ref_table = refin != refout;

      static constexpr base_type next_bit_mask = forward ? base_type(1) << base_type_bits - 1 : 1;

      // poly and init are adjusted according to the direction and bit-order of the computation.
      static constexpr base_type poly = adjusted_param(Algorithm::poly);
      static constexpr base_type init = adjusted_param(Algorithm::init);
      // xorout is not adjusted because it is applied after the final result is reflected/shifted.


    };

  } // namespace detail

} // namespace crcxx

#endif // CRCXX_DETAIL_CRC_PRIMITIVES_HPP_8C02F536252A0259D44EE35FFFF9865578428256
