file(REMOVE_RECURSE
  "doc/doxygen-html"
  "doc/doxygen.log"
  "doc/talos_data.doxytag"
  "CMakeFiles/ContinuousMemCheck"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/ContinuousMemCheck.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
