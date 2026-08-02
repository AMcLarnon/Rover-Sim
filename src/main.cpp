#include "Rover.h"
#include <iostream>

int main() {
    Rover rover;
    char command;

    while (true) {
        rover.displayStatus();
        std::cout << "\nEnter command (W/A/S/D, Q to quit): ";
        std::cin >> command;

        if (command == 'w' || command == 'W') {
            rover.moveUp();
        } else if (command == 's' || command == 'S') {
            rover.moveDown();
        } else if (command == 'a' || command == 'A') {
            rover.moveLeft();
        } else if (command == 'd' || command == 'D') {
            rover.moveRight();
        } else if (command == 'q' || command == 'Q') {
            break; 
        } else {
            std::cout << "Invalid command.\n";
        }
    }

    std::cout << "Mission ended." << std::endl;
    return 0;
}
