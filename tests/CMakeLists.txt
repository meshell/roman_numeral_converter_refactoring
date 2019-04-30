# Roman Encoder test cmake file

# required minimum version of cmake
cmake_minimum_required(VERSION 3.6...3.14)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

include(clang)

find_package(Catch 2.1.2)

if(NOT RUNTIME_OUTPUT_DIRECTORY)
    set(RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
    file(MAKE_DIRECTORY
        ${RUNTIME_OUTPUT_DIRECTORY}
        )
endif(NOT RUNTIME_OUTPUT_DIRECTORY)

if(NOT TEST_RUNTIME_OUTPUT_DIRECTORY)
    set(TEST_RUNTIME_OUTPUT_DIRECTORY ${RUNTIME_OUTPUT_DIRECTORY}/tests)

    file(MAKE_DIRECTORY
        ${TEST_RUNTIME_OUTPUT_DIRECTORY}
        )
endif(NOT TEST_RUNTIME_OUTPUT_DIRECTORY)

######################################
# Create a single test executable.   #
######################################
add_executable(roman_converter_unittests
    main.cpp
    encoder_test.cpp
    decoder_test.cpp
    validator_test.cpp
    )
add_executable(roman_converter_tests::unit ALIAS roman_converter_unittests)

catch_add_tests($<TARGET_FILE:roman_converter_unittests> "" ${CMAKE_CURRENT_SOURCE_DIR}/encoder_test.cpp ${CMAKE_CURRENT_SOURCE_DIR}/decoder_test.cpp ${CMAKE_CURRENT_SOURCE_DIR}/validator_test.cpp)
# add_test(NAME encoder_unittest COMMAND $<TARGET_FILE:encoder_unittests>)


set_target_properties(roman_converter_unittests
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${TEST_RUNTIME_OUTPUT_DIRECTORY}"
    )

set_target_properties(roman_converter_unittests
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${TEST_RUNTIME_OUTPUT_DIRECTORY}"
    )

target_link_libraries(roman_converter_unittests
    PRIVATE
    Catch::catch
    roman::roman_lib
    "$<$<BOOL:${UNIX}>:-Xlinker '--no-as-needed'>"
    )

if(NOT MSVC)
    target_compile_options(roman_converter_unittests
        PRIVATE
        -pedantic
        -Wall
        -Wextra
        -Werror
        -Wno-c++98-compat
        $<$<BOOL:${CMAKE_COMPILER_IS_CLANGCXX}>:-Weverything>
        )
endif(NOT MSVC)


target_compile_options(roman_converter_unittests
    PRIVATE
    $<$<BOOL:${MSVC}>:/analyze;/W4>
    )

target_compile_definitions(roman_converter_unittests
    PRIVATE
    $<$<BOOL:${WIN32}>:WINVER=0x0A00;_WIN32_WINNT=0x0A00>
    )

if(CLANG_TIDY_EXE AND NOT CMAKE_COMPILER_IS_GNUCXX)
    set_target_properties(
        roman_converter_unittests
        PROPERTIES
        CXX_CLANG_TIDY "${CLANG_TIDY_PROPERTIES}"
    )
endif()


# Target: run tests
add_custom_target(run_unittests
    ALL # run the test always for target all
    roman_converter_tests::unit --order rand
    )

# set report and documentation output paths
if(NOT REPORT_DIR)
    set(REPORT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../reports CACHE PATH "Reports directory")
endif(NOT REPORT_DIR)
if(NOT COVERAGE_REPORT_DIR)
    set(COVERAGE_REPORT_DIR ${REPORT_DIR}/coverage CACHE PATH "Coverage reports output directory")
endif(NOT COVERAGE_REPORT_DIR)
if(NOT TESTS_REPORT_DIR)
    set(TESTS_REPORT_DIR ${REPORT_DIR}/tests CACHE PATH "Testresult output directory")
endif(NOT TESTS_REPORT_DIR)

# create report and documentation output directories
file(MAKE_DIRECTORY
    ${REPORT_DIR}
    ${COVERAGE_REPORT_DIR}
    ${TESTS_REPORT_DIR}
    )

# Target: run tests with junit output
add_custom_target(run_unittests_junit
    roman_converter_tests::unit -r junit;-o ${TESTS_REPORT_DIR}/unit-tests.xml
    )


# Coverage
include(CodeCoverage)

if(Coverage_FOUND AND CMAKE_BUILD_TYPE MATCHES Debug)
    if(COVERAGE_XML)
        setup_target_for_coverage_cobertura(
            NAME coverage_unittests_cobertura
            EXECUTABLE roman_converter_tests::unit
            OUTPUTNAME ${COVERAGE_REPORT_DIR}/unittests
        )

        if(NOT TARGET coverage_roman_converter)
            add_custom_target(coverage_roman_converter)
        endif(NOT TARGET coverage_roman_converter)

        add_dependencies(coverage_roman_converter coverage_unittests_cobertura)
    endif(COVERAGE_XML)

    if(COVERAGE_HTML)
        setup_target_for_coverage(
            NAME coverage_unittests
            EXECUTABLE roman_converter_tests::unit
            OUTPUTNAME ${COVERAGE_REPORT_DIR}/encoder_unittests
        )
        if(NOT TARGET coverage_roman_converter)
            add_custom_target(coverage_roman_converter)
        endif(NOT TARGET coverage_roman_converter)
        add_dependencies(coverage_roman_converter coverage_unittests)
    endif(COVERAGE_HTML)
endif(Coverage_FOUND AND CMAKE_BUILD_TYPE MATCHES Debug)
