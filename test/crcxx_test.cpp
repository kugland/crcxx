#include <iostream>
#include "../src/crc_catalogue.hpp"
#include "../src/detail/crc_primitives.hpp"

using algo = crcxx::algorithms::CRC32_PKZIP;
using algo2 = crcxx::algorithms::CRC32_BZIP2;
using crc = crcxx::detail::crc_primitives<algo, crcxx::detail::BIT_BY_BIT>;
using crc2 = crcxx::detail::crc_primitives<algo2, crcxx::detail::BIT_BY_BIT>;

int main()
{
  for (int i = 0; i < 256; i++) {
    std::cout << std::hex << crc::shift_checksum(crc::adjusted_input(i), 8) << std::endl;
    std::cout << std::hex << crc2::shift_checksum(crc2::adjusted_input(i), 8) << std::endl;
  }
  std::cout << std::hex << crc::poly << std::endl;
  std::cout << std::hex << crc::next_bit_mask << std::endl;
  std::cout << std::hex << crc2::poly << std::endl;
  std::cout << std::hex << crc2::next_bit_mask << std::endl;
}
