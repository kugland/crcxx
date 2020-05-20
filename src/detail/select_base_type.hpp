#ifndef CRCXX_DETAIL_SELECT_BASE_TYPE_HPP_
#define CRCXX_DETAIL_SELECT_BASE_TYPE_HPP_

#include <cstdint>

namespace crcxx {

  namespace detail {

    // Select base type according to Width.
    template <unsigned Width>
    struct select_base_type
    {
      static_assert(Width >= 1,  "Width must be >= 1");
      static_assert(Width <= 64, "Width must be <= 64");

      // Recurse until one of the defined specializations is found.
      using type = typename select_base_type<Width + 1>::type;
    };

    template <> struct select_base_type<8>  { using type = std::uint_least8_t;  };
    template <> struct select_base_type<16> { using type = std::uint_least16_t; };
    template <> struct select_base_type<32> { using type = std::uint_least32_t; };
    template <> struct select_base_type<64> { using type = std::uint_least64_t; };

  };

};

#endif // CRCXX_DETAIL_SELECT_BASE_TYPE_HPP_
