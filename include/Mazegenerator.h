#ifndef Maze_Generator_H
#define Maze_Generator_H

#include "Grid.h"
#include <stack>
#include <map>

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
    int MAX_GEN = 3;
    int currentGenerator = 1;

    std::map<int, std::string> generator_dict = {
    {1, "None_gen"},
    {2, "depth_first"},
    {3, "prim"}
    };

public:
    // constructor
    Maze_Generator();

    // Helper Variables
    std::stack<Cell *> stack;
    std::vector<Cell *> frontier_vec;

    // setter
    void set_run_maze_on() { run_generator = true; };
    void set_run_maze_off() { run_generator = false; };
    void set_choise(Choice_generator new_choise) { choise = new_choise; };
    void cycleGenerator();

    void update_generate_with_choosen(Grid &grid, sf::RenderWindow &window);
    void depth_first_search_stack(Grid &maze_grid, sf::RenderWindow &window);
    void prim(Grid &maze_grid, sf::RenderWindow &window);
    void toggle_run();
    void reset(Grid &grid, sf::RenderWindow &window);
};

#endif