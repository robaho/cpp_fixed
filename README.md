**Summary**

A fixed place numeric library designed for performance. Based on the Go version [fixed](https://github.com/robaho/fixed)

The library is safe for concurrent use. 

It is ideally suited for high performance trading financial systems. All common math operations are completed with 0 allocations.

**Design Goals**

Financial systems, especially trading systems need efficient, and stable decimal arithmetic.

THis was designed as a drop-in replacement for double, but allow conversion to/from double for non-basic math operations.

Primarily developed for use in [cpp_orderbook](https://github.com/robaho/cpp_orderbook).
