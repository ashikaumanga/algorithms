cmake_minimum_required(VERSION 3.16)
project(union VERSION 0.1.0)

include(CTest)
enable_testing()

set (SRC_FILES main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Percolation.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/QuickUnion.cpp) # your source files

#include_directories(union PRIVATE include/)
add_executable(union ${SRC_FILES})

target_include_directories(union PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include) # include directory for header files

target_compile_features(union PRIVATE cxx_std_17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
