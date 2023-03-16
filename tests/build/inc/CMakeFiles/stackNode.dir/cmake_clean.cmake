file(REMOVE_RECURSE
  "libstackNode.a"
  "libstackNode.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/stackNode.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
