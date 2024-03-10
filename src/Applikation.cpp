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

void Applikation::update_maze(sf::RenderWindow &window)
{
    // TODO: Dession + Create + Render Maze Generator // Maze Solver comes later
    Cell test(0, 0, 50.00);
    Cell test2(50, 0, 50.00);
    window.clear();
    test.draw(window);
    test2.draw(window);
    window.display();
}

void Applikation::run(sf::RenderWindow &window)
{
    while (window.isOpen())
    {
        poolevent(window);
        update_maze(window);
    }
}
