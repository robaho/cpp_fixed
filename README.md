**Summary**

A fixed place numeric library designed for performance. Based on the Go version [fixed](https://github.com/robaho/fixed)

The library is safe for concurrent use. 

It is ideally suited for high performance trading financial systems. All common math operations are completed with 0 allocations.

**Building**

You need the [Boost Unit Testing Framework](https://www.boost.org/doc/libs/1_87_0/libs/test/doc/html/index.html) installed.

It builds using `make` by default with CLang. There is `Makefile.gcc` for using GCC instead.

**Design Goals**

Financial systems, especially trading systems need efficient, and stable decimal arithmetic.

This was designed as a drop-in replacement for double, but allows conversion to/from double for advanced math operations.

Primarily developed for use in [cpp-trader](https://github.com/robaho/cpp-trader).
