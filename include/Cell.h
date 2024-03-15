#ifndef Cell_H
#define Cell_H

#include <SFML/Graphics.hpp>
// Decides Color and how to interact with the cell
enum Type
{
    Start,
    End,
    Visited,
    Neutral,
    Finished,
    Frontier
};
class Cell
{
private:
    // private attribbutes
    int x;
    int y;
    bool visited;
    bool isaktiv;
    int size;
    int thickness_wall;
    Type cell_type = Neutral;

    // Walls saved in array this way (Used for Color and conncetion)
    // [0] = north
    // [1] = East (Right)
    // [2] = South
    // [3] = West (Left)

    bool walls[4] = {true, true, true, true}; // sets if the Cell has Walls or not

public:
    // constructor + deconstructor
    Cell(int x, int y, int size, int wall_thiccnes);

    // Getter
    int get_x() const { return x; };
    int get_y() const { return y; };
    bool get_visited() const { return visited; };
    bool get_isaktive() const { return isaktiv; };

    // Setter
    void set_type(Type type);
    void set_visited() { visited = true; };
    void set_unvisited() { visited = false; };
    void set_isaktive() { isaktiv = true; };
    void set_cellColor() const; // cell_body is mutable
    void set_size(int new_size) { size = new_size; };

    // funcs
    void
    draw(sf::RenderWindow &window) const;
    void reset(sf::RenderWindow &window);
    void turn_wall_off(int wall);

    // helper
    void print_attributes();

    // set SFML Shapes for Walls and body
    sf::RectangleShape wall_n;
    sf::RectangleShape wall_e;
    sf::RectangleShape wall_s;
    sf::RectangleShape wall_w;

    mutable sf::RectangleShape cell_body;
};

#endif // Cell_H