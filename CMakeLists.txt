cmake_minimum_required(VERSION 3.0)
project(function_timer
    LANGUAGES CXX
    VERSION 0.1.0
    DESCRIPTION "Library to get the execution time of a given function. Written in C++ with hooks for C language as well."
)

add_library(function_timer
    src/main.cpp
)

target_include_directories(function_timer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

install(TARGETS function_timer DESTINATION lib)
install(FILES include/function_timer.h DESTINATION lib)

include(CTest)
enable_testing()

add_executable(test_cxx src/test.cpp)
target_link_libraries(test_cxx function_timer)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
