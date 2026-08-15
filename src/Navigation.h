#ifndef NAVIGATION_H
#define NAVIGATION_H

#include "Grid.h"

class Navigation
{
public:
    Navigation();

    void checkNeighbours(
        int x,
        int y,
        Grid& grid
    );
};

#endif