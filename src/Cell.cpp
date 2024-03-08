#include "Cell.h"

int Cell::num_cells = 0;

Cell::Cell()
    : type{"None"}, color{"black"}, visited{false}
{
    num_cells++;
}

Cell::~Cell()
{
    num_cells--;
}

bool Cell::set_cell_type(std::string t)
{
    type = t;
    return true;
}

bool Cell::print_Cell() const
{
    if (type == "None")
    {
        std::cout << " X ";
    }
    else if (type == "Wall")
    {
        std::cout << " W ";
    }
    else if (type == "Path")
    {
        std::cout << " P ";
    }
    return true;
}