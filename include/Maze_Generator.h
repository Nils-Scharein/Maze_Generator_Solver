#ifndef Matrix_H
#define Matrix_H

#include <vector>
#include <Cell.h>

class Maze
{
public:
    // constructor + deconstructor
    Maze(int h, int w);
    ~Maze();

    // Public here
    std::vector<std::vector<Cell>> get_maze() { return grid; };

    // public attributes
    bool create_matrix();
    bool print_current_2D_Map() const;
    bool generate_maze_recursive_backtracker();
    bool generate_maze_kruskal();
    bool generate_maze_prim();

private:
    // private attribbutes
    int hight;
    int wight;
    std::vector<std::vector<Cell>> grid; // is used for the 2d vector to save Cells
};

#endif // Matrix_H
