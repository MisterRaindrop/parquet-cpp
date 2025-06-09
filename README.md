# parquet-cpp
pure c++ library for reading/writing parquet file



## High-Performance, C++ Library for Reading & Writing Parquet Files

This library provides a pure C++20 implementation for seamless reading and writing of Apache Parquet files. Designed for mission-critical applications, it eliminates Java/Python dependencies while delivering industry-leading throughput and memory efficiency.

## Core Features
 - 📊 Native C++ Implementation: Zero external dependencies (no Java VM, Arrow, or Boost required)
 - 🔧 Full Format Support:
    - All Parquet data types (INT96, BYTE_ARRAY, FIXED_LEN_BYTE_ARRAY, etc.)
    - Compressions: Snappy, Zstandard, GZIP, LZ4, Brotli
    - Encodings: PLAIN, RLE, DELTA_BINARY_PACKED, BYTE_STREAM_SPLIT
 - 📦 Simple build and used

## Requirements

- CMake 3.25 or higher
- C++20 compliant compiler

## Build

### Simple Build, Run Test and Install
```
cd parquet-cpp
cmake -S . -B build -DCMAKE_INSTALL_PREFIX=/path/to/install
make install
```

## Contribute
parquet-cpp is open to people who want to contribute to it. Here are some ways to get involved:

- Submit Issues for bug report or feature requests.

## License
Licensed under the Apache License, Version 2.0
