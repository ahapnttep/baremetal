cmake_minimum_required(VERSION 3.20)

project(
    baremetal
    VERSION 0.0.1
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Build the portable operating environment core.
add_library(
    baremetal_core
    STATIC

    src/shell/shell.cpp
)

target_include_directories(
    baremetal_core
    PUBLIC
    include
)

# Allow the core library to be linked into shared game libraries later.
set_target_properties(
    baremetal_core
    PROPERTIES
    POSITION_INDEPENDENT_CODE ON
)

# Build the standalone development frontend.
add_executable(
    baremetal_cli

    standalone/main.cpp
    src/io/console_terminal.cpp
)

target_link_libraries(
    baremetal_cli
    PRIVATE
    baremetal_core
)