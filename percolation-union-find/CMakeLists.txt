cmake_minimum_required(VERSION 3.16)
project(union VERSION 0.1.0)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CTest)
enable_testing()

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()


set (SRC_FILES main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Percolation.cpp
 ${CMAKE_CURRENT_SOURCE_DIR}/src/QuickUnion.cpp
 ${CMAKE_CURRENT_SOURCE_DIR}/MyWidget.cpp) # your source files

add_executable(union ${SRC_FILES})
target_link_libraries(union PRIVATE Qt6::Widgets)
target_include_directories(union PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${FLTK_INCLUDE_DIR}) # include directory for header files

target_compile_features(union PRIVATE cxx_std_17)


include(CPack)
