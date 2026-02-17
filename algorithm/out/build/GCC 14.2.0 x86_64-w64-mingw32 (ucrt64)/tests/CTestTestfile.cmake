# CMake generated Testfile for 
# Source directory: C:/Users/Ivan/Arc_Looters_Project/Arc-Looters/algorithm/tests
# Build directory: C:/Users/Ivan/Arc_Looters_Project/Arc-Looters/algorithm/out/build/GCC 14.2.0 x86_64-w64-mingw32 (ucrt64)/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(AlgorithmAllTests "C:/Users/Ivan/Arc_Looters_Project/Arc-Looters/algorithm/out/build/GCC 14.2.0 x86_64-w64-mingw32 (ucrt64)/tests/test_all.exe")
set_tests_properties(AlgorithmAllTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Ivan/Arc_Looters_Project/Arc-Looters/algorithm/tests/CMakeLists.txt;34;add_test;C:/Users/Ivan/Arc_Looters_Project/Arc-Looters/algorithm/tests/CMakeLists.txt;0;")
subdirs("../_deps/googletest-build")
