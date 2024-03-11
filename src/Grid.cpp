#include "Grid.h"
#include "Cell.h"
#include <vector>

Grid::Grid(int rows, int colums, float cell_size, float wall_size)
    : num_rows{rows}, num_colums{colums}, cell_size{cell_size}, wall_size{wall_size}
{
    create_grid();
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
/*
void Grid::reset()
{

}
*/
/*
std::vector<Cell> Grid::get_random_neighbor_unvited()
{
    return std::vector<Cell>{};
}
*/
/*
Cell Grid::get_Cell(int row, int colum)
{
    return Cell;
}
*/
/*
void set_cell_active(Cell cell)
{
    cell
}
*/