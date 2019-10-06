#include <stdlib.h>
#include <iostream>
#include <iomanip>

#include "../src/crcxx.hpp"
#include "../src/crcxx_algorithms.hpp"

template <typename Algorithm, crcxx::crc_method Method>
struct check_crc_primitives
{

  using base_type = typename Algorithm::base_type;
  using primitives = crcxx::detail::crc_primitives<Algorithm, Method>;

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

template <typename Algorithm>
struct check_crc_primitives<Algorithm, crcxx::BIT_BY_BIT>
{

  using base_type = typename Algorithm::base_type;
  using primitives = crcxx::detail::crc_primitives<Algorithm, crcxx::BIT_BY_BIT>;

  static constexpr base_type compute_check(base_type checksum = primitives::initial_value(), unsigned i = 0)
  {
    return i < 9
      ? compute_check(primitives::update_checksum(checksum, "123456789"[i], 8), i + 1)
      : primitives::finalize(checksum);
  }

};

using algo = crcxx::algorithms::CRC32_BZIP2;
using algo2 = crcxx::algorithms::CRC32_PKZIP;
using check = check_crc_primitives<algo, crcxx::USE_SMALL_TABLE>;
using check2 = check_crc_primitives<algo2, crcxx::USE_SMALL_TABLE>;

int main()
{
  std::cout << std::hex << check::compute_check() << ' ' << algo::check << '\n';
  std::cout << std::hex << check2::compute_check() << ' ' << algo2::check << '\n';
  /*using crc = crcxx::detail::crc_primitives<algo, crcxx::USE_TABLE>;
  for (int i = 0; i <= 16; i++) {
    std::cout << "0x" << std::hex << i << ": 0x" << std::hex << std::setfill('0') << std::setw(4) << crc::compute_lookup_table_item(i) << ",\n";
  }
  std::cout << "msb_first: " << crc::msb_first << '\n';*/
}

uint32_t table[256];

/*
31->9ef0
32->9f10
33->1fe0
34->9cd0
35->1c20
36->1dc0
37->9d30
38->9b50
39->1ba0
*/

static uint32_t table_func(uint_least8_t index)
{
  return table[index];
}

using crc = crcxx::detail::crc_primitives<algo2, crcxx::BIT_BY_BIT>;

uint32_t crc32(const char* ptr, size_t size)
{
  uint32_t checksum = crc::initial_value();

  for (int i = 0; i < size; i++) {
    checksum = crc::update_checksum(checksum, uint_least8_t(ptr[i]), 8);
  }

  return crc::finalize(checksum);
}
