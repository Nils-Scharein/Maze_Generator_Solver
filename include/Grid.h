#ifndef Grid_H
#define Grid_H

#include <vector>
#include <Cell.h>
#include <MazeRenderer.h>
class Grid
{
private:
    int num_rows;
    int num_colums;
    int cell_size;
    int wall_size;
    std::vector<std::vector<Cell>> cell_vec;
    static std::vector<Cell*> cells_to_redraw;

public:
    Grid(int rows, int columns, int cell_size, int wall_size);
    int get_rows() { return num_rows; };
    int get_colums() { return num_colums; };
    Cell* get_cell(int row, int colum);
    Cell* get_random_cell();
    std::vector<Cell*> get_unvisited_neighbours(int x, int y);
    std::vector<Cell*> get_visited_neighbours(int x, int y);
    std::vector<Cell*> get_all_cell_Pointers();
    std::vector<Cell*> get_cells_to_redraw() { return cells_to_redraw; };

    // showing and creating funcs
    void create_grid();
    void reset_grid_state();
    static void mark_cell_for_redraw(Cell& cell);
    void clear_cells_for_redraw();

    void connect_cells(Cell &cell1, Cell &cell2);
    Cell *select_random_cell(std::vector<Cell *> &cell_selection);
};

#endif
