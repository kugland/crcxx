#include <iostream>
#include "../src/crc_catalogue.hpp"
#include "../src/detail/crc_primitives.hpp"

using algo = crcxx::algorithms::CRC32_PKZIP;
using algo2 = crcxx::algorithms::CRC32_BZIP2;
using crc = crcxx::detail::crc_primitives<algo, crcxx::detail::BIT_BY_BIT>;
using crc2 = crcxx::detail::crc_primitives<algo2, crcxx::detail::BIT_BY_BIT>;
using type = typename algo::base_type;
using type2 = typename algo2::base_type;


int main()
{
  /*for (int i = 0; i < 256; i++) {
    std::cout << std::hex << crc::shift_checksum(crc::adjusted_input(i), 8) << std::endl;
    std::cout << std::hex << crc2::shift_checksum(crc2::adjusted_input(i), 8) << std::endl;
  }
  std::cout << std::hex << crc::poly << std::endl;
  std::cout << std::hex << crc::next_bit_mask << std::endl;
  std::cout << std::hex << crc2::poly << std::endl;
  std::cout << std::hex << crc2::next_bit_mask << std::endl;*/

  type checksum = crc::init;
  type2 checksum2 = crc2::init;

  for (int i = 0; i < 9; i++) {
    checksum = crc::shift_checksum(checksum ^ crc::adjusted_input(uint8_t("123456789"[i])), 8);
    checksum2 = crc2::shift_checksum(checksum2 ^ crc2::adjusted_input(uint8_t("123456789"[i])), 8);
  }

  std::cout << std::hex << crc::finalize(checksum) << ' ' << algo::check << '\n';
  std::cout << std::hex << crc2::finalize(checksum2) << ' ' << algo2::check << '\n';
  std::cout << crc2::forward << ' ' << crc2::refout << '\n';
  std::cout << std::hex << crc2::shift_forward(0x100000000, -32) << '\n';
}
