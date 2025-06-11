# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.

set(PARQUET_INCLUDES "$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/src>"
                     "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>")
set(PARQUET_SOURCES
    exception.cc
    platform.cc)

set(PARQUET_STATIC_BUILD_INTERFACE_LIBS)
set(PARQUET_SHARED_BUILD_INTERFACE_LIBS)
set(PARQUET_STATIC_INSTALL_INTERFACE_LIBS)
set(PARQUET_SHARED_INSTALL_INTERFACE_LIBS)

add_parquet_lib(parquet
                SOURCES
                ${PARQUET_SOURCES}
                EXTRA_INCLUDES
                ${PARQUET_INCLUDES}
                SHARED_LINK_LIBS
                ${PARQUET_SHARED_BUILD_INTERFACE_LIBS}
                STATIC_LINK_LIBS
                ${PARQUET_STATIC_BUILD_INTERFACE_LIBS}
                STATIC_INSTALL_INTERFACE_LIBS
                ${PARQUET_STATIC_INSTALL_INTERFACE_LIBS}
                SHARED_INSTALL_INTERFACE_LIBS
                ${PARQUET_SHARED_INSTALL_INTERFACE_LIBS})

parquet_install_all_headers(parquet)



#parquet_install_cmake_package(Parquet parquet_targets)