cmake_minimum_required(VERSION 3.5)
project(Maze_Generator_Solvere)

set(CMAKE_POLICY_DEFAULT_CMP0135 NEW)

# Set SFML version
set(SFML_VERSION "2.6.1")

#include
include_directories(include)
include_directories(ressources)

# Fetch SFML
include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        "2.6.1"  # Stelle sicher, dass dies mit der SFML-Version übereinstimmt, die du verwenden möchtest
)
FetchContent_MakeAvailable(SFML)
set(CMAKE_CXX_STANDARD 17)

# Add your project files
file(GLOB SOURCES
    include/*.h
    src/*.cpp
)

add_executable(Maze_Generator_Solvere ${SOURCES})

# Link SFML libraries
target_link_libraries(Maze_Generator_Solvere sfml-graphics)