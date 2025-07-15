include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.17.0
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