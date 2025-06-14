add_library(pattern_generator_lib STATIC
        PatternGenerator.cpp
)

target_include_directories(pattern_generator_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})