#include <Mazesolver.h>

Maze_Solver::Maze_Solver()
    : run_solver{false},
      choise{Choice_solver::None_solv},
      a_star_init{false}
{
}

void Maze_Solver::update_solver_with_choosen(Grid &grid, sf::RenderWindow &window)
{
    if (run_solver)
    {
        if (choise == Choice_solver::a_star)
        {
            a_star(grid, window);
        }
    }
}

void recunstruct_path()
{
    return;
}

void Maze_Solver::a_star(Grid &maze_grid, sf::RenderWindow &window)
{

    if (!a_star_init)
    {
        Cell *start_cell = maze_grid.get_cell(0, 0);
    }
    int a = 10;
    return;
}

void Maze_Solver::toggle_run()
{
    run_solver = !run_solver;
}
void Maze_Solver::reset(Grid &grid, sf::RenderWindow &window)
{
    grid.reset(window);
    run_solver = false;
    a_star_init = false;
}