cmake_minimum_required (VERSION 2.6)
project (CARGO)

include_directories (.)
add_library (cargo cargo.c cargo.h)

# doc
find_package (Doxygen)

# Tests
add_executable (cargo_test
  cargo_test.c
  cargo.c
  cargo.h)

target_link_libraries (cargo_test cargo)
enable_testing()
add_test (NAME Boolean1 COMMAND cargo_test --boolean --expected=true --testflag)
add_test (NAME Boolean2 COMMAND cargo_test --boolean --expected=false --testflag=false)
add_test (NAME Boolean3 COMMAND cargo_test --boolean --expected=false)
add_test (NAME Integer  COMMAND cargo_test --integer --expected=2 --testflag=2)
add_test (NAME Float1   COMMAND cargo_test --float   --expected=2.0 --testflag=2.0)
add_test (NAME Float2   COMMAND cargo_test --float   --expected=2.0 --testflag=2)
add_test (NAME String1  COMMAND cargo_test --string  --expected="Hello world" --testflag="Hello world")
add_test (NAME String2  COMMAND cargo_test --string  --expected="Hello world" --testflag="Hello world overflow")
add_test (NAME String3  COMMAND cargo_test --string  --expected="Hello" --testflag=Hello long no quotes)




if (DOXYGEN_FOUND)

  configure_file (
    ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
    ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)

  add_custom_target (cargo_doc
    ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating API documentation with Doxygen" VERBATIM)

endif (DOXYGEN_FOUND)
