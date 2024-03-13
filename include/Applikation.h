#ifndef Applikation_H
#define Applikation_H

#include <SFML/Graphics.hpp>
#include <cell.h>
#include <Grid.h>

class Applikation
{
private:
    int CELLSIZE = 80;
    int WALLSIZE = 2;
    int WINDOW_HIGHT = (600);
    int WINDOW_WIGHT = (1200);
    int num_rows = WINDOW_HIGHT / (int)CELLSIZE;
    int num_columns = WINDOW_WIGHT / (int)CELLSIZE;
    sf::RenderWindow Applikation_window;
    Grid grid;

public:
    Applikation();
    void poolevent();
    void update_maze();
    void run();
    void render();
};

#endif
