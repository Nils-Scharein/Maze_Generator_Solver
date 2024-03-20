#include <Settings_window.h>
#include <iostream>

Settings_Window::Settings_Window(int Hight, int Width, int Offset)
    : hight{Hight}, width{Width}, offset{Offset}
{
    if (!myfont.loadFromFile("C:/Users/Nils/Desktop/git/Maze_Genertor_Solver/ressources/Montserrat-Regular.ttf"))
    {
        std::cout << "Failed to load font" << std::endl;
    }
    Generator_Message.setFont(myfont);
    Generator_Message.setString("Selected Maze Generator");
    Generator_Message.setCharacterSize(24);
    Generator_Message.setPosition(offset + 40, 30);

    generator_selected.setFont(myfont);
    generator_selected.setString("test");
    generator_selected.setCharacterSize(24);
    generator_selected.setPosition(offset + 40, 60);
}

void Settings_Window::update(sf::RenderWindow &window, Maze_Generator maze_gen, Maze_Solver maze_solv)
{
    window.draw(Generator_Message);
    generator_selected.setString(maze_gen.get_selected_gen());
    window.draw(generator_selected);
}