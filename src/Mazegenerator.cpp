#include <Mazegenerator.h>
#include <Grid.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>

Maze_Generator::Maze_Generator()
    : run_generator{false},
      choise{Choice_generator::None_gen},
      deph_init{false},
      prim_init{false}
{
}

void Maze_Generator::toggle_run()
{
    run_generator = !run_generator;
}

void Maze_Generator::update_generate_with_choosen(Grid &grid, sf::RenderWindow &window)
{
    if (run_generator)
    {
        if (choise == Choice_generator::depth_first)
        {
            depth_first_search_stack(grid, window);
        }
        if (choise == Choice_generator::prim)
        {
            prim(grid, window);
        }
    }
}

void Maze_Generator::depth_first_search_stack(Grid &maze_grid, sf::RenderWindow &window)
{
    /*
    1. Choose the initial cell, mark it as visited and push it to the stack
    2. While the stack is not empty
        1. Pop a cell from the stack and make it a current cell
        2. If the current cell has any neighbours which have not been visited
            1. Push the current cell to the stack
            2. Choose one of the unvisited neighbours
            3. Remove the wall between the current cell and the chosen cell
            4. Mark the chosen cell as visited and push it to the stack
    */
    if (!deph_init)
    {
        Cell *start_cell = maze_grid.get_cell(0, 0);
        start_cell->set_visited();
        stack.push(start_cell);
        maze_grid.draw_grid(window);
        deph_init = true;
    }
    if (!run_generator)
    {
        return;
    }
    if (stack.empty())
    {
        run_generator = false;
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

void Maze_Generator::prim(Grid &maze_grid, sf::RenderWindow &window)
{
    if (!prim_init)
    {
        Cell *startcell = maze_grid.get_cell(0, 0);
        // Mark the start cell as visited and add its unvisited neighbors to the frontier
        startcell->set_visited();
        startcell->set_type(Finished);
        startcell->draw(window);
        std::vector<Cell *> frontier = maze_grid.get_unvisited_neighbours(startcell->get_x(), startcell->get_y());
        for (Cell *single_frontier : frontier)
        {
            single_frontier->set_type(Frontier);
            frontier_vec.push_back(single_frontier);
        }

        // Draw the start cell and the frontier cells
        for (Cell *frontier_cell : frontier)
        {
            frontier_cell->draw(window);
        }
        window.display();

        prim_init = true; // Mark initialization as complete
    }

    if (!frontier_vec.empty())
    {
        // Select a random frontier cell
        Cell *current_cell = maze_grid.select_random_cell(frontier_vec);
        current_cell->set_visited();
        current_cell->set_type(Finished);
        current_cell->draw(window);

        // Remove the current cell from the frontier
        std::vector<Cell *>::iterator it = std::find(frontier_vec.begin(), frontier_vec.end(), current_cell);
        if (it != frontier_vec.end())
        {
            frontier_vec.erase(it);
            // Reassign the iterator after erasing the element
            it = std::find(frontier_vec.begin(), frontier_vec.end(), current_cell);
            // Now 'it' points to the next occurrence of 'current_cell' if it exists, or 'frontier_vec.end()' otherwise
        }
        // Get unvisited neighbors of the current cell
        std::vector<Cell *> unvisited_neighbors = maze_grid.get_unvisited_neighbours(current_cell->get_x(), current_cell->get_y());
        for (Cell *neighbor : unvisited_neighbors)
        {
            // Check if the neighbor is not already in the frontier vector
            if (std::find(frontier_vec.begin(), frontier_vec.end(), neighbor) == frontier_vec.end())
            {
                // Mark the unvisited neighbor as frontier and add it to the frontier vector
                neighbor->set_type(Frontier);
                frontier_vec.push_back(neighbor);
                neighbor->draw(window);
            }
        }

        // Get visited neighbors of the current cell
        std::vector<Cell *> visited_neighbours = maze_grid.get_visited_neighbours(current_cell->get_x(), current_cell->get_y());
        if (!visited_neighbours.empty())
        {
            // Connect the current cell to a random visited neighbor
            Cell *random_visited_neighbour = maze_grid.select_random_cell(visited_neighbours);
            maze_grid.connect_cells(*current_cell, *random_visited_neighbour);
            current_cell->draw(window);
            random_visited_neighbour->draw(window);
        }

        window.display();
    }
}

void Maze_Generator::reset(Grid &grid, sf::RenderWindow &window)
{
    window.clear();
    grid.reset(window);
    run_generator = false;
    while (!stack.empty())
    {
        stack.pop();
    }
    frontier_vec.clear();
    deph_init = false;
    prim_init = false;
}