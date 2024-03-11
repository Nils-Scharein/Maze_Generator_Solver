#include "Cell.h"
#include <iostream>
#include "SFML/Graphics.hpp"

Cell::Cell(int x, int y, float size, float wall_thiccnes)
    : x{x},
      y{y},
      visited{false},
      size{size},
      thickness_wall{wall_thiccnes},
      isaktiv{false}
{
    sf::Color wall_color = sf::Color::Black;
    sf::Color fill_color = sf::Color::Cyan;

    cell_body.setSize(sf::Vector2f(size, size));
    cell_body.setFillColor(fill_color);
    cell_body.setPosition(x * size, y * size);

    wall_n.setSize(sf::Vector2f(size, thickness_wall));
    wall_n.setPosition(sf::Vector2f(x * size, y * size));
    wall_n.setFillColor(wall_color);

    wall_e.setSize(sf::Vector2f(size, thickness_wall));
    wall_e.setPosition(sf::Vector2f(x * size + size, y * size));
    wall_e.setFillColor(wall_color);
    wall_e.rotate(90);

    wall_s.setSize(sf::Vector2f(size, thickness_wall));
    wall_s.setPosition(sf::Vector2f(x * size, y * size + size));
    wall_s.setFillColor(wall_color);

    wall_w.setSize(sf::Vector2f(size, thickness_wall));
    wall_w.setPosition(sf::Vector2f(x * size, y * size));
    wall_w.setFillColor(wall_color);
    wall_w.rotate(90);
}

void Cell::set_type(Type type)
{
    switch (type)
    {
    case (Type::Start):
        cell_type = Start;
        break;
    case (Type::End):
        cell_type = End;
        break;
    case (Type::Visited):
        break;
        cell_type = Visited;
    case (Type::Neutral):
        cell_type = Neutral;
        break;
    }
}

void Cell::setCellColor() const
{
    switch (cell_type)
    {
    case Start:
        cell_body.setFillColor(sf::Color::Green);
        break;
    case End:
        cell_body.setFillColor(sf::Color::Red);
        break;
    case Neutral:
        cell_body.setFillColor(sf::Color::Cyan);
        break;
    case Visited:
        cell_body.setFillColor(sf::Color::Blue);
        break;
    }
}

void Cell::draw(sf::RenderWindow &window) const
{
    setCellColor();
    window.draw(cell_body);
    if (walls[0]) // North
        window.draw(wall_n);
    if (walls[1]) // East
        window.draw(wall_e);
    if (walls[2]) // south
        window.draw(wall_s);
    if (walls[3]) // west
        window.draw(wall_w);
}

// TODO: Check if works
void Cell::reset(sf::RenderWindow &window)
{
    isaktiv = false;
    visited = false;
    draw(window);
}