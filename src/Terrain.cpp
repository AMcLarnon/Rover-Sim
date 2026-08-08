#include "Terrain.h"

char getTerrainSymbol(TerrainType terrain)
{
    switch (terrain)
    {
        case NORMAL:
            return '.';

        case SAND:
            return '~';

        case ROCKY:
            return '^';

        case GRAVEL:
            return ':';

        case ICE:
            return '_';

        case SLOPE:
            return '/';

        default:
            return '.';
    }
}


int getTerrainBatteryCost(TerrainType terrain)
{
    switch (terrain)
    {
        case NORMAL:
            return 1;

        case SAND:
            return 2;

        case ROCKY:
            return 3;

        case GRAVEL:
            return 2;

        case ICE:
            return 1;

        case SLOPE:
            return 3;

        default:
            return 1;
    }
}