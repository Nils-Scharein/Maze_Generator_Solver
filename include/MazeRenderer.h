#ifndef MAZERENDERER_H
#define MAZERENDERER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Cell.h"

class MazeRenderer {
public:
    MazeRenderer();
    void render_single_cell(const Cell& cell, sf::RenderWindow& window) const;
    void render_given_cells(const std::vector<Cell*>& cells_to_render, sf::RenderWindow& window);

private:
    std::vector<Cell*> cells_to_redraw;
};

#endif // MAZERENDERER_H
