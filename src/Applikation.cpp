#include "Applikation.h"

void Applikation::poolevent(sf::RenderWindow &window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed)
            if (sf::Keyboard::Escape)
                window.close();
    }
}

void Applikation::run(sf::RenderWindow &window)
{
    poolevent(window);
}

void update_maze()
{
    // TODO: Dession + Create + Render Maze Generator // Maze Solver comes later
}