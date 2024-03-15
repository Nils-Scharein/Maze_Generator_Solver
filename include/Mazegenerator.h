#ifndef Maze_Generator_H
#define Maze_Generator_H

#include "Grid.h"
#include <stack>

enum Choice_generator
{
    depth_first,
    prim
};
class Maze_Generator
{
private:
    Choice_generator choise;
    bool run_maze;
    bool deph_init;
    bool prim_init;

public:
    Maze_Generator();
    std::stack<Cell *> stack;
    std::vector<Cell *> frontier_vec;

    void set_run_maze_on() { run_maze = true; };
    void set_run_maze_off() { run_maze = false; };
    void set_choise(Choice_generator new_choise) { choise = new_choise; };

    void choose_generator();
    void update_generate_with_choosen(Grid &grid, sf::RenderWindow &window);
    void depth_first_search_stack(Grid &maze_grid, sf::RenderWindow &window);
    void prim(Grid &maze_grid, sf::RenderWindow &window);
    void toggle_run();
    void reset(Grid &grid, sf::RenderWindow &window);
};

#endif