file(REMOVE_RECURSE
  "doc/doxygen-html"
  "doc/doxygen.log"
  "doc/talos_data.doxytag"
  "CMakeFiles/distdir"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/distdir.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
