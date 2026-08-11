#ifndef SENSOR_H
#define SENSOR_H

#include "Grid.h"
#include "Rover.h"

class Sensor
{
private:
    int range;

public:
    Sensor(int sensorRange);

    void scan(
        int roverX,
        int roverY,
        Direction direction,
        Grid& grid,
        int missionX,
        int missionY,
        int stationX,
        int stationY
    );
};

#endif