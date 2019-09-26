Computation parameters
----------------------

### Method

| Method            | Description           | Characteristics                |
|-------------------|-----------------------|--------------------------------|
| Bit by bit        | No lookup table       | Smallest memory usage, slowest |
| Use small table   | 16-item lookup table  | Memory usage/speed compromise  |
| Use table         | 256-item lookup table | Biggest memory usage, fastest  |


### Direction

| Direction | Mask (for <code>uint32_t</code>) | Shift                   |
|-----------|----------------------------------|-------------------------|
| LSB first | 0x00000001                       | <code>&gt;&gt; 1</code> |
| MSB first | 0x80000000                       | <code>&lt;&lt; 1</code> |


Rules for selecting direction
-----------------------------

When using bit by bit computation, we can eliminate the reflection of the input byte by changing
the direction of the computation.

* If <code>Refin == true</code>, use <code>direction = LSB_FIRST</code>.

* If <code>Refin == false</code>, use <code>direction = MSB_FIRST</code>.

When using lookup tables, we can further eliminate the reflection of the output code, since the
input can be pre-reflected when needed.

* If <code>Refout == true</code>, use <code>direction = LSB_FIRST</code>.

  - When using a small lookup table, first shift the least significant nibble in, then the most
    significant nibble. 

* If <code>Refout == false</code>, use <code>direction = MSB_FIRST</code>.

  - When using a small lookup table, first shift the most significant nibble in, then the least
    significant nibble.


Lookup tables
-------------
Since CRC++ is primarily intended for MCUs with very little speed and RAM, lookup table generation
is always done at compile time, by using constant expression constructs.

When compiling for AVR MCUs, lookup tables are stored in instruction memory (<code>PROGMEM</code>).
