#include "Cell.h"
#include "SFML/Graphics.hpp"

int Cell::num_cells = 0;

Cell::Cell()
    : type{"None"}, visited{false}, is_active{false}
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

bool Cell::print_cell_2D() const
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

bool Cell::draw(sf::RenderWindow &window) const
{
    sf::RectangleShape rect;
    if (is_active)
    {
        rect.setFillColor(sf::Color::Black);
        rect.setSize(sf::Vector2(size, size));
        rect.setPosition(x, y);
        window.draw(rect);
    }

    return true;
}