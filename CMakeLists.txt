cmake_minimum_required(VERSION 3.14)
include(FetchContent)
project(gtest_test)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Also requires one of: libbfd (gnu binutils), libdwarf, libdw (elfutils)
FetchContent_Declare(backward
        GIT_REPOSITORY https://github.com/bombela/backward-cpp
        GIT_TAG v1.6)
FetchContent_MakeAvailable(backward)

# iterator library for zip and enumerate
string(COMPARE EQUAL ${CMAKE_CXX_COMPILER_ID} "Clang" IS_CLANG)
string(COMPARE LESS ${CMAKE_CXX_COMPILER_VERSION} "16" LESS_THAN_16)
# Clangs ranges implementation is broken until clang-16 => only limited support of c++20 view features
if (${IS_CLANG} AND ${LESS_THAN_16})
    add_compile_definitions(__STD_RANGES_DISABLED__)
endif ()

FetchContent_Declare(iterators
        GIT_REPOSITORY https://github.com/Timmifixedit/IteratorTools
        GIT_TAG master
)
FetchContent_MakeAvailable(iterators)
include_directories(${iterators_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -mtune=native -march=native" )
string(TOLOWER ${CMAKE_BUILD_TYPE} BUILD_TYPE)
if (BUILD_TYPE STREQUAL "debug")
    add_compile_definitions(__DEBUG_BUILD__)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer -g")
    message("Building for debug")
elseif (BUILD_TYPE STREQUAL "release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
    message("Building for release")
else ()
    message(SEND_ERROR "Unknown build type ${CMAKE_BUILD_TYPE}")
endif ()

set(SOURCES )
set(TARGETS )

message("generating following targets")
foreach (TARGET ${TARGETS})
    get_filename_component(NAME ${TARGET} NAME_WLE)
    message(\t${TARGET}\ ->\ target:\ ${NAME})
    if (BUILD_TYPE STREQUAL "debug")
        add_executable(${NAME} ${TARGET} ${SOURCES} ${BACKWARD_ENABLE})
        add_backward(${NAME})
    else()
        add_executable(${NAME} ${TARGET} ${SOURCES})
    endif()
endforeach ()

add_subdirectory(Tests)
