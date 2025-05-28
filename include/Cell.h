#ifndef Cell_H
#define Cell_H

#include <SFML/Graphics.hpp>
#include <array>
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
    float gcost;
    float fcost;
    int size;
    int thickness_wall;
    Type cell_type = Neutral;

    // Walls saved in array this way (Used for Color and conncetion)
    // [0] = north
    // [1] = East (Right)
    // [2] = South
    // [3] = West (Left)

    std::array<bool, 4> walls = { true, true, true, true };

public:
    // constructor + deconstructor
    Cell(int x, int y, int size, int wall_thiccnes);

    // Getter
    int get_x() const { return x; };
    int get_y() const { return y; };
    bool get_visited() const { return visited; };
    bool get_isaktive() const { return isaktiv; };
    float get_gcost() { return gcost; };
    float get_fcost() { return fcost; };
    const std::array<bool, 4>& get_walls() const { return walls; }


    // Setter
    void set_gcost(float new_gcost) { gcost = new_gcost; };
    void set_fcost(float new_fcost) { fcost = new_fcost; };
    void set_type(Type type);
    void set_visited() { visited = true; };
    void set_unvisited() { visited = false; };
    void set_isaktive() { isaktiv = true; };
    void set_cellColor() const; 
    void set_size(int new_size) { size = new_size; };

    // funcs
    void reset();
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