file(REMOVE_RECURSE
  "libsocketsServer.a"
  "libsocketsServer.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/socketsServer.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
