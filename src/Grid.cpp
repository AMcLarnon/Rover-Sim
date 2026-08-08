#include "Grid.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

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
            else
            {
                terrain[row][col] = NORMAL;
            }
        }
    }


    terrain[1][1] = NORMAL;
}


bool Grid::isRock(int row, int col)
{
    return (row == 2 && col == 5) ||
           (row == 4 && col == 7);
}


bool Grid::isBlocked(int x, int y)
{
    return isRock(y, x);
}


int Grid::getBatteryCost(int x, int y)
{
    switch (terrain[y - 1][x - 1])
    {
        case NORMAL:
            return 1;

        case SAND:
            return 2;

        case ROCKY:
            return 3;

        default:
            return 1;
    }
}


void Grid::display(int roverX, int roverY, int missionX, int missionY)
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

            else
            {
                switch (terrain[row - 1][col - 1])
                {
                    case NORMAL:
                        std::cout << ".";
                        break;

                    case SAND:
                        std::cout << "~";
                        break;

                    case ROCKY:
                        std::cout << "^";
                        break;

                    default:
                        std::cout << ".";
                        break;
                }
            }
        }

        std::cout << "\n";
    }
}