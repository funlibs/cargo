cmake_minimum_required (VERSION 2.6)
project (CARGO)

include_directories (.)
add_library (cargo cargo.c cargo.h)

add_executable(example example.c cargo.c cargo.h)
target_link_libraries(example cargo)
