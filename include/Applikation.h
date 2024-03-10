#ifndef Applikation_H
#define Applikation_H

#include <SFML/Graphics.hpp>
#include <cell.h>

class Applikation
{
private:
public:
    Applikation()
    {
    }
    ~Applikation()
    {
    }

    void poolevent(sf::RenderWindow &window);
    void update_maze(sf::RenderWindow &window);
    void run(sf::RenderWindow &window);
};

// TODO: implement Algorythemn to generate / solve Maze

#endif
