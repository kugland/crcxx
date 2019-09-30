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

#ifndef CRCXX_DETAIL_CONFIG_HPP_42B45C48DE24E364185BEAA83FB83AA9CB816E88
#define CRCXX_DETAIL_CONFIG_HPP_42B45C48DE24E364185BEAA83FB83AA9CB816E88

// When CRCXX_USE_STL is enabled, crcxx includes functions for dealing with STL containers
// std::string, std::array, std::vector and (if std >= C++17) std::string_view.
//
// For now, it is enabled by default except when compiling for AVR architecture.
#ifndef CRCXX_USE_STL
#if !defined(__AVR__)
#define CRCXX_USE_STL 1
#else
#define CRCXX_USE_STL 0
#endif
#endif

// When CRCXX_USE_FAST_TYPES is enabled, computation is done using uint_fastX_t instead of uintX_t.
//
// Defaults to true unless optimizing for size (-Os).
#ifndef CRCXX_USE_FAST_TYPES
#ifndef __OPTIMIZE_SIZE__
#define CRCXX_USE_FAST_TYPES 1
#else
#define CRCXX_USE_FAST_TYPES 0
#endif
#endif

#endif // CRCXX_DETAIL_CONFIG_HPP_42B45C48DE24E364185BEAA83FB83AA9CB816E88
