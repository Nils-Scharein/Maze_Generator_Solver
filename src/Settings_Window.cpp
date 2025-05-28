#include <Settings_window.h>
#include <iostream>

Settings_Window::Settings_Window(int Hight, int Width, int Offset)
    : hight{Hight}, width{Width}, offset{Offset}
{
    if (!myfont.loadFromFile("C:/Users/Nils/Desktop/git/Maze_Genertor_Solver/ressources/Montserrat-Regular.ttf"))
    {
        std::cout << "Failed to load font" << std::endl;
    }
    generator_message.setFont(myfont);
    generator_message.setString("Selected Maze Generator");
    generator_message.setCharacterSize(24);
    generator_message.setPosition(offset + 40, 30);

    generator_selected.setFont(myfont);
    generator_selected.setString("test");
    generator_selected.setCharacterSize(24);
    generator_selected.setPosition(offset + 155, 90);

    solver_message.setFont(myfont);
    solver_message.setString("Selected Maze Solver");
    solver_message.setCharacterSize(24);
    solver_message.setPosition(offset + 40, 150);

    solver_selected.setFont(myfont);
    solver_selected.setString("test");
    solver_selected.setCharacterSize(24);
    solver_selected.setPosition(offset + 155, 210);

}

void Settings_Window::update(sf::RenderWindow &window, Maze_Generator maze_gen, Maze_Solver maze_solv)
{
    window.draw(generator_message);
    generator_selected.setString("TEst2");
    window.draw(generator_selected);
    window.draw(solver_message);
    solver_selected.setString("TEst3");
    window.draw(solver_selected);
}