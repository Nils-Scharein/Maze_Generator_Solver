#ifndef Cell_H
#define Cell_H

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

class Cell
{
private:
    // static
    // FIXME: num_cells to show correct number (Need to add in Copyconstrucor, that increase number and copy all the values)
    static int num_cells;
    // private attribbutes
    int x, y;
    bool visited;
    bool is_active;
    float size = 30.f;
    float thickness = 2.f;
    bool walls[4] = {true, true, true, true};
    std::string type;

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
    bool set_x(int _x)
    {
        x = _x;
        return true;
    };
    bool get_x(int x) { return x; };
    bool set_y(int _y)
    {
        x = _y;
        return true;
    };
    bool get_y(int y) { return y; };
    bool set_color();
    bool set_type();
    bool print_cell_2D() const;
    bool draw(sf::RenderWindow &window) const;
};

#endif // Cell_H