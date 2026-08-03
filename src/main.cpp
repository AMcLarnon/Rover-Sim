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
        rover.moveUp(10);
    } else if (command == 's' || command == 'S') {
        rover.moveDown(10);
    } else if (command == 'a' || command == 'A') {
        rover.moveLeft(10);
    } else if (command == 'd' || command == 'D') {
        rover.moveRight(10);
    } else if (command == 'q' || command == 'Q') {
        break; 
    } else {
        std::cout << "Invalid command.\n";
    }
}

    std::cout << "Mission ended." << std::endl;
    return 0;
}
