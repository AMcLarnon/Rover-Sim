#include "Grid.h"
#include <iostream>

Grid::Grid(int gridWidth, int gridHeight) {
    width = gridWidth;
    height = gridHeight;
}

void Grid::display(int roverX, int roverY) {
    for (int row = 0; row <= height + 1; ++row) {
        for (int col = 0; col <= width + 1; ++col) {

            if (row == 0 || row == height + 1 || 
                col == 0 || col == width + 1) {
                std::cout << "#";
            }
            else if (col == roverX && row == roverY) {
                std::cout << "R";
            }
            else {
                std::cout << ".";
            }

        }

        std::cout << "\n";
    }
}