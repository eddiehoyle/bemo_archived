cmake_minimum_required(VERSION 3.10)

project(bemo)

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 11)

set(TARGET_DIR ${CMAKE_SOURCE_DIR}/build)
set(PYTHON_DIST_DIR ${TARGET_DIR})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${TARGET_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${TARGET_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TARGET_DIR})

set(PYBIND11 ${CMAKE_SOURCE_DIR}/ext/pybind11)
set(PYTHON_INCLUDE_DIR /usr/include/python2.7)
set(PYBIND11_PYTHON_VERSION 2.7 CACHE STRING "")

add_subdirectory(ext/pybind11)
add_subdirectory(cpp)