include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(pattern_generator_tests
        PatternGeneratorTests.cpp
)

target_link_libraries(pattern_generator_tests
        gtest_main
        gmock
        pattern_generator_lib
)

include(GoogleTest)
gtest_discover_tests(pattern_generator_tests)