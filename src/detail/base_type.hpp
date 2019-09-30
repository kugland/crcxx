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

#ifndef CRCXX_DETAIL_BASE_TYPE_HPP_DDEDF398C5A47027CC3DCE1C1ACFD7669F00F354
#define CRCXX_DETAIL_BASE_TYPE_HPP_DDEDF398C5A47027CC3DCE1C1ACFD7669F00F354

#include <stdint.h>

#include "config.hpp"

namespace crcxx {

  namespace detail {

    // Select base type according to Width.
    template <unsigned Width>
    struct base_type
    {
      static_assert(Width >= 1,  "Width must be >= 1");
      static_assert(Width <= 64, "Width must be <= 64");

      // Recurse until Width equals 8, 16, 32 or 64.
      using type = typename base_type<Width + 1>::type;
    };

#if CRCXX_USE_FAST_TYPES

    template <> struct base_type<8>  { using type = uint_fast8_t;  };
    template <> struct base_type<16> { using type = uint_fast16_t; };
    template <> struct base_type<32> { using type = uint_fast32_t; };
    template <> struct base_type<64> { using type = uint_fast64_t; };

#else

    template <> struct base_type<8>  { using type = uint_least8_t;  };
    template <> struct base_type<16> { using type = uint_least16_t; };
    template <> struct base_type<32> { using type = uint_least32_t; };
    template <> struct base_type<64> { using type = uint_least64_t; };

#endif

  } // namespace detail

} // namespace crcxx

#endif // CRCXX_DETAIL_BASE_TYPE_HPP_DDEDF398C5A47027CC3DCE1C1ACFD7669F00F354
