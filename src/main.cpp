
#include "Rover.h"
#include "Grid.h"
#include "Mission.h"
#include "RechargeStation.h"
#include "Sensor.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0));

    Rover rover(2, 2);
    char command;

    Grid grid(10, 10);
    Sensor sensor(2);

    Mission mission(0, 0);

    int missionX;
    int missionY;

    int stationX;
    int stationY;

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

    do
    {
        stationX = rand() % 10 + 1;
        stationY = rand() % 10 + 1;

    } while (
        (stationX == rover.getX() &&
         stationY == rover.getY()) ||

        (stationX == mission.getX() &&
         stationY == mission.getY()) ||

        grid.isBlocked(stationX, stationY)
    );

    RechargeStation station(stationX, stationY);
    grid.generateRocks(
    rover.getX(),
    rover.getY(),
    mission.getX(),
    mission.getY(),
    station.getX(),
    station.getY()
);


    while (true)
    {

        grid.display(
            rover.getX(),
            rover.getY(),
            mission.getX(),
            mission.getY(),
            station.getX(),
            station.getY()
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


        std::cout << "\nEnter command "
                  << "(F/L/R, Q to quit, X to reset, C to recharge, S to scan): ";

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


            do
            {
                stationX = rand() % 10 + 1;
                stationY = rand() % 10 + 1;

            } while (
                (stationX == rover.getX() &&
                 stationY == rover.getY()) ||

                (stationX == mission.getX() &&
                 stationY == mission.getY()) ||

                grid.isBlocked(stationX, stationY)
            );

            station.setPosition(stationX, stationY);

            grid.generateRocks(
    rover.getX(),
    rover.getY(),
    mission.getX(),
    mission.getY(),
    station.getX(),
    station.getY()
);

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


        else if (command == 'c' || command == 'C')
        {
            if (rover.getX() == station.getX() &&
                rover.getY() == station.getY())
            {
                rover.recharge();

                std::cout << "Battery fully recharged!\n";
            }
            else
            {
                std::cout << "No recharge station here.\n";
            }
        }

        else if (command == 's' || command == 'S')
{
    sensor.scan(
    rover.getX(),
    rover.getY(),
    rover.getDirection(),
    grid,
    mission.getX(),
    mission.getY(),
    station.getX(),
    station.getY()
);

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
