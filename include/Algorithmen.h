#ifndef Algo_H
#define Algo_H

// TODO: implement Algorythemn to generate / solve Maze

#endif

file(GLOB SOURCES
    include/*.h
    src/*.cpp
)

add_executable(Maze_Generator_Solver ${SOURCES})
include_directories(include)



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)