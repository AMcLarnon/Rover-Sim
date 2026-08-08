#ifndef TERRAIN_H
#define TERRAIN_H

enum TerrainType
{
    NORMAL,
    SAND,
    ROCKY,
    GRAVEL,
    ICE,
    SLOPE
};

char getTerrainSymbol(TerrainType terrain);
int getTerrainBatteryCost(TerrainType terrain);

#endif