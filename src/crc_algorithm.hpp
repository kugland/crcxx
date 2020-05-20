#ifndef CRCXX_CRC_ALGORITHM_HPP_
#define CRCXX_CRC_ALGORITHM_HPP_

#include <cstdint>

#include "detail/select_base_type.hpp"

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
    unsigned        Width,
    std::uintmax_t  Poly,
    uintmax_t       Init,
    bool            Refin,
    bool            Refout,
    std::uintmax_t  Xorout,
    std::uintmax_t  Check,
    std::uintmax_t  Residue
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

};

#endif // CRCXX_CRC_ALGORITHM_HPP_
