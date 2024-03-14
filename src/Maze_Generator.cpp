#include "Mazegenerator.h"
#include <Grid.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>

Maze_Generator::Maze_Generator()
    : run_maze{true}, choise{choice_generator::depth_first}
{
}

void Maze_Generator::update_generate_with_choosen(Grid &grid, sf::RenderWindow &window)
{
    if (run_maze)
    {
        if (choise == choice_generator::depth_first)
        {
            depth_first_search_stack(*grid.get_cell(0, 0), grid, window);
            run_maze = false;
        }
    }
}

void Maze_Generator::depth_first_search_stack(Cell current_cell, Grid &maze_grid, sf::RenderWindow &window)
{
    std::stack<Cell *> stack;
    Cell *start_cell = maze_grid.get_cell(0, 0); // Store the pointer to the random cell
    start_cell->set_visited();
    start_cell->set_type(Type::Start);
    stack.push(start_cell);
    while (!stack.empty())
    {
        window.clear();
        maze_grid.draw_grid(window);
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
        }
        else
        {
            // If the current cell has no unvisited neighbors, backtrack
            stack.pop();
        }

        // Display the updated window
        window.display();
    }
    run_maze = false;
}