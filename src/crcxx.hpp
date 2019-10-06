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



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////// CONFIGURATION MACROS ////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////// FORWARD DECLARATIONS ////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


namespace crcxx {

  namespace detail {

    template <unsigned Width> struct select_base_type;

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
    using base_type = typename ::crcxx::detail::select_base_type<Width>::type;

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

  enum crc_method {
    BIT_BY_BIT,
    USE_TABLE,
    USE_SMALL_TABLE
  };


  namespace detail {

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////// crcxx::detail::select_base_type /////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    // Select base type according to Width.
    template <unsigned Width>
    struct select_base_type
    {
      static_assert(Width >= 1,  "Width must be >= 1");
      static_assert(Width <= 64, "Width must be <= 64");

      // Recurse until Width equals 8, 16, 32 or 64.
      using type = typename select_base_type<Width + 1>::type;
    };

    template <> struct select_base_type<8>  { using type = uint_least8_t;  };
    template <> struct select_base_type<16> { using type = uint_least16_t; };
    template <> struct select_base_type<32> { using type = uint_least32_t; };
    template <> struct select_base_type<64> { using type = uint_least64_t; };



    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////// crcxx::detail::crc_primitives //////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    template <typename Algorithm, ::crcxx::crc_method Method>
    class crc_primitives
    {

      using base_type = typename Algorithm::base_type;


      ///////////////////////////////////////// Primitives for CRC computation ////////////////////////////////////////

    public:

      // Initial value
      static constexpr base_type initial_value()
      {
        return init;
      }

      // Updates the checksum with new data bit by bit.
      template <typename InputType>
      static constexpr base_type update_checksum(base_type checksum, InputType input, unsigned bits)
      {
        return shift_checksum(checksum ^ adjusted_input(input, bits), bits);
      }

      // Updates the checksum with new data using a table.
      template <typename TableType>
      static constexpr base_type update_checksum_table(base_type checksum, TableType table, uint_least8_t input,
                                                       unsigned index = Method == USE_SMALL_TABLE ? 2 : 1)
      {
        return index == 0
          ? checksum
          : update_checksum_table(
              shift_forward(checksum, table_bits) ^ table(adjusted_table_index(checksum, input)),
              table,
              shift_forward(input, table_bits),
              index - 1
            );
      }

      // Computes an item of the lookup table.
      static constexpr base_type compute_lookup_table_item(base_type index)
      {
        return shift_checksum(adjusted_input(index, table_bits), table_bits);
      }

      // Finalize the checksum
      static constexpr base_type finalize(base_type checksum)
      {
        return Algorithm::xorout ^ reflect_if(refout, shift_forward(checksum, msb_first ^ refout ? -width_diff : 0));
      }


      ///////////////////////////////////////////////// Helper methods ////////////////////////////////////////////////

    private:

      // Shift a value forward, i.e. left when MSB first, right when LSB first.
      static constexpr base_type shift_forward(base_type value, int shift)
      {
        return msb_first ? (shift >= 0 ? value << shift : value >> -shift)
                         : (shift >= 0 ? value >> shift : value << -shift);
      }

      // Returns the first n least significant bits of value in reverse order if cond == true, otherwise returns value.
      static constexpr base_type reflect_if(bool cond, base_type value, uint_fast8_t bits = base_type_bits,
                                            base_type result = 0)
      {
        return cond ? (bits != 0
                        ? reflect_if(cond, value >> 1, bits - 1, (result << 1) | (value & 1))
                        : result)
                    : value;
      }

      // Adjust poly and init for computation, according to direction and base_type_width.
      static constexpr base_type adjusted_param(base_type value)
      {
        return reflect_if(!msb_first, value << width_diff);
      }

      // Adjust input for computation, according to direction and base_type_width.
      template <typename InputType>
      static constexpr base_type adjusted_input(InputType value, uint_fast8_t bits)
      {
        return shift_forward(reflect_if(refin, value, bits), msb_first ? base_type_bits - bits : 0);
      }

      // Adjust input for computation, according to direction and base_type_width.
      static constexpr base_type adjusted_table_index(base_type checksum, uint_least8_t input)
      {
        return (shift_forward(checksum, msb_first ? -base_type_bits + table_bits : 0) ^ input) & table_mask;
      }

      // Shift the checksum and xors poly when appropriate.
      static constexpr base_type shift_checksum(base_type checksum, uint_fast8_t bits)
      {
        return bits > 0 ? shift_checksum(shift_forward(checksum, 1) ^ (checksum & next_bit_mask ? poly : 0), bits - 1)
                        : checksum;
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

      static constexpr unsigned table_bits = Method == USE_SMALL_TABLE ?  4 :   8;
      static constexpr uint8_t  table_mask = Method == USE_SMALL_TABLE ? 15 : 255;

    };

  } // namespace detail

} // namespace crcxx

#endif // CRCXX_CRCXX_HPP_
