#ifndef Cell_H
#define Cell_H

#include <SFML/Graphics.hpp>

class Cell
{
private:
    // Decides Color and how to interact with the cell
    enum Type
    {
        Start,
        End,
        Visited,
        Neutral
    };

    // private attribbutes
    int x, y;
    bool visited;
    bool isaktiv;
    float size;
    float thickness_wall;
    Type cell_type = Neutral;

    // Walls saved in array this way (Used for Color and conncetion)
    // [0] = north
    // [1] = East
    // [2] = Soth
    // [3] = West

    bool walls[4] = {true, true, true, true}; // sets if the Cell has Walls or not

public:
    // constructor + deconstructor
    Cell(int x, int y, float size, float wall_thiccnes);

    // Getter
    bool get_x(int x) const { return x; };
    bool get_y(int y) const { return y; };
    bool get_visited() const { return visited; };
    bool get_isaktive() const { return isaktiv; };

    // Setter
    void set_type(Type type);
    void set_visited() { visited = true; };
    void set_isaktive() { isaktiv = true; };
    void setCellColor() const; // cell_body is mutable

    // funcs
    void draw(sf::RenderWindow &window) const;
    void reset(sf::RenderWindow &window);

    // set SFML Shapes for Walls
    sf::RectangleShape wall_n;
    sf::RectangleShape wall_e;
    sf::RectangleShape wall_s;
    sf::RectangleShape wall_w;

    mutable sf::RectangleShape cell_body;
};

#endif // Cell_H