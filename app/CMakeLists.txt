include(FetchContent)
FetchContent_Declare(
        cli11
        GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
        GIT_TAG v2.5.0
)

FetchContent_MakeAvailable(cli11)

add_executable(pavement_pattern_generator main.cpp)

target_link_libraries(pavement_pattern_generator PRIVATE
        pattern_generator_lib
)