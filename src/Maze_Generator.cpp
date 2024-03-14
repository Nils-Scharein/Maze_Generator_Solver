#include "Mazegenerator.h"
#include <Grid.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>

Maze_Generator::Maze_Generator()
    : run_maze{false},
      choise{choice_generator::depth_first},
      deph_init{false}
{
}

void Maze_Generator::toggle_run()
{
    run_maze = !run_maze;
}

void Maze_Generator::update_generate_with_choosen(Grid &grid, sf::RenderWindow &window)
{
    if (run_maze)
    {
        if (choise == choice_generator::depth_first)
        {
            depth_first_search_stack(grid, window);
        }
    }
}

void Maze_Generator::depth_first_search_stack(Grid &maze_grid, sf::RenderWindow &window)
{
    if (!deph_init)
    {
        Cell *start_cell = maze_grid.get_cell(0, 0); // Store the pointer to the random cell
        start_cell->set_visited();
        start_cell->set_type(Type::Start);
        maze_grid.get_cell((maze_grid.get_colums() - 1), (maze_grid.get_rows() - 1))->set_type(Type::End);
        stack.push(start_cell);
        maze_grid.draw_grid(window);
        deph_init = true;
    }
    if (!run_maze)
    {
        return;
    }
    if (stack.empty())
    {
        run_maze = false;
        return;
    }
    if (!stack.empty())
    {
        Cell *currentCell = stack.top();

        std::vector<Cell *> unvisited_neighbors = maze_grid.get_unvisited_neighbours(currentCell->get_x(), currentCell->get_y());
        if (!unvisited_neighbors.empty())
        {
            // If the current cell has unvisited neighbors
            Cell *neighbour = maze_grid.select_random_cell(unvisited_neighbors); // Select a random unvisited neighbor
            maze_grid.connect_cells(*currentCell, *neighbour);
            neighbour->set_visited();
            neighbour->set_type(Type::Visited);
            stack.push(neighbour); // Push the pointer to the neighbor cell
            neighbour->draw(window);
            window.display();
        }
        else
        {
            // If the current cell has no unvisited neighbors, backtrack
            stack.pop();
            currentCell->set_type(Type::Finished);
            currentCell->draw(window);
            window.display();
        }

        // Display the updated window
        window.display();
    }
}

void Maze_Generator::reset(Grid &grid, sf::RenderWindow &window)
{
    window.clear();
    grid.reset(window);
    run_maze = false;
    while (!stack.empty())
    {
        stack.pop();
    }
    deph_init = false;
    grid.draw_grid(window);
}