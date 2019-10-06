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

#ifndef CRCXX_CRCXX_HPP_
#define CRCXX_CRCXX_HPP_

#include <stdint.h>
#include <limits.h>
#include <stdlib.h>


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////// CONFIGURATION MACROS ////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// When CRCXX_USE_STL is enabled, crcxx includes functions for dealing with STL containers std::string, std::array,
// std::vector and (if std >= C++17) std::string_view.
//
// For now, it is enabled by default except when compiling for AVR architecture.
#ifndef CRCXX_USE_STL
#if !defined(__AVR__)
#define CRCXX_USE_STL 1

#if __cplusplus >= 201402
#include <utility>
#define CRCXX_USE_STL_INDEX_SEQUENCE 1
#endif

#else
#define CRCXX_USE_STL 0
#endif
#endif


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////// CONSTANTS //////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


namespace crcxx {

  enum crc_method {
    BIT_BY_BIT,
    USE_TABLE,
    USE_SMALL_TABLE
  };

} // namespace crcxx



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////// FORWARD DECLARATIONS ////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


namespace crcxx {

  namespace detail {

    template <unsigned Width>
    struct select_base_type;

    template <typename Algorithm, crc_method Method>
    class crc_primitives;

    template <typename Algorithm, crc_method Method>
    struct crc_lookup_table;

  } // namespace crcxx

} //namespace detail



namespace crcxx {

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////// crcxx::crc_algorithm ///////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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
    using base_type = typename detail::select_base_type<Width>::type;

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
    static_assert(poly    == Poly,    "Poly doesn't fit");
    static_assert(poly    != 0,       "Poly can't be zero");
    static_assert(poly    %  2,       "Poly can't be even");
    static_assert(init    == Init,    "Init doesn't fit");
    static_assert(xorout  == Xorout,  "Xorout doesn't fit");
    static_assert(check   == Check,   "Check doesn't fit");
    static_assert(residue == Residue, "Residue doesn't fit");
  };


  template <typename Algorithm, crc_method Method>
  class crc
  {

    using base_type    = typename Algorithm::base_type;
    using primitives   = detail::crc_primitives<Algorithm, Method>;
    using lookup_table = detail::crc_lookup_table<Algorithm, Method>;

    base_type checksum = primitives::init;

  public:

    void update(char data)
    {
      checksum ^= primitives::adjusted_input(data, 8);

      if (Method == BIT_BY_BIT) {
        checksum = primitives::shift_checksum(checksum, 8);
      } else {
        const static lookup_table table;
        uint_fast8_t repeat = Method == USE_TABLE ? 1 : 2;

        while (repeat--)
          checksum = primitives::shift_forward(checksum, lookup_table::table_bits) ^ table[checksum];
      }
    }

    void update(size_t size, const char* data)
    {
      while (size--) {
        update(*data++);
      }
    }

    base_type finalize() const
    {
      return primitives::finalize(checksum);
    }

  };


  namespace detail {

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////  BASE TYPE FOR CRC COMPUTATION  /////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    // Select base type according to Width.
    template <unsigned Width>
    struct select_base_type
    {
      static_assert(Width >= 1,  "Width must be >= 1");
      static_assert(Width <= 64, "Width must be <= 64");

      // Recurse until one of the defined specializations is found.
      using type = typename select_base_type<Width + 1>::type;
    };

    template <> struct select_base_type<8>  { using type = uint_least8_t;  };
    template <> struct select_base_type<16> { using type = uint_least16_t; };
    template <> struct select_base_type<32> { using type = uint_least32_t; };
    template <> struct select_base_type<64> { using type = uint_least64_t; };



    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////   PRIMITIVES & PARAMETERS FOR CRC COMPUTATION  //////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    template <typename Algorithm, crc_method Method>
    struct crc_primitives
    {

      using base_type = typename Algorithm::base_type;


      ///////////////////////////////////////// Primitives for CRC computation ////////////////////////////////////////

      // Shift a value forward, i.e. left when MSB first, right when LSB first.
      static constexpr base_type shift_forward(base_type value, int shift)
      {
        return msb_first ? (shift >= 0 ? value << shift : value >> -shift)
                         : (shift >= 0 ? value >> shift : value << -shift);
      }

      // Returns the first n least significant bits of value in reverse order if cond == true, otherwise returns value.
      static constexpr base_type reflect_if(bool cond, base_type value, int bits = base_type_bits, base_type acc = 0)
      {
        return cond ? (bits != 0 ? reflect_if(cond, value >> 1, bits - 1, (acc << 1) | (value & 1)) : acc) : value;
      }

      // Adjust poly and init for computation, according to direction and base_type_width.
      static constexpr base_type adjusted_param(base_type value)
      {
        return reflect_if(!msb_first, value << width_diff);
      }

      // Adjust input for computation, according to direction and base_type_width.
      template <typename InputType>
      static constexpr base_type adjusted_input(InputType value, int bits)
      {
        return shift_forward(reflect_if(refin, value, bits), msb_first ? base_type_bits - bits : 0);
      }

       // Shift the checksum and xors poly when appropriate.
      static constexpr base_type shift_checksum(base_type checksum, int bits)
      {
        return bits > 0 ? shift_checksum(shift_forward(checksum, 1) ^ (checksum & next_bit_mask ? poly : 0), bits - 1)
                        : checksum;
      }

      // Finalize the checksum
      static constexpr base_type finalize(base_type checksum)
      {
        return Algorithm::xorout ^ reflect_if(refout, shift_forward(checksum, msb_first ^ refout ? -width_diff : 0));
      }


      ///////////////////////////////////////////// Computation parameters ////////////////////////////////////////////

      static constexpr unsigned base_type_bits = sizeof(base_type) * CHAR_BIT;
      static constexpr unsigned width_diff = base_type_bits - Algorithm::width;

      // msb_first defines the direction of computation. It is selected to eliminate input reflection.
      static constexpr bool msb_first = !Algorithm::refin;

      // refin and refout are adjusted according to the direction of the computation.
      static constexpr bool refin  = !msb_first ^ Algorithm::refin;
      static constexpr bool refout = !msb_first ^ Algorithm::refout;

      // poly and init are adjusted according to the direction and bit-order of the computation.
      static constexpr base_type poly = adjusted_param(Algorithm::poly);
      static constexpr base_type init = adjusted_param(Algorithm::init);
      // xorout is not adjusted because it is applied after the final result is reflected/shifted.

      // And mask used to test next bit, most significant bit if msb_first, least significant bit otherwise.
      static constexpr base_type next_bit_mask = msb_first ? base_type(1) << (base_type_bits - 1) : 1;

    };



    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////  LOOKUP TABLE IMPLEMENTATION  //////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    // The following STL templates are needed for the implementation of the lookup table.
    // If they are not present, a backport is provided.
#if CRCXX_USE_STL_INDEX_SEQUENCE
    using ::std::index_sequence;
    using ::std::make_index_sequence;
#else
    template <size_t... Is> struct index_sequence { static constexpr size_t size = sizeof...(Is); };
    template <size_t N, size_t... Is> struct make_index_sequence: make_index_sequence<N - 1, N - 1, Is...> { };
    template <size_t... Is> struct make_index_sequence<0, Is...>: index_sequence<Is...> { };
#endif


    template <typename Algorithm, crc_method Method>
    struct crc_lookup_table
    {

      using base_type   = typename Algorithm::base_type;
      using primitives  = crc_primitives<Algorithm, Method>;

      constexpr static unsigned table_bits  = Method == USE_SMALL_TABLE ? 4 : 8;
      constexpr static unsigned table_size  = 1u << table_bits;
      constexpr static unsigned index_mask  = table_size - 1;
      constexpr static unsigned index_shift = primitives::msb_first ? primitives::base_type_bits - table_bits : 0;

      struct internal_array
      {
        base_type values[table_size];
      };

      template <size_t... Is>
      static constexpr internal_array make_lookup_table(index_sequence<Is...>)
      {
        return {{
          primitives::shift_checksum(
            primitives::adjusted_input(Is, table_bits),
            table_bits)...
        }};
      }

      static constexpr internal_array make_lookup_table()
      {
        return make_lookup_table(make_index_sequence<table_size>());
      }

      base_type operator[](base_type index) const
      {
        const static internal_array table = make_lookup_table();
        return table.values[(index >> index_shift) & index_mask];
      }

    };

    template <typename Algorithm>
    struct crc_lookup_table<Algorithm, BIT_BY_BIT>
    {

      using base_type = typename Algorithm::base_type;
      constexpr static unsigned table_bits = 0;

      base_type operator[](base_type index) const
      {
        return 0;
      }

    };

  } // namespace detail

} // namespace crcxx

#endif // CRCXX_CRCXX_HPP_
