#include "Navigation.h"
#include <iostream>

Navigation::Navigation()
{
}

void Navigation::checkNeighbours(
    int x,
    int y,
    Grid& grid
)
{
    std::cout << "\n===== NAVIGATION =====\n";

    // Up
    if (!grid.isBlocked(x, y - 1))
    {
        std::cout << "Up: valid\n";
    }
    else
    {
        std::cout << "Up: blocked\n";
    }

    // Right
    if (!grid.isBlocked(x + 1, y))
    {
        std::cout << "Right: valid\n";
    }
    else
    {
        std::cout << "Right: blocked\n";
    }

    // Down
    if (!grid.isBlocked(x, y + 1))
    {
        std::cout << "Down: valid\n";
    }
    else
    {
        std::cout << "Down: blocked\n";
    }

    // Left
    if (!grid.isBlocked(x - 1, y))
    {
        std::cout << "Left: valid\n";
    }
    else
    {
        std::cout << "Left: blocked\n";
    }

    std::cout << "======================\n";
}