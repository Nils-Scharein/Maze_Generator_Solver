#include <iostream>
#include <string>
#include <Cell.h>
#include <Matrix.h>

int main(int, char **)
{
    Matrix tes(5, 5);
    tes.create_matrix();
    tes.print_matrix();

    return true;
}
