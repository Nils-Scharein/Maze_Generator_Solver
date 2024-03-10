#ifndef Cell_H
#define Cell_H

#include <string> //TODO: DELETE
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
    bool walls[4] = {true, true, true, true}; // sets if the Cell has Walls or not
    std::string type;                         // TODO:DELETE

    // For Setting the Tyoe of the Cell
    enum class Type
    {
        Start,
        Ende,
        Visited,
        Neutral
    };

public:
    // constructor + deconstructor
    Cell();
    ~Cell();

    // public attributes
    // declared inside

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

    void draw(sf::RenderWindow &window);
    void set_type(Type type);

    // set SFML Shapes for Walls
    sf::RectangleShape wall_n;
    sf::RectangleShape wall_s;
    sf::RectangleShape wall_r;
    sf::RectangleShape wall_l;

    sf::RectangleShape cell_body;
};

#endif // Cell_H