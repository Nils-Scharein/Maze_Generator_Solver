#include "Applikation.h"
#include <chrono>
#include <thread>
#include <iostream>
#include <Grid.h>

int WINDOW_HIGHT = 1000;
int WINDOW_WIGHT = 600;
float CELLSIZE = 100;
float WALLSIZE = 6;

Applikation::Applikation()
    : Applikation_window(sf::VideoMode(WINDOW_HIGHT, WINDOW_WIGHT), "Maze Generator")
{
    num_rows = WINDOW_WIGHT / (int)CELLSIZE;
    num_columns = WINDOW_HIGHT / (int)CELLSIZE;
}

void init_setup()
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

    Applikation_window.clear(sf::Color::White);
    bool a = true;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 40; j++)
        {
            Cell temp(j, i, 40.00, 2);
            temp.draw(Applikation_window);
        }
    Applikation_window.display();
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
    Applikation_window.clear();

    Grid test(num_rows, num_columns, CELLSIZE, WALLSIZE);
    test.draw_grid(Applikation_window);
    Applikation_window.display();
}
