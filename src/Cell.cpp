#include "Cell.h"
#include <iostream>
#include "SFML/Graphics.hpp"

Cell::Cell(int x, int y, int size, int wall_thiccnes)
    : x{x},
      y{y},
      visited{false},
      size{size},
      thickness_wall{wall_thiccnes},
      isaktiv{false}
{
    float cell_x = x * size;
    float cell_y = y * size;
    sf::Color wall_color = sf::Color::Black;
    sf::Color Cell_color(0, 255, 255, 0);

    cell_body.setFillColor(Cell_color);
    cell_body.setSize(sf::Vector2f(size, size));
    cell_body.setPosition(cell_x, cell_y);

    wall_n.setFillColor(wall_color);
    wall_n.setSize(sf::Vector2f(size, thickness_wall));
    wall_n.setPosition(sf::Vector2f(cell_x - thickness_wall, cell_y - thickness_wall));

    wall_e.setFillColor(wall_color);
    wall_e.setSize(sf::Vector2f(thickness_wall, size));
    wall_e.setPosition(sf::Vector2f(cell_x + size - thickness_wall, cell_y));

    wall_s.setFillColor(wall_color);
    wall_s.setSize(sf::Vector2f(size, thickness_wall));
    wall_s.setPosition(sf::Vector2f(cell_x, cell_y + size - thickness_wall));

    wall_w.setFillColor(wall_color);
    wall_w.setSize(sf::Vector2f(thickness_wall, size));
    wall_w.setPosition(sf::Vector2f(cell_x - thickness_wall, cell_y));
}

void Cell::print_attributes()
{
    std::cout << "x: " << x << " y: " << y << std::endl;
    std::cout << "Visited: " << visited << std::endl;
    std::cout << "Aktive: " << isaktiv << std::endl;
    std::cout << "Cell Type: " << cell_type << std::endl;
}

void Cell::set_type(Type type)
{
    // Check if the current type is already Start or End
    if (cell_type == Start || cell_type == End)
    {
        // Preserve the current type
        return;
    }

    // Otherwise, update the cell type based on the input type
    switch (type)
    {
    case Type::Start:
        cell_type = Start;
        break;
    case Type::End:
        cell_type = End;
        break;
    case Type::Visited:
        cell_type = Visited;
        break;
    case Type::Neutral:
        cell_type = Neutral;
        break;
    case Type::Finished:
        cell_type = Finished;
        break;
    }
}
void Cell::set_cellColor() const
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
        cell_body.setFillColor(sf::Color(255, 166, 0));
        break;
    case Finished:
        cell_body.setFillColor(sf::Color::Yellow);
        break;
    }
}

void Cell::draw(sf::RenderWindow &window) const
{
    set_cellColor();
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

void Cell::reset(sf::RenderWindow &window)
{
    isaktiv = false;
    visited = false;
    for (int i = 0; i < 4; ++i)
    {
        walls[i] = true;
    }
    cell_type = Type::Neutral;
}

void Cell::turn_wall_off(int wall)
{
    if (wall == 0)
        walls[0] = false;
    if (wall == 1)
        walls[1] = false;
    if (wall == 2)
        walls[2] = false;
    if (wall == 3)
        walls[3] = false;
}