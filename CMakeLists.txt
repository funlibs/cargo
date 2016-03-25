cmake_minimum_required (VERSION 2.6)
project (CARGO)

include_directories (.)
add_library (cargo cargo.c cargo.h)

add_executable(cargo_example cargo_example.c cargo.c cargo.h)
target_link_libraries(cargo_example cargo)

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
