#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "antlr4_shared" for configuration "Debug"
set_property(TARGET antlr4_shared APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(antlr4_shared PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib64/libantlr4-runtime.so.4.13.2"
  IMPORTED_SONAME_DEBUG "libantlr4-runtime.so.4.13.2"
  )

list(APPEND _cmake_import_check_targets antlr4_shared )
list(APPEND _cmake_import_check_files_for_antlr4_shared "${_IMPORT_PREFIX}/lib64/libantlr4-runtime.so.4.13.2" )

# Import target "antlr4_static" for configuration "Debug"
set_property(TARGET antlr4_static APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(antlr4_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib64/libantlr4-runtime.a"
  )

list(APPEND _cmake_import_check_targets antlr4_static )
list(APPEND _cmake_import_check_files_for_antlr4_static "${_IMPORT_PREFIX}/lib64/libantlr4-runtime.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
