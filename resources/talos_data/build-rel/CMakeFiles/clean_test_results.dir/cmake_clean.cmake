file(REMOVE_RECURSE
  "doc/doxygen-html"
  "doc/doxygen.log"
  "doc/talos_data.doxytag"
  "CMakeFiles/clean_test_results"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/clean_test_results.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
