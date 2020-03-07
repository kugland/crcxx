#include <iostream>
#include <iomanip>

#include <vector>

#include "../src/crcxx.hpp"
#include "../src/crcxx_algorithms.hpp"

using algo = crcxx::algorithms::CRC32_PKZIP;

template <typename IteratorType>
uint32_t crc32(const IteratorType begin, const IteratorType end)
{
  crcxx::crc<algo, crcxx::USE_SMALL_TABLE> crc;

  crc.update(begin, end);

  return crc.finalize();
}

int main()
{
  std::vector<char> check{ 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39 };

  std::cout
    << std::hex
    << crc32(check.cbegin(), check.cend())
    << ' '
    << algo::check << '\n';
}
