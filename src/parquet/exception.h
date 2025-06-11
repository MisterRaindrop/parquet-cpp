// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#pragma once

#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

#include "platform.h"

namespace parquet {

class PARQUET_EXPORT ParquetException : public std::exception {
 public:
  PARQUET_NORETURN static void EofException(const std::string& msg = "") {
    static std::string prefix = "Unexpected end of stream";
    if (msg.empty()) {
      throw ParquetException(prefix);
    }
    throw ParquetException(prefix, ": ", msg);
  }

  PARQUET_NORETURN static void NYI(const std::string& msg = "") {
    throw ParquetException("Not yet implemented: ", msg, ".");
  }

  explicit ParquetException(std::string msg) : msg_(std::move(msg)) {}

  explicit ParquetException(const char* msg, const std::exception&) : msg_(msg) {}

  ParquetException(const ParquetException&) = default;
  ParquetException& operator=(const ParquetException&) = default;
  ParquetException(ParquetException&&) = default;
  ParquetException& operator=(ParquetException&&) = default;

  ~ParquetException() noexcept override = default;

  const char* what() const noexcept override { return msg_.c_str(); }

 private:
  std::string msg_;
};

class PARQUET_EXPORT ParquetStatusException : public ParquetException {
 public:
  explicit ParquetStatusException(std::string msg) : ParquetException(msg) {}

  ~ParquetStatusException() noexcept override = default;
};

// This class exists for the purpose of detecting an invalid or corrupted file.
class PARQUET_EXPORT ParquetInvalidOrCorruptedFileException
    : public ParquetStatusException {
 public:
  explicit ParquetInvalidOrCorruptedFileException(std::string msg)
      : ParquetStatusException(msg) {}

  ~ParquetInvalidOrCorruptedFileException() noexcept override = default;
};

}  // namespace parquet