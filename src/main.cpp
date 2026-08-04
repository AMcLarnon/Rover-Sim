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

        std::cout << "\nEnter command (W/A/S/D, Q to quit): ";
        std::cin >> command;

        if (command == 'w' || command == 'W') {

            if (!grid.isBlocked(rover.getX(), rover.getY() - 1)) {
                rover.moveUp(10);
            } else {
                std::cout << "Movement blocked.\n";
            }

        } else if (command == 's' || command == 'S') {

            if (!grid.isBlocked(rover.getX(), rover.getY() + 1)) {
                rover.moveDown(10);
            } else {
                std::cout << "Movement blocked.\n";
            }

        } else if (command == 'a' || command == 'A') {

            if (!grid.isBlocked(rover.getX() - 1, rover.getY())) {
                rover.moveLeft(10);
            } else {
                std::cout << "Movement blocked.\n";
            }

        } else if (command == 'd' || command == 'D') {

            if (!grid.isBlocked(rover.getX() + 1, rover.getY())) {
                rover.moveRight(10);
            } else {
                std::cout << "Movement blocked.\n";
            }

        } else if (command == 'q' || command == 'Q') {
            break;
        } else {
            std::cout << "Invalid command.\n";
        }
    }

    std::cout << "Mission ended." << std::endl;
    return 0;
}