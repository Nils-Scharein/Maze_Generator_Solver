#ifndef Maze_Solver_H
#define Maze_Solver_H

#include <Grid.h>

enum Choice_solver
{
    None_solv,
    a_star
};

class Maze_Solver
{
private:
    Choice_solver choise;
    bool run_solver;
    bool a_star_init;

public:
    Maze_Solver();

    std::vector<Cell *> vec_cells;

    // setter
    void set_run_maze_on() { run_solver = true; };
    void set_run_maze_off() { run_solver = false; };
    void set_choise(Choice_solver new_choise) { choise = new_choise; };

    void update_solver_with_choosen(Grid &grid, sf::RenderWindow &window);
    void a_star(Grid &maze_grid, sf::RenderWindow &window);
    void toggle_run();
    void reset(Grid &grid, sf::RenderWindow &window);
};

#endif