Computation parameters
----------------------

### Method

|            Method            |      Description      |        Characteristics         |
|------------------------------|-----------------------|--------------------------------|
| ```crcxx::BIT_BY_BIT```      | No lookup table       | Smallest memory usage, slowest |
| ```crcxx::USE_SMALL_TABLE``` | 16-item lookup table  | Memory usage/speed compromise  |
| ```crcxx::USE_TABLE```       | 256-item lookup table | Greatest memory usage, fastest |


### Direction

| Direction | Mask (for ```uint32_t```) |      Shift       |
|-----------|---------------------------|------------------|
| LSB first | ```0x00000001```          | ```&gt;&gt; 1``` |
| MSB first | ```0x80000000```          | ```&lt;&lt; 1``` |


Rules for selecting direction
-----------------------------

When using bit by bit computation, we can eliminate the reflection of the input byte by reversing the direction of the
computation.

* If <code>Refin == true</code>, use <code>msb_first = false</code>.

* If <code>Refin == false</code>, use <code>msb_first = true</code>.

When using lookup tables, we can further eliminate the reflection of the output code, since the input bytes can be
adjusted at compile time.

* If <code>Refout == true</code>, use <code>msb_first = false</code>.

  - When using a small lookup table, first shift the least significant nibble in, then the most
    significant nibble. 

* If <code>Refout == false</code>, use <code>msb_first = true</code>.

  - When using a small lookup table, first shift the most significant nibble in, then the least
    significant nibble.


Lookup tables
-------------

Lookup table generation is always done at compile time, by using constant expression constructs.

When compiling for AVR MCUs, lookup tables are stored in instruction memory (<code>PROGMEM</code>). Similar constructs
can be used in other modified Harvard architectures which allow for the storage of data in instruction memory. Pull
requests are welcome.
