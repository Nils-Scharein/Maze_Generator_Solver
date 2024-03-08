#ifndef Matrix_H
#define Matrix_H

#include <vector>
#include <Cell.h>

class Matrix
{
public:
    // constructor + deconstructor
    Matrix(int h, int w);
    ~Matrix();

    // public attributes
    bool create_matrix();
    bool print_matrix() const;

private:
    // private attribbutes
    int hight;
    int wight;
    std::vector<std::vector<Cell>> grid; // is used for the 2d vector to save Cells
};

#endif // Matrix_H
