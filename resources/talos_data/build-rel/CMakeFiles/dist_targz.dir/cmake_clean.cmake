file(REMOVE_RECURSE
  "doc/doxygen-html"
  "doc/doxygen.log"
  "doc/talos_data.doxytag"
  "CMakeFiles/dist_targz"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/dist_targz.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
