#include "Rover.h"
#include <iostream>


Rover::Rover(int startX, int startY)
    : xPosition(startX),
      yPosition(startY),
      battery(100),
      direction(NORTH)
{
}

void Rover::reset(int startX, int startY)
{
    xPosition = startX;
    yPosition = startY;
    battery = 100;
    direction = NORTH;
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


void Rover::turnRight()
{
    switch (direction)
    {
        case NORTH:
            direction = EAST;
            break;

        case EAST:
            direction = SOUTH;
            break;

        case SOUTH:
            direction = WEST;
            break;

        case WEST:
            direction = NORTH;
            break;
    }
}

void Rover::turnLeft()
{
    switch (direction)
    {
        case NORTH:
            direction = WEST;
            break;

        case WEST:
            direction = SOUTH;
            break;

        case SOUTH:
            direction = EAST;
            break;

        case EAST:
            direction = NORTH;
            break;
    }
}

void Rover::moveForward(int gridWidth, int gridHeight)
{
    int oldX = xPosition;
    int oldY = yPosition;

    switch (direction)
    {
        case NORTH:
            moveUp(gridHeight);
            break;

        case EAST:
            moveRight(gridWidth);
            break;

        case SOUTH:
            moveDown(gridHeight);
            break;

        case WEST:
            moveLeft(gridWidth);
            break;
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

int Rover::getBattery()
{
    return battery;
}

Direction Rover::getDirection()
{
    return direction;
}


void Rover::useBattery(int amount)
{
    battery -= amount;

    if (battery < 0)
    {
        battery = 0;
    }
}

void Rover::displayStatus()
{

    if (battery <= 20)
{
    std::cout << "Warning: Low battery!\n";
}

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

    std::cout << "Direction: ";


switch (direction)
{
    case NORTH:
        std::cout << "NORTH";
        break;

    case EAST:
        std::cout << "EAST";
        break;

    case SOUTH:
        std::cout << "SOUTH";
        break;

    case WEST:
        std::cout << "WEST";
        break;
}

std::cout << std::endl;
}