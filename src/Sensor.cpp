#include "Sensor.h"
#include <iostream>

Sensor::Sensor(int sensorRange)
{
    range = sensorRange;
}

void Sensor::scan(
    int roverX,
    int roverY,
    Direction direction,
    Grid& grid,
    int missionX,
    int missionY,
    int stationX,
    int stationY
)

{
    std::cout << "\n===== SENSOR SCAN =====\n";

    (void)direction;

    for (int y = roverY - range; y <= roverY + range; y++)
    {
        for (int x = roverX - range; x <= roverX + range; x++)
        {
            if (x < 1 || x > 10 ||
                y < 1 || y > 10)
            {
                continue;
            }

            if (x == roverX && y == roverY)
            {
                continue;
            }

            std::cout << "("
                      << x
                      << ", "
                      << y
                      << "): ";

            if (grid.isRock(y, x))
            {
                std::cout << "Obstacle";
            }

            else if (x == missionX && y == missionY)
            {
                std::cout << "Mission target";
            }

            else if (x == stationX && y == stationY)
            {
                std::cout << "Recharge station";
            }

            else
            {
                TerrainType terrain = grid.getTerrain(x, y);

                switch (terrain)
                {
                    case NORMAL:
                        std::cout << "Normal terrain";
                        break;

                    case SAND:
                        std::cout << "Sand";
                        break;

                    case ROCKY:
                        std::cout << "Rocky terrain";
                        break;

                    case GRAVEL:
                        std::cout << "Gravel";
                        break;

                    case ICE:
                        std::cout << "Ice";
                        break;

                    case SLOPE:
                        std::cout << "Slope";
                        break;

                    default:
                        std::cout << "Unknown";
                        break;
                }
            }

            std::cout << "\n";
        }
    }

    std::cout << "=======================\n";
}