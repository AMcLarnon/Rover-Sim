#include "Rover.h"
#include "Grid.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0));

    Rover rover(2, 2);
    char command;

    Grid grid(10, 10);

    int missionX;
    int missionY;

    do
    {
        missionX = rand() % 10 + 1;
        missionY = rand() % 10 + 1;
    }
    while (
        (missionX == rover.getX() &&
         missionY == rover.getY()) ||

        grid.isBlocked(missionX, missionY)
    );


    while (true)
    {
        grid.display(
            rover.getX(),
            rover.getY(),
            missionX,
            missionY
        );

        rover.displayStatus();

        std::cout << "\n==============================\n";
        std::cout << "MISSION\n";
        std::cout << "Reach (" << missionX << ", " << missionY << ")\n";
        std::cout << "==============================\n";


        std::cout << "\nEnter command (F/L/R, Q to quit): ";
        std::cin >> command;


        if (command == 'l' || command == 'L')
        {
            rover.turnLeft();
        }

        else if (command == 'r' || command == 'R')
        {
            rover.turnRight();
        }

        else if (command == 'f' || command == 'F')
        {
            if (rover.getBattery() <= 0)
            {
                std::cout << "Battery depleted. Rover cannot move.\n";
            }
            else
            {
                int nextX = rover.getX();
                int nextY = rover.getY();


                if (rover.getDirection() == NORTH)
                {
                    nextY--;
                }
                else if (rover.getDirection() == EAST)
                {
                    nextX++;
                }
                else if (rover.getDirection() == SOUTH)
                {
                    nextY++;
                }
                else if (rover.getDirection() == WEST)
                {
                    nextX--;
                }


                if (!grid.isBlocked(nextX, nextY))
                {
                    int oldX = rover.getX();
                    int oldY = rover.getY();

                    int cost = grid.getBatteryCost(nextX, nextY);

                    rover.moveForward(10, 10);


                    if (rover.getX() != oldX ||
                        rover.getY() != oldY)
                    {
                        rover.useBattery(cost);


                        if (rover.getX() == missionX &&
                            rover.getY() == missionY)
                        {
                            std::cout << "\n==============================\n";
                            std::cout << "MISSION COMPLETE!\n";
                            std::cout << "Target reached successfully.\n";
                            std::cout << "==============================\n";

                            break;
                        }
                    }
                }
                else
                {
                    std::cout << "Movement blocked.\n";
                }
            }
        }

        else if (command == 'q' || command == 'Q')
        {
            break;
        }

        else
        {
            std::cout << "Invalid command.\n";
        }
    }


    std::cout << "Mission ended." << std::endl;

    return 0;
}