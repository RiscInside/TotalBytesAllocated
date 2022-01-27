# Total bytes allocated

This repository contains code for shared library `total_bytes_allocated.so` that intercepts calls to `malloc` function and outputs total allocated memory in bytes after each allocation.

## Dependencies

The makefile depends on GCC being installed

## Building

`make build` builds a shared library `total_bytes_allocated.so`. `make test` (or simply `make`) runs `seq 1 5` program with `total_bytes_allocated.so` preloaded

## Acknowledgements

[This](https://fishi.devtail.io/weblog/2015/01/25/intercepting-hooking-function-calls-shared-c-libraries/) blogpost helped me to understand how to intercept C standard library calls.
