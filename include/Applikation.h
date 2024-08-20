#ifndef Applikation_H
#define Applikation_H

#include <SFML/Graphics.hpp>
#include <cell.h>
#include <Grid.h>
#include <Mazegenerator.h>
#include <Mazesolver.h>
#include <Settings_window.h>
class Applikation
{
private:
    int CELLSIZE = 40;
    int WALLSIZE = 2;
    int MAZE_HIGHT = 800;
    int MAZE_WIGHT = 1400;
    int SETTINGSWINDOW_WIGHT = 400;
    int num_rows = MAZE_HIGHT / (int)CELLSIZE;
    int num_columns = MAZE_WIGHT / (int)CELLSIZE;
    sf::RenderWindow Applikation_window;
    MazeRenderer renderer;
    Grid grid;
    Maze_Generator maze_gen;
    Maze_Solver maze_solv;
    Settings_Window settings_window;

public:
    Applikation();
    void poolevent();
    void run();
    void render();
};

#endif
