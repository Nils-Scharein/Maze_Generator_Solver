#ifndef Applikation_H
#define Applikation_H

#include <SFML/Graphics.hpp>
#include <cell.h>

class Applikation
{
private:
    int num_rows;
    int num_columns;
    sf::RenderWindow Applikation_window;

public:
    Applikation();

    void poolevent();
    void update_maze();
    void run();
    void render();
};

// TODO: implement Algorythemn to generate / solve Maze

#endif
