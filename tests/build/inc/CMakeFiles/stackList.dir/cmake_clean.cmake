file(REMOVE_RECURSE
  "libstackList.a"
  "libstackList.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/stackList.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
