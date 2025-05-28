#include <Applikation.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <Grid.h>
#include <random>

Applikation::Applikation()
    : Applikation_window(sf::VideoMode(MAZE_WIGHT + SETTINGSWINDOW_WIGHT, MAZE_HIGHT), "Maze Generator"),
      grid(num_rows, num_columns, CELLSIZE, WALLSIZE),
      maze_gen(),
      maze_solv(),
      settings_window(MAZE_HIGHT, SETTINGSWINDOW_WIGHT, MAZE_WIGHT)
{
    // Applikation_window.setFramerateLimit(1000);
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
                maze_gen.set_choise(Choice_generator::depth_first);
                maze_gen.reset(grid, Applikation_window);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
            {
                maze_gen.set_choise(Choice_generator::prim);
                maze_gen.reset(grid, Applikation_window);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
            {
                maze_solv.set_choise(Choice_solver::a_star);
            }
        }
    }
}

void Applikation::run()
{
    grid.create_grid();
    renderer.render_given_cells(grid.get_all_cell_Pointers(), Applikation_window);
    while (Applikation_window.isOpen())
    {
        poolevent();
        render();
    }
}

void Applikation::render()
{
    maze_gen.update_generate_with_choosen(grid, Applikation_window);
    settings_window.update(Applikation_window, maze_gen, maze_solv);
    renderer.render_given_cells(grid.get_cells_to_redraw(), Applikation_window);
    grid.clear_cells_for_redraw();
    Applikation_window.display();
}
