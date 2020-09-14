#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "talos_data::talos_data" for configuration ""
set_property(TARGET talos_data::talos_data APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(talos_data::talos_data PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libtalos_data.so.1.2.2"
  IMPORTED_SONAME_NOCONFIG "libtalos_data.so.1.2.2"
  )

list(APPEND _IMPORT_CHECK_TARGETS talos_data::talos_data )
list(APPEND _IMPORT_CHECK_FILES_FOR_talos_data::talos_data "${_IMPORT_PREFIX}/lib/libtalos_data.so.1.2.2" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
