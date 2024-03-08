cmake_minimum_required(VERSION 3.5)
project(Maze_Generator_Solver VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

file(GLOB SOURCES
    include/*.h
    src/*.cpp
)

add_executable(Maze_Generator_Solver ${SOURCES})
include_directories(include)




set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
