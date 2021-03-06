// Copyright (c) 2020 André Kugland
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT


#ifndef CRCXX_CRCXX_HPP_
#define CRCXX_CRCXX_HPP_

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////// CONFIGURATION MACROS ////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// AVR library does not include <climits>, <cstdint> etc variants, but only <limits.h>, <stdint.h> etc.
#ifndef CRCXX_USE_STD_CPP_HEADERS
#if !defined(__AVR__)
#define CRCXX_USE_STD_CPP_HEADERS 1
#else
#define CRCXX_USE_STD_CPP_HEADERS 0
#endif
#endif

#if CRCXX_USE_STD_CPP_HEADERS
#include <climits>
#include <cstdint>
#include <cstdlib>
#define CRCXX_STD_NS ::std
#else
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#define CRCXX_STD_NS
#endif


#ifdef __AVR__
#include <avr/pgmspace.h>
#define CRCXX_LOOKUP_TABLE_ATTR PROGMEM
#else
#define CRCXX_LOOKUP_TABLE_ATTR
#endif


#ifndef CRCXX_USE_ARDUINO_STRING
#ifdef ARDUINO
#define CRCXX_USE_ARDUINO_STRING 1
#else
#define CRCXX_USE_ARDUINO_STRING 0
#endif
#endif

#if CRCXX_USE_ARDUINO_TYPES
#include <Arduino.h>
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

} // namespace detail



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
    unsigned                Width,
    CRCXX_STD_NS::uintmax_t Poly,
    CRCXX_STD_NS::uintmax_t Init,
    bool                    Refin,
    bool                    Refout,
    CRCXX_STD_NS::uintmax_t Xorout,
    CRCXX_STD_NS::uintmax_t Check,
    CRCXX_STD_NS::uintmax_t Residue
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
      int bits = CHAR_BIT;
      checksum ^= primitives::adjusted_input(data, bits);
      if (Method != BIT_BY_BIT) {
        while (bits >= lookup_table::table_bits) {
          const static lookup_table table;
          checksum = primitives::shift_forward(checksum, lookup_table::table_bits) ^ table[checksum];
          bits -= lookup_table::table_bits;
        }
      }
      checksum = primitives::shift_checksum(checksum, bits);
    }

    template<class InputIt>
    void update(InputIt first, InputIt last)
    {
      static_assert(sizeof(*first) == 1, "Type must be char");

      for (; first != last; ++first)
        update(*first);
    }

    base_type finalize() const
    {
      return primitives::finalize(checksum);
    }

    void reset()
    {
      checksum = primitives::init;
    }

#if CRCXX_USE_ARDUINO_STRING
    void update(const String& str)
    {
      update(str.length(), str.c_str());
    }
#endif

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

    template <> struct select_base_type<8>  { using type = CRCXX_STD_NS::uint_least8_t;  };
    template <> struct select_base_type<16> { using type = CRCXX_STD_NS::uint_least16_t; };
    template <> struct select_base_type<32> { using type = CRCXX_STD_NS::uint_least32_t; };
    template <> struct select_base_type<64> { using type = CRCXX_STD_NS::uint_least64_t; };



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
      template <bool Cond>
      static constexpr base_type reflect_if(base_type value, int bits = base_type_bits, base_type acc = 0)
      {
        return Cond ? (bits != 0 ? reflect_if<Cond>(value >> 1, bits - 1, (acc << 1) | (value & 1)) : acc) : value;
      }

      // Adjust poly and init for computation, according to direction and base_type_width.
      static constexpr base_type adjusted_param(base_type value)
      {
        return reflect_if<!msb_first>(value << width_diff);
      }

      // Adjust input for computation, according to direction and base_type_width.
      template <typename InputType>
      static constexpr base_type adjusted_input(InputType value, int bits)
      {
        return shift_forward(reflect_if<refin>(value, bits), msb_first ? base_type_bits - bits : 0);
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
        return Algorithm::xorout ^ reflect_if<refout>(shift_forward(checksum, msb_first ^ refout ? -width_diff : 0));
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
    template <CRCXX_STD_NS::size_t... Is>
    struct index_sequence { static constexpr CRCXX_STD_NS::size_t size = sizeof...(Is); };

    template <CRCXX_STD_NS::size_t N, CRCXX_STD_NS::size_t... Is>
    struct make_index_sequence: make_index_sequence<N - 1, N - 1, Is...> { };

    template <CRCXX_STD_NS::size_t... Is>
    struct make_index_sequence<0, Is...>: index_sequence<Is...> { };


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

      template <CRCXX_STD_NS::size_t... Is>
      static constexpr internal_array make_lookup_table(index_sequence<Is...>)
      {
        return {{ primitives::shift_checksum(primitives::adjusted_input(Is, table_bits), table_bits)... }};
      }

      static constexpr internal_array make_lookup_table()
      {
        return make_lookup_table(make_index_sequence<table_size>());
      }

      base_type operator[](base_type index) const
      {
        const static internal_array table CRCXX_LOOKUP_TABLE_ATTR = make_lookup_table();
        auto value_ptr = table.values + ((index >> index_shift) & index_mask);
#if __AVR__
        switch (sizeof(base_type)) {
          case 1: return pgm_read_byte(value_ptr);
          case 2: return pgm_read_word(value_ptr);
          case 4: return pgm_read_dword(value_ptr);
          case 8: { base_type result;
                    memcpy_P(&result, value_ptr, 8);
                    return result; }
        }
#else
        return *value_ptr;
#endif
      }

    };

    template <typename Algorithm>
    struct crc_lookup_table<Algorithm, BIT_BY_BIT>
    {

      using base_type = typename Algorithm::base_type;
      constexpr static unsigned table_bits = 1;

      base_type operator[](base_type index) const { return 0; }

    };

  } // namespace detail

} // namespace crcxx

#include "crcxx_algorithms.hpp"

#endif // CRCXX_CRCXX_HPP_
