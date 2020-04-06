cmake_minimum_required(VERSION 3.0)
project(function_timer
    LANGUAGES C CXX
    VERSION 0.1.0
    DESCRIPTION "Library to get the execution time of a given function. Written in C++ with hooks for C language as well."
)

add_library(function_timer
    src/main.cpp
    include/function_timer.h
)

target_include_directories(function_timer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

install(TARGETS function_timer DESTINATION lib)
install(FILES include/function_timer.h DESTINATION lib)

cmake_policy(SET CMP0054 NEW)
find_package(Doxygen OPTIONAL_COMPONENTS dot dia)
if(DOXYGEN_FOUND)
    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_GENERATE_MAN NO)

    doxygen_add_docs(
        docs
        ${PROJECT_SOURCE_DIR}
        COMMENT "Generate man pages"
    )
endif()

find_package(OpenMP)
# find_package(cunit)
# if (cunit_FOUND)
    include(CTest)
    enable_testing()

    add_executable(test_cxx src/test.cpp)
    target_link_libraries(test_cxx function_timer)
    if(OpenMP_CXX_FOUND)
        target_link_libraries(test_cxx OpenMP::OpenMP_CXX)
    endif()

    add_executable(test_c src/test.c)
    set_target_properties(test_c PROPERTIES LINKER_LANGUAGE C)
    target_link_libraries(test_c function_timer)
    if(OpenMP_C_FOUND)
        target_link_libraries(test_c OpenMP::OpenMP_C)
    endif()
# else(cunit_FOUND)
#     message(WARNING "CUnit library not found. Skipping tests.")
# endif(cunit_FOUND)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
