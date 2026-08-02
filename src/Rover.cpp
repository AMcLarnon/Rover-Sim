#include "Rover.h"
#include <iostream>


Rover::Rover()
{
    xPosition = 0;
    yPosition = 0;
    battery = 100;
}


void Rover::moveUp()
{
    yPosition++;
}


void Rover::moveDown()
{
    yPosition--;
}


void Rover::moveLeft()
{
    xPosition--;
}


void Rover::moveRight()
{
    xPosition++;
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