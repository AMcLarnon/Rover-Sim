#include "Grid.h"
#include <iostream>

Grid::Grid(int gridWidth, int gridHeight) {
    width = gridWidth;
    height = gridHeight;
}

void Grid::display(int roverX, int roverY) {
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            if (col == roverX - 1 && row == roverY - 1) {
                std::cout << "R";
            } else {
                std::cout << ".";
            }
        }
        std::cout << "\n";
    }
}
