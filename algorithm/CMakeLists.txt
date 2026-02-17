cmake_minimum_required(VERSION 3.10)
project(algorithm VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Include all source files needed for the library
set(LIB_SOURCES
    src/core/Graph.cpp
    src/core/PathSolver.cpp 
    src/core/Point.cpp
    src/core/Path.cpp
    src/core/steps/EllipseInit.cpp
)

add_library(algorithm_lib ${LIB_SOURCES})
target_include_directories(algorithm_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Create executable target
add_executable(algorithm main.cpp)
target_link_libraries(algorithm algorithm_lib)

# Enable testing
enable_testing()
add_subdirectory(tests)
