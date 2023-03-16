# CMake generated Testfile for 
# Source directory: /home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos
# Build directory: /home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test1 "/home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos/build/test1" "/test1_data.txt")
set_tests_properties(test1 PROPERTIES  _BACKTRACE_TRIPLES "/home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos/CMakeLists.txt;30;add_test;/home/tomasz/Documents/Studia/PAMSI/Projekt1/Stos/CMakeLists.txt;0;")
subdirs("inc")
