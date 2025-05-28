#include "MazeRenderer.h"
#include "grid.h"
#include <SFML/Graphics.hpp>


MazeRenderer::MazeRenderer()
{
}

void MazeRenderer::render_single_cell(const Cell& cell, sf::RenderWindow& window) const
{
    // Assuming set_cellColor() is a method of Cell that sets the cell's color
    cell.set_cellColor();

    // Draw the cell's body
    window.draw(cell.cell_body);

    //Draw the cell's walls if they exist
    const auto& walls = cell.get_walls();
    if (walls[0]) // North
        window.draw(cell.wall_n);
    if (walls[1]) // East
        window.draw(cell.wall_e);
    if (walls[2]) // South
        window.draw(cell.wall_s);
    if (walls[3]) // West
       window.draw(cell.wall_w);
}

void MazeRenderer::render_given_cells(const std::vector<Cell*>& cells_to_render, sf::RenderWindow& window)
{
    for (const auto& cell : cells_to_render)
    {
        render_single_cell(*cell, window);
    }
    window.display();
}