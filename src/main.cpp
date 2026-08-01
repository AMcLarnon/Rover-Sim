#include <iostream>

int main()
{
    int battery = 100;
    int xPosition = 0;
    int yPosition = 0;

    std::cout << "Rover status:" << std::endl;
    std::cout << "Battery: " << battery << "%" << std::endl;
    std::cout << "Position: (" << xPosition << ", " << yPosition << ")" << std::endl;

    return 0;
}