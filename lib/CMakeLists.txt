# Roman Encoder cmake file

# required minimum version of cmake
cmake_minimum_required(VERSION 3.6...3.14)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# Set a project name in case only this library is built
if(NOT PROJECT_NAME)
    project(roman_converter_lib
        VERSION 0.0.1
        DESCRIPTION "Convert to and from roman number"
        LANGUAGES CXX)
endif(NOT PROJECT_NAME)

# set the path to the additional cmake modules
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../cmake)

#include(clang)

# Build library
add_library(roman_converter_lib STATIC
    encode.cpp
    validator.cpp
    )

# define alias
add_library(roman::roman_lib ALIAS roman_converter_lib)

target_include_directories(roman_converter_lib
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
    $<INSTALL_INTERFACE:../include>
    )

if(NOT MSVC)
    target_compile_options(roman_converter_lib
        PRIVATE
        -pedantic
        -Wall
        -Wextra
        -Werror
        -Wno-c++98-compat
        $<$<BOOL:${CMAKE_COMPILER_IS_CLANGCXX}>:-Weverything>
        )
endif(NOT MSVC)

target_compile_options(roman_converter_lib
    PRIVATE
    $<$<BOOL:${MSVC}>:/analyze>
    )

if(CLANG_TIDY_EXE AND NOT CMAKE_COMPILER_IS_GNUCXX)
    set_target_properties(
        roman_converter_lib
        PROPERTIES
        CXX_CLANG_TIDY "${CLANG_TIDY_PROPERTIES}"
    )
endif()


target_compile_features(roman_converter_lib
    PUBLIC
    cxx_std_14
    cxx_auto_type
    )

# Coverage instrumentation
include(CodeCoverage)
if(Coverage_FOUND)
    enable_coverage(roman_converter_lib)
endif(Coverage_FOUND)


#Install targets
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/../..)

install(TARGETS roman_converter_lib
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    )

install(DIRECTORY include/roman_encoder DESTINATION include)

install(TARGETS roman_converter_lib EXPORT converter_lib DESTINATION lib)
install(EXPORT converter_lib NAMESPACE roman:: DESTINATION lib)
