cmake_minimum_required(VERSION 4.3.3)

project(
  Kaush
  VERSION 1.0
  LANGUAGES C
)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
  ${CMAKE_SOURCE_DIR}/bin
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
  ${CMAKE_SOURCE_DIR}/bin
)

add_subdirectory(engine)
add_subdirectory(testbed)
