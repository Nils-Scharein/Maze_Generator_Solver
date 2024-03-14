#include "Applikation.h"
#include <chrono>
#include <thread>
#include <iostream>
#include <Grid.h>
#include <random>

Applikation::Applikation()
    : Applikation_window(sf::VideoMode(WINDOW_WIGHT, WINDOW_HIGHT), "Maze Generator"),
      grid(num_rows, num_columns, CELLSIZE, WALLSIZE),
      maze_gen()
{
}

void Applikation::poolevent()
{
    sf::Event event;
    while (Applikation_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            Applikation_window.close();
        }
        if (event.type == sf::Event::KeyPressed)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                Applikation_window.close();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
            {
                // TODO: Pause Generation
                std::cout << "Pressed P\n";
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                // TODO: Start der Simulation
                std::cout << "Pressed S\n";
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                // TODO: Reset Maze and Stop
                std::cout << "Pressed R\n";
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
            {
                // TODO: Maze Generator 1
                std::cout << "Pressed Generator 1\n";
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
            {
                // TODO: Maze Generator 2
                std::cout << "Pressed Generator 2\n";
            }
        }
    }
}

void Applikation::update_maze()
{
    // TODO: Dession + Create + Render Maze Generator // Maze Solver comes later
}

void Applikation::run()
{
    while (Applikation_window.isOpen())
    {
        poolevent();
        render();
    }
}

void Applikation::render()
{
    Applikation_window.clear(sf::Color::White);
    maze_gen.update_generate_with_choosen(grid, Applikation_window);
}
