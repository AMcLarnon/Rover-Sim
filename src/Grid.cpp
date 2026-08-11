#include "Grid.h"
#include <iostream>
#include <cstdlib>
#include "Terrain.h"


Grid::Grid(int gridWidth, int gridHeight)
{
    width = gridWidth;
    height = gridHeight;

    generateTerrain();
}


void Grid::generateTerrain()
{
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            terrain[row][col] = NORMAL;
        }
    }


    for (int row = 1; row < height - 1; row++)
    {
        for (int col = 1; col < width - 1; col++)
        {
            int chance = rand() % 100;

            if (chance < 15)
            {
                terrain[row][col] = SAND;
            }
            else if (chance < 25)
            {
                terrain[row][col] = ROCKY;
            }
            else if (chance < 35)
            {
                terrain[row][col] = GRAVEL;
            }
            else if (chance < 45)
            {
                terrain[row][col] = ICE;
            }
            else if (chance < 50)
            {
                terrain[row][col] = SLOPE;
            }
            else
            {
                terrain[row][col] = NORMAL;
            }
        }
    }


    terrain[1][1] = NORMAL;
}

TerrainType Grid::getTerrain(int x, int y)
{
    return terrain[y - 1][x - 1];
}

void Grid::generateRocks(int roverX, int roverY,
                         int missionX, int missionY,
                         int stationX, int stationY)
{
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            rocks[row][col] = false;
        }
    }

    int rocksToPlace = 2;
    int placed = 0;

    while (placed < rocksToPlace)
    {
        int row = rand() % height;
        int col = rand() % width;

        int x = col + 1;
        int y = row + 1;

        if ((x == roverX && y == roverY) ||
            (x == missionX && y == missionY) ||
            (x == stationX && y == stationY))
        {
            continue;
        }

        if (!rocks[row][col])
        {
            rocks[row][col] = true;
            placed++;
        }
    }
}

bool Grid::isRock(int row, int col)
{
    return rocks[row - 1][col - 1];
}


bool Grid::isBlocked(int x, int y)
{
    return isRock(y, x);
}


int Grid::getBatteryCost(int x, int y)
{
    return getTerrainBatteryCost(
        terrain[y - 1][x - 1]
    );
}


void Grid::display(
    int roverX,
    int roverY,
    int missionX,
    int missionY,
    int stationX,
    int stationY)
{
    for (int row = 0; row <= height + 1; ++row)
    {
        for (int col = 0; col <= width + 1; ++col)
        {
            if (row == 0 || row == height + 1 ||
                col == 0 || col == width + 1)
            {
                std::cout << "#";
            }

            else if (col == roverX && row == roverY)
            {
                std::cout << "R";
            }

            else if (col == missionX && row == missionY)
            {
                std::cout << "M";
            }

            else if (isRock(row, col))
            {
                std::cout << "O";
            }
            else if (col == stationX && row == stationY)
            {
                std::cout << "C";
            }
            else
            {
                std::cout << getTerrainSymbol(
                    terrain[row - 1][col - 1]
                );
            }
        }

        std::cout << "\n";
    }
}