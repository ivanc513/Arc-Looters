# tests/CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(AlgorithmTests)

# Download and configure GoogleTest
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

# Needed for MSVC
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Create one test executable including all test files
add_executable(test_all
    test_point.cpp
    test_ellipse.cpp
    test_path.cpp
)

# Link with your library and GoogleTest
target_link_libraries(test_all
    algorithm_lib     
    gtest
    gtest_main
)

enable_testing()
add_test(NAME AlgorithmAllTests COMMAND test_all)


