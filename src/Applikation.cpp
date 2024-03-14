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
                maze_gen.toggle_run();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                maze_gen.set_run_maze_on();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                maze_gen.reset(grid, Applikation_window);
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
    grid.draw_grid(Applikation_window);
    while (Applikation_window.isOpen())
    {
        poolevent();
        render();
    }
}

void Applikation::render()
{
    maze_gen.update_generate_with_choosen(grid, Applikation_window);
    Applikation_window.display();
}
