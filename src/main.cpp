#include <iostream>
#include <string>
#include <Cell.h>
#include <Maze.h>
#include <SFML/Graphics.hpp>

int WINDOW_HIGHT = 1000;
int WINDOW_WIGHT = 600;

int main()
{

    sf::RenderWindow window(sf::VideoMode(WINDOW_HIGHT, WINDOW_WIGHT), "Maze Generator");
    sf::CircleShape shape(100.f);
    sf::CircleShape test(250.f);
    shape.setFillColor(sf::Color::Blue);
    shape.setOutlineColor(sf::Color::Yellow);
    shape.setOutlineThickness(10);
    test.setFillColor(sf::Color::White);
    test.setOutlineColor(sf::Color::Red);
    test.setOutlineThickness(10);

    while (window.isOpen())
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

    return 0;
}