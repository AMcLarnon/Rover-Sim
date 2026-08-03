#include "Rover.h"
#include <iostream>


Rover::Rover(int startX, int startY)
    : xPosition(startX), yPosition(startY), battery(100)
{
}


void Rover::moveUp(int gridHeight)
{
    if (yPosition > 1)
    {
        yPosition--;
    }
}


void Rover::moveDown(int gridHeight)
{
    if (yPosition < gridHeight)
    {
        yPosition++;
    }
}


void Rover::moveLeft(int gridWidth)
{
    if (xPosition > 1)
    {
        xPosition--;
    }
}


void Rover::moveRight(int gridWidth)
{
    if (xPosition < gridWidth)
    {
        xPosition++;
    }
}


int Rover::getX()
{
    return xPosition;
}


int Rover::getY()
{
    return yPosition;
}

void Rover::displayStatus()
{
    std::cout << "Position: (" 
              << xPosition 
              << ", " 
              << yPosition 
              << ")" 
              << std::endl;

    std::cout << "Battery: "
              << battery
              << "%"
              << std::endl;
}