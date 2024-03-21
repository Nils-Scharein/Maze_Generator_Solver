#ifndef Maze_Generator_H
#define Maze_Generator_H

#include "Grid.h"
#include <stack>

enum Choice_generator
{
    None_gen,
    depth_first,
    prim
};
class Maze_Generator
{
private:
    Choice_generator choise;
    bool run_generator;
    bool deph_init;
    bool prim_init;

public:
    // constructor
    Maze_Generator();

    // Helper Variables
    std::stack<Cell *> stack;
    std::vector<Cell *> frontier_vec;

    // getter
    // TODO: Write getter with Char not Enum
    char get_selected_gen();

    // setter
    void set_run_maze_on() { run_generator = true; };
    void set_run_maze_off() { run_generator = false; };
    void set_choise(Choice_generator new_choise) { choise = new_choise; };

    void update_generate_with_choosen(Grid &grid, sf::RenderWindow &window);
    void depth_first_search_stack(Grid &maze_grid, sf::RenderWindow &window);
    void prim(Grid &maze_grid, sf::RenderWindow &window);
    void toggle_run();
    void reset(Grid &grid, sf::RenderWindow &window);
};

#endif