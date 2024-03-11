#ifndef Grid_H
#define Grid_H

#include <vector>
#include <Cell.h>

class Grid
{
private:
    int num_rows;
    int num_colums;
    float cell_size;
    float wall_size;
    std::vector<std::vector<Cell>> cell_vec;

public:
    Grid(int rows, int colums, float cell_size, float wall_size);
    int get_rows() { return num_rows; };
    int get_colums() { return num_colums; };

    // showing and creating funcs
    void create_grid();
    void draw_grid(sf::RenderWindow &window) const;
    void reset();

    // TODO: funcs for later Maze generating
    std::vector<Cell> get_random_neighbor_unvited();
    Cell get_Cell(int row, int colum);
    void set_cell_active();
    void connect_cells();
};

#endif
