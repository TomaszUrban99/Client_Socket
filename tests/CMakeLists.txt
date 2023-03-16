cmake_minimum_required(VERSION 3.5)

project(stos LANGUAGES C CXX)

set(STOS_TABLICA_HEADLINES inc/stos_tablica.hh)
add_library(stos_tablica src/stos_tablica.cpp ${STOS_TABLICA_HEADLINES})
target_include_directories(stos_tablica PRIVATE inc/)

set(SOCKET_FUNCT inc/socketConnection.hh)
add_library(socket_server src/socketConnection.cpp ${SOCKET_FUNCT})
target_include_directories(socket_server PRIVATE inc/)

add_subdirectory(inc)

add_executable(stos src/main.cpp ${STOS_TABLICA_HEADLINES} ${SOCKET_FUNCT})
target_include_directories(stos PRIVATE inc/)
target_link_libraries(stos stos_tablica stackList socket_server)



# Include test functionalities
add_executable(test1 tests/test1.cpp) 
target_include_directories(test1 PRIVATE inc/)
target_link_libraries(test1 stos_tablica)

enable_testing()

# Check push functionality

add_test(
    NAME test1
    COMMAND $<TARGET_FILE:test1> ${TEST1_DATA_DIR}/test1_data.txt
)