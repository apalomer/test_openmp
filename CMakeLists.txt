cmake_minimum_required (VERSION 2.8)
project(test_openmp LANGUAGES CXX)

#OPENMP
find_package(OpenMP REQUIRED)
if(OPENMP_FOUND)
 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
 set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

# Library
add_library(example_lib SHARED example_lib.h example_lib.cpp)
target_compile_definitions(example_lib PRIVATE EXEMPLE_LIB_EXPORT)

# Executable
add_executable(test_openmp test_openmp.cpp)
target_link_libraries(test_openmp example_lib)