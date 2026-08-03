#include "Rover.h"
#include <iostream>
#include "Grid.h"

int main() {
    Rover rover(5, 10);
    char command;


     Grid grid(10, 10);
     grid.display();

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
