#include <iostream>

int main()
{
    int battery = 100;
    int xPosition = 0;
    int yPosition = 0;

    char command;

    std::cout << "Rover status:" << std::endl;
    std::cout << "Battery: " << battery << "%" << std::endl;
    std::cout << "Position: (" << xPosition << ", " << yPosition << ")" << std::endl;

    std::cout << "Enter movement command (w/a/s/d): ";
    std::cin >> command;

    if (command == 'w')
    {
        yPosition++;
    }

    if (command == 's')
    {
        yPosition--;
    }

    if (command == 'a')
    {
        xPosition--;
    }

    if (command == 'd')
    {
        xPosition++;
    }

    std::cout << "New position: (" << xPosition << ", " << yPosition << ")" << std::endl;

    return 0;
}