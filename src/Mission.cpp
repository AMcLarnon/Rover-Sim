#include "Mission.h"


Mission::Mission(int x, int y)
{
    targetX = x;
    targetY = y;
    completed = false;
}

void Mission::reset(int x, int y)
{
    targetX = x;
    targetY = y;
    completed = false;
}

int Mission::getX()
{
    return targetX;
}


int Mission::getY()
{
    return targetY;
}


bool Mission::isComplete()
{
    return completed;
}


void Mission::checkCompletion(int roverX, int roverY)
{
    if (roverX == targetX && roverY == targetY)
    {
        completed = true;
    }
}

void Mission::setTarget(int x, int y)
{
    targetX = x;
    targetY = y;
    completed = false;
}