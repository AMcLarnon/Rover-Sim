#ifndef GRID_H
#define GRID_H
#include "Terrain.h"

class Grid

{
private:
    int width;
    int height;

    TerrainType terrain[10][10];
    bool rocks[10][10];

public:
    Grid(int gridWidth, int gridHeight);

    void display(int roverX, int roverY,
             int missionX, int missionY,
             int stationX, int stationY);

    bool isRock(int row, int col);

    bool isBlocked(int x, int y);

    void generateTerrain();

    int getBatteryCost(int x, int y);

    void generateRocks(int roverX, int roverY,
                   int missionX, int missionY,
                   int stationX, int stationY);

    TerrainType getTerrain(int x, int y);
};

#endif