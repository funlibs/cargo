cmake_minimum_required (VERSION 2.6)
project (CARGO)


# library
include_directories (.)
add_library (cargo cargo.c cargo.h)


# test
add_executable(cargo_test cargo_test cargo.c cargo.h)
enable_testing()
add_test (NAME TBool     COMMAND cargo_test --type=boolean --val=TRUE)
add_test (NAME TEmpty    COMMAND cargo_test --type=empty   --val=)
add_test (NAME TValue    COMMAND cargo_test --type=value   --val=innerValue)
add_test (NAME TMissing  COMMAND cargo_test --type=missing)


# example
add_executable(cargo_example cargo_example.c cargo.c cargo.h)
target_link_libraries(cargo_example cargo)


# doc
find_package (Doxygen)
if (DOXYGEN_FOUND)

  configure_file (
    ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
    ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)

  add_custom_target (cargo_doc
    ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating API documentation with Doxygen" VERBATIM)

endif (DOXYGEN_FOUND)
