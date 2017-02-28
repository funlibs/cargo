cmake_minimum_required (VERSION 2.6)
project (Cargo)


set(CARGO_MAJOR_VERSION 0)
set(CARGO_MINOR_VERSION 1)
set(CARGO_PATCH_VERSION 0)
set(CARGO_VERSION
    ${CARGO_MAJOR_VERSION}.${CARGO_MINOR_VERSION}.${CARGO_PATCH_VERSION})

# library
include_directories (.)

# test
add_executable(cargo_test cargo_test cargo.h)
enable_testing()
add_test (NAME TBool     COMMAND cargo_test --type=boolean --val=TRUE)
add_test (NAME TEmpty    COMMAND cargo_test --type=empty   --val=)
add_test (NAME TValue    COMMAND cargo_test --type=value   --val=innerValue)
add_test (NAME TMissing  COMMAND cargo_test --type=missing)
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_test (NAME MemCheck  COMMAND valgrind --error-exitcode=1 --tool=memcheck --leak-check=full --track-origins=yes -v ./cargo_example)
endif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")


set (CARGO_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR} CACHE STRING "cargo includes")

# example
add_executable(cargo_example cargo_example.c cargo.h)
