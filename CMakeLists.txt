# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.

cmake_minimum_required(VERSION 3.25)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

list(PREPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules")

project(Parquet
  VERSION 0.1.0
  DESCRIPTION "Parquet C++ Project"
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(GNUInstallDirs)

set(PARQUET_INSTALL_LIBDIR "${CMAKE_INSTALL_LIBDIR}")
set(PARQUET_INSTALL_BINDIR "${CMAKE_INSTALL_BINDIR}")
set(PARQUET_INSTALL_INCLUDEDIR "${CMAKE_INSTALL_INCLUDEDIR}")
set(PARQUET_INSTALL_CMAKEDIR "${CMAKE_INSTALL_LIBDIR}/cmake")
set(PARQUET_INSTALL_DOCDIR "${CMAKE_INSTALL_DOCDIR}")

include(ParquetBuildUtils)
include(ParquetSanitizer)

add_subdirectory(src)

install(FILES LICENSE DESTINATION ${PARQUET_INSTALL_DOCDIR})
