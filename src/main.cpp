#include "Rover.h"
#include <iostream>
#include "Grid.h"

int main() {
    Rover rover(2, 2);
    char command;

    Grid grid(10, 10);

    while (true) {
        grid.display(rover.getX(), rover.getY());

        rover.displayStatus();
        

        std::cout << "\nEnter command (F/L/R, Q to quit): ";
        std::cin >> command;


if (command == 'l' || command == 'L') {

    rover.turnLeft();

} else if (command == 'r' || command == 'R') {

    rover.turnRight();

} else if (command == 'f' || command == 'F')
{
    if (rover.getBattery() <= 0)
    {
        std::cout << "Battery depleted. Rover cannot move.\n";
    }
    else
    {

    int nextX = rover.getX();
    int nextY = rover.getY();

    if (rover.getDirection() == NORTH) {
        nextY--;
    }
    else if (rover.getDirection() == EAST) {
        nextX++;
    }
    else if (rover.getDirection() == SOUTH) {
        nextY++;
    }
    else if (rover.getDirection() == WEST) {
        nextX--;
    }

    if (!grid.isBlocked(nextX, nextY)) {
        rover.moveForward(10, 10);
    }
    else {
        std::cout << "Movement blocked.\n";
    }
    }

} else if (command == 'q' || command == 'Q') {

    break;

} else {

    std::cout << "Invalid command.\n";

        } 
    } 

} 