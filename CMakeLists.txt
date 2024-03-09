cmake_minimum_required(VERSION 3.5)
project(Maze_Generator_Solvere)

# Set SFML version
set(SFML_VERSION "2.6.1")

# Set SFML directory
set(SFML_DIR "${CMAKE_BINARY_DIR}/SFML-${SFML_VERSION}")

#include
include_directories(include)

# Fetch SFML
include(FetchContent)
FetchContent_Declare(
    SFML
    URL "https://www.sfml-dev.org/files/SFML-${SFML_VERSION}-sources.zip"
)
FetchContent_GetProperties(SFML)
if(NOT SFML_POPULATED)
    FetchContent_Populate(SFML)
    add_subdirectory(${SFML_SOURCE_DIR} ${SFML_BINARY_DIR})
endif()

# Include SFML
include_directories(${SFML_DIR}/include)
link_directories(${SFML_DIR}/lib)
set(SFML_LIBRARIES sfml-graphics sfml-window sfml-system)

# Add your project files
file(GLOB SOURCES
    include/*.h
    src/*.cpp
)

add_executable(Maze_Generator_Solvere ${SOURCES})

# Link SFML libraries
target_link_libraries(Maze_Generator_Solvere ${SFML_LIBRARIES})