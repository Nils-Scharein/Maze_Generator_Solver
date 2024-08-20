#ifndef Setting_Window_H
#define Setting_Window_H

#include "SFML/Graphics.hpp"
#include <Mazegenerator.h>
#include <Mazesolver.h>

class Settings_Window
{
private:
    int hight;
    int width;
    int offset;

public:
    Settings_Window(int Hight, int Width, int Offset);
    void update(sf::RenderWindow &window, Maze_Generator maze_gen, Maze_Solver maze_solv);
    sf::Text generator_message;
    sf::Text generator_selected;
    sf::Text solver_message;
    sf::Text solver_selected;
    sf::Font myfont;
};

#endif