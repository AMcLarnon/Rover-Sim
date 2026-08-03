#include "Rover.h"
#include <iostream>


Rover::Rover(int startX, int startY)
    : xPosition(startX), yPosition(startY), battery(100)
{
}


void Rover::moveUp()
{
    yPosition--;
}


void Rover::moveDown()
{
    yPosition++;
}


void Rover::moveLeft()
{
    xPosition--;
}


void Rover::moveRight()
{
    xPosition++;
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