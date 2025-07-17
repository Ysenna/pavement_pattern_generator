add_library(pattern_generator_lib STATIC
        CLIParser.cpp
        PatternGenerator.cpp
)

target_include_directories(pattern_generator_lib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(pattern_generator_lib PRIVATE
        CLI11::CLI11)