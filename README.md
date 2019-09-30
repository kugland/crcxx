# crcxx

crcxx is a header-only library for computing CRC checksums written in modern C++.


## Features

- Supports any CRC algorithm with width between 1 bit and 64 bits.
- Includes algorithm catalogue extracted from Greg Cook’s catalogue.
- Usable in constant-expression contexts.
- Three computation methods:
    + Bit by bit (```crcxx::BIT_BY_BIT```): no lookup table — slowest.
    + Normal table (```crcxx::USE_TABLE```): 16-item lookup table.
    + Small table (```crcxx::USE_SMALL_TABLE```): 256-item lookup table — fastest.
- Compile-time generation of lookup tables.
- Lookup tables stored in program memory in platforms that support it.
- Static testing of algorithms.


## Usage

### Usage as an updatable checksum object

```c++
crcxx::crc<crcxx::algorithms::CRC32_POSIX> cksum;

void on_recv(const uint8_t* ptr, std::size_t size)
{ cksum.update(ptr, size); }

uint32_t get_cksum()
{ return cksum.finalize(); }
```

### Usage in constant expression context

```c++
using crc32_pkzip = crcxx::crc<crcxx::algorithms::CRC32_PKZIP>;

constexpr uint8_t array_of_bytes = { 0, 1, 2, 3, 4, 5, 7, 8, 9 };

constexpr uint32_t check = crc32_pkzip::crc(array_of_bytes);

// Use NULL_TERMINATED flag to ignore the last NUL in a null-terminated string/array.
constexpr uint32_t hello_check = crc32_pkzip::crc("123456789", crcxx::NULL_TERMINATED);
```

## References

[CRC RevEng (by Greg Cook) catalogue of CRC algorithms](http://reveng.sourceforge.net/crc-catalogue/all.htm)
