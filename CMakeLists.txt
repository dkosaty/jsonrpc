cmake_minimum_required(VERSION 3.30)

project(JsonRpc)

option(BUILD_TESTING "Build tests" OFF)
option(BUILD_SHARED_LIBS "If ON is built as a shared library, otherwise as a static" ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    add_compile_options(-Wall -Wextra -Werror -Wpedantic -pedantic-errors)
endif()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

add_subdirectory(src)

enable_testing()
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
