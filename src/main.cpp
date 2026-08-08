#include "Rover.h"
#include "Grid.h"
#include "Mission.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0));

    Rover rover(2, 2);
    char command;

    Grid grid(10, 10);

    Mission mission(0, 0);

    int missionX;
    int missionY;

    do
    {
        missionX = rand() % 10 + 1;
        missionY = rand() % 10 + 1;

    } while (
        (missionX == rover.getX() &&
         missionY == rover.getY()) ||

        grid.isBlocked(missionX, missionY)
    );

    mission.setTarget(missionX, missionY);


    while (true)
    {
        grid.display(
            rover.getX(),
            rover.getY(),
            mission.getX(),
            mission.getY()
        );


        std::cout << "\n==============================\n";
        std::cout << "MISSION\n";
        std::cout << "Reach (" 
                  << mission.getX()
                  << ", "
                  << mission.getY()
                  << ")\n";
        std::cout << "==============================\n";


        rover.displayStatus();


        std::cout << "\nEnter command (F/L/R, Q to quit, X to reset): ";
        std::cin >> command;


        if (command == 'l' || command == 'L')
        {
            rover.turnLeft();
        }

        else if (command == 'x' || command == 'X')
{
    rover.reset(2, 2);

    grid.generateTerrain();

    do
    {
        missionX = rand() % 10 + 1;
        missionY = rand() % 10 + 1;

    } while (
        (missionX == rover.getX() &&
         missionY == rover.getY()) ||
        grid.isBlocked(missionX, missionY)
    );

    mission.reset(missionX, missionY);

    std::cout << "\nSimulator reset!\n";
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


                    // Only drain battery if rover actually moved
                    if (rover.getX() != oldX ||
                        rover.getY() != oldY)
                    {
                        rover.useBattery(cost);
                    }


                    mission.checkCompletion(
                        rover.getX(),
                        rover.getY()
                    );


                    if (mission.isComplete())
                    {
                        std::cout << "\n==============================\n";
                        std::cout << "MISSION COMPLETE!\n";
                        std::cout << "Target reached successfully.\n";
                        std::cout << "==============================\n";

                        break;
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