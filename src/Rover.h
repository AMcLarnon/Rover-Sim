#ifndef ROVER_H
#define ROVER_H

enum Direction
{
    NORTH,
    EAST,
    SOUTH,
    WEST
};

class Rover
{
private:
    int xPosition;
    int yPosition;
    int battery;

    Direction direction;
public:
    Rover(int startX, int startY);

    void moveUp(int gridHeight);
    void moveDown(int gridHeight);
    void moveLeft(int gridWidth);
    void moveRight(int gridWidth);
    void turnLeft();
    void turnRight();
    void moveForward(int gridWidth, int gridHeight);
    void useBattery(int amount);
    void reset(int startX, int startY);

    Direction getDirection();
    int getBattery();
  
    int getX();
    int getY();

    void displayStatus();
};

#endif