#include "RechargeStation.h"

RechargeStation::RechargeStation(int x, int y)
{
    xPosition = x;
    yPosition = y;
}

int RechargeStation::getX()
{
    return xPosition;
}

int RechargeStation::getY()
{
    return yPosition;
}

void RechargeStation::setPosition(int x, int y)
{
    xPosition = x;
    yPosition = y;
}