cmake_minimum_required(VERSION 3.5)

project(stos LANGUAGES C CXX)

set(STOS_TABLICA_HEADLINES inc/stos_tablica.hh)
add_library(stos_tablica src/stos_tablica.cpp ${STOS_TABLICA_HEADLINES})
target_include_directories(stos_tablica PRIVATE inc/)

set(SOCKET_FUNCT_CLIENT inc/socketConnection.hh)
add_library(socket_client src/socketConnection.cpp ${SOCKET_FUNCT})
target_include_directories(socket_client PRIVATE inc/)

set(FILE_TRANSFER inc/fileTransferClient.hh ${SOCKET_FUNCT_CLIENT} ${STOS_TABLICA_HEADLINES} ${STACK_HEADLINES})
add_library(file_transfer src/fileTransferClient.cpp ${FILE_TRANSFER})
target_include_directories(file_transfer PRIVATE inc/)

#set(STACK_HEADLINES inc/stackList.hh inc/stackNode.hh)
#add_library(stack src/stackList.cpp ${STACK_HEADLINES})
#target_include_directories(stack PRIVATE inc/)

add_subdirectory(inc)

add_executable(stos src/main.cpp ${STOS_TABLICA_HEADLINES} ${SOCKET_FUNCT_CLIENT} ${FILE_TRANSFER})
target_include_directories(stos PRIVATE inc/)
target_link_libraries(stos stos_tablica stackList socket_client file_transfer)


# Include test functionalities
add_executable(test1 tests/test1.cpp ${STOS_TABLICA_HEADLINES} ${SOCKET_FUNCT_CLIENT} ${FILE_TRANSFER}) 
target_include_directories(test1 PRIVATE inc/)
target_link_libraries(test1 stos_tablica stackList socket_client file_transfer)

enable_testing()

# Check push functionality

add_test(
    NAME test1
    COMMAND $<TARGET_FILE:test1> ${TEST1_DATA_DIR}/test1_data.txt
)