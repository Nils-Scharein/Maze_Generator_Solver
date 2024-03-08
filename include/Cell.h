#ifndef Cell_H
#define Cell_H

#include <string>
#include <iostream>

class Cell
{
private:
    // static
    // FIXME: num_cells to show correct number (Need to add in Copyconstrucor, that increase number and copy all the values)
    static int num_cells;
    // private attribbutes
    bool visited;
    std::string type;
    std::string color;

public:
    // constructor + deconstructor
    Cell();
    ~Cell();

    // public attributes
    // declared inside
    static int get_num_cells() { return num_cells; };

    // declared outside
    // TODO: declare most of these funcs in cpp file
    bool set_cell_type(std::string t);
    bool set_color();
    bool set_type();
    bool print_Cell() const;
};

#endif // Cell_H