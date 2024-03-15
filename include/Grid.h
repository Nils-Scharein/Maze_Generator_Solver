#ifndef Grid_H
#define Grid_H

#include <vector>
#include <Cell.h>

class Grid
{
private:
    int num_rows;
    int num_colums;
    int cell_size;
    int wall_size;
    std::vector<std::vector<Cell>> cell_vec;

public:
    Grid(int rows, int colums, int cell_size, int wall_size);
    int get_rows() { return num_rows; };
    int get_colums() { return num_colums; };

    // showing and creating funcs
    void create_grid();
    void draw_grid(sf::RenderWindow &window) const;
    void reset(sf::RenderWindow &window);

    // TODO: funcs for later Maze generating
    std::vector<Cell *> get_unvisited_neighbours(int x, int y);
    std::vector<Cell *> get_visited_neighbours(int x, int y);
    void connect_cells(Cell &cell1, Cell &cell2);
    Cell *get_cell(int row, int colum);
    Cell *get_random_cell();
    Cell *select_random_cell(std::vector<Cell *> &cell_selection);
    // TODO: Needed?
    void set_cell_active();
};

#endif
