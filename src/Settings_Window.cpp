#include <Settings_window.h>
#include <iostream>

Settings_Window::Settings_Window(int Hight, int Width, int Offset)
    : hight{Hight}, width{Width}, offset{Offset}
{
    if (!myfont.loadFromFile("./ressources/Montserrat-Regular.ttf"))
    {
        std::cout << "Failed to load font" << std::endl;
    }
    Generator_Message.setFont(myfont);
    Generator_Message.setString("Test");
    Generator_Message.setPosition((offset + ((Width - Offset) / 10)), (Hight - Hight / 10));
    sf::Text generator_choice;
    sf::Text solver_choice;
}

void Settings_Window::update(sf::RenderWindow &window, Maze_Generator maze_gen, Maze_Solver maze_solv)
{
    window.draw(Generator_Message);
}