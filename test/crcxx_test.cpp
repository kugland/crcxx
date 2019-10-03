#include <iostream>
#include "../src/crcxx.hpp"
#include "../src/crcxx_algorithms.hpp"

template <typename Algorithm, crcxx::crc_method Method>
struct check_crc_primitives
{

  using base_type = typename Algorithm::base_type;
  using primitives = crcxx::detail::crc_primitives<Algorithm, Method>;

  static constexpr base_type compute_check(base_type checksum = primitives::initial_value(), unsigned i = 0)
  {
    return i < 9
      ? compute_check(primitives::update_checksum(checksum, "123456789"[i], 8), i + 1)
      : primitives::finalize(checksum);
  }

};

template <typename Algorithm>
struct check_crc_primitives<Algorithm, crcxx::USE_TABLE>
{

  using base_type = typename Algorithm::base_type;
  using primitives = crcxx::detail::crc_primitives<Algorithm, crcxx::USE_TABLE>;

  static constexpr base_type table_func(uint_least8_t index)
  {
    return primitives::compute_lookup_table_item(index);
  }

  static constexpr base_type compute_check(base_type checksum = primitives::initial_value(), unsigned i = 0)
  {
    return i < 9
      ? compute_check(primitives::update_checksum_table(checksum, table_func, "123456789"[i]), i + 1)
      : primitives::finalize(checksum);
  }

};

using algo = crcxx::algorithms::CRC64_ECMA_182;
using algo2 = crcxx::algorithms::CRC32_BZIP2;
using check = check_crc_primitives<algo, crcxx::USE_TABLE>;
using check2 = check_crc_primitives<algo2, crcxx::USE_TABLE>;

int main()
{
  std::cout << std::hex << check::compute_check() << ' ' << algo::check << '\n';
  std::cout << std::hex << check2::compute_check() << ' ' << algo2::check << '\n';
}
