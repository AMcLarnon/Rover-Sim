#ifndef GRID_H
#define GRID_H

#include "Terrain.h"

class Grid {
private:
    int width;
    int height;

public:
    Grid(int gridWidth, int gridHeight);
    
    void display(int roverX, int roverY);
   
    bool isRock(int row, int col);
   
    bool isBlocked(int x, int y);

    Terrain terrain[10][10];
};


#endif
