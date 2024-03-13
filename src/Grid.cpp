#include <Cell.h>
#include <Grid.h>
#include <vector>
#include <random>
#include <iostream>

Grid::Grid(int rows, int colums, float cell_size, float wall_size)
    : num_rows{rows}, num_colums{colums}, cell_size{cell_size}, wall_size{wall_size}
{
    create_grid();
}

Cell &Grid::get_cell(int colum, int row)
{
    return cell_vec[row][colum];
}

Cell &Grid::select_random_cell(std::vector<Cell *> cell_selection)
{
    if (cell_selection.empty())
    {
        throw std::invalid_argument("Select_random_cell: Vector is empty");
    }
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, cell_selection.size() - 1);
    int random_num = dist(rd);
    Cell random_cell = *cell_selection[random_num];
    return get_cell(random_cell.get_x(), random_cell.get_y());
}

Cell &Grid::get_random_cell()
{
    // Seed for the random number generator
    std::random_device rd;
    // Initialize the random number generator
    std::mt19937 gen(rd());
    // Generate a random index within the range of valid indices for the vector
    std::uniform_int_distribution<> dis(0, cell_vec.size() - 1);
    int random_index_x = dis(gen);
    int random_index_y = dis(gen);
    // Return the random element
    return cell_vec[random_index_x][random_index_y];
}

void Grid::create_grid()
{
    for (int y = 0; y < num_rows; y++)
    {
        std::vector<Cell> temp_vec;
        for (int x = 0; x < num_colums; x++)
        {
            Cell temp_cell(x, y, cell_size, wall_size);
            temp_vec.push_back(temp_cell);
        }
        cell_vec.push_back(temp_vec);
    }
}

void Grid::draw_grid(sf::RenderWindow &window) const
{
    for (const auto &row : cell_vec)
    {
        for (const Cell &single_cell : row)
        {
            single_cell.draw(window);
        }
    }
}
void Grid::reset(sf::RenderWindow &window)
{
    for (auto &row : cell_vec)
    {
        for (Cell &single_cell : row)
        {
            single_cell.reset(window);
        }
    }
}

std::vector<Cell *> Grid::get_unvisited_neighbours(int x, int y)
{
    // first checkaround the givien cordinades and return the first all unvisted neighbors
    std::vector<Cell *> unvisited_neighbors;
    // is a valid cell given? Return empty vector if the coordinates are out of bounds from the Grid
    if (x < 0 || x >= num_colums || y < 0 || y >= num_rows)
    {
        return unvisited_neighbors;
    }
    // check if top cell is option
    if (y > 0 && !cell_vec[y - 1][x].get_visited())
    {
        unvisited_neighbors.push_back(&cell_vec[y - 1][x]);
    }
    // check if bottom cell is option
    if (y < num_rows - 1 && !cell_vec[y + 1][x].get_visited())
    {
        unvisited_neighbors.push_back(&cell_vec[y + 1][x]);
    }
    // check if left cell is option
    if (x > 0 && !cell_vec[y][x - 1].get_visited())
    {
        unvisited_neighbors.push_back(&cell_vec[y][x - 1]);
    }
    // check if right cell is option
    if (x < num_colums - 1 && !cell_vec[y][x + 1].get_visited())
    {
        unvisited_neighbors.push_back(&cell_vec[y][x + 1]);
    }
    return unvisited_neighbors;
}

void Grid::connect_cells(Cell &cell1, Cell &cell2)
{
    int x1 = cell1.get_x();
    int x2 = cell2.get_x();
    int y1 = cell1.get_y();
    int y2 = cell2.get_y();
    // Walls saved in array this way (Used for Color and connection)
    // [0] = north
    // [1] = East (Right)
    // [2] = Soth
    // [3] = West (Left)
    // Cells are vertical and should be connected left and right
    if (y1 == y2)
    {
        // cell 1 is right from cell 2
        if (x1 > x2)
        {
            cell1.turn_wall_off(3);
            cell2.turn_wall_off(1);
        }
        // cell 1 is left from cell2
        else if (x1 < x2)
        {
            cell1.turn_wall_off(1);
            cell2.turn_wall_off(3);
        }
    }
    // Cells are horizontal and should be connected up and down
    else if (x1 == x2)
    {
        // cell 1 is under cell 2
        if (y1 > y2)
        {
            cell1.turn_wall_off(0);
            cell2.turn_wall_off(2);
        }
        // cell 1 is above cell 2
        else if (y1 < y2)
        {
            cell1.turn_wall_off(2);
            cell2.turn_wall_off(0);
        }
    }
    else
    {
        std::cout << "ERROR CONNECT CELLS\n";
    }
}
