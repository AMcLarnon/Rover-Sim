#include "Grid.h"
#include <iostream>

Grid::Grid(int gridWidth, int gridHeight) {
    width = gridWidth;
    height = gridHeight;
}

void Grid::display() {
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            std::cout << ".";
        }
        std::cout << "\n";
    }
}
