#include <iostream>
#include <string>
#include <Cell.h>
#include <Maze.h>
/*
int main(int, char **)
{
    Maze tes(5, 5);
    tes.create_matrix();
    tes.print_current_2D_Map();

    return true;
}*/

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}