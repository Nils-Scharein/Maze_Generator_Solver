#include "Cell.h"
#include <iostream>
#include "SFML/Graphics.hpp"

Cell::Cell()
    : type{"None"}, visited{false}, is_active{false}
{
    // TODO: Add SFML creation of the Cell with the Walls
}

Cell::~Cell()
{
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

void Cell::set_type(Type type)
{
    switch (type)
    {
    case (Type::Start):
        break;
    case (Type::Ende):
        break;
    case (Type::Visited):
        break;
    case (Type::Neutral):
        break;
    }
}

void Cell::draw(sf::RenderWindow &window)
{
    sf::RectangleShape rect;
    if (is_active)
    {
        rect.setFillColor(sf::Color::Black);
        rect.setSize(sf::Vector2(size, size));
        rect.setPosition(x, y);
        window.draw(rect);
    }
}