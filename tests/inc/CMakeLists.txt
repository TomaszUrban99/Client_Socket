add_library(stackNode stackNode.hh)
add_library(stackList stackList.hh)

set_target_properties(stackNode PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(stackList PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(stackList stackNode)
