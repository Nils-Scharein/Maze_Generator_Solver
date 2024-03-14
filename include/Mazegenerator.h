#ifndef Maze_Generator_H
#define Maze_Generator_H

#include "Grid.h"

class Maze_Generator
{
    enum choice_generator
    {
        depth_first
    };

private:
    choice_generator choise;
    bool run_maze;

public:
    Maze_Generator();
    choice_generator get_choise();

    void choose_generator();
    void update_generate_with_choosen(Grid &grid, sf::RenderWindow &window);
    void depth_first_search_stack(Cell current_cell, Grid &maze_grid, sf::RenderWindow &window);
    void reset();
    void pause();
};

#endif