#ifndef Maze_Generator_H
#define Maze_Generator_H

#include "Grid.h"
#include <stack>

class Maze_Generator
{
    enum choice_generator
    {
        depth_first
    };

private:
    choice_generator choise;
    bool run_maze;
    bool deph_init;

public:
    Maze_Generator();
    choice_generator get_choise();
    std::stack<Cell *> stack;

    void set_run_maze_on() { run_maze = true; };
    void set_run_maze_off() { run_maze = false; };

    void choose_generator();
    void update_generate_with_choosen(Grid &grid, sf::RenderWindow &window);
    void depth_first_search_stack(Grid &maze_grid, sf::RenderWindow &window);
    void toggle_run();
    void reset(Grid &grid, sf::RenderWindow &window);
};

#endif