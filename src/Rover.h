#ifndef ROVER_H
#define ROVER_H

class Rover
{
private:
    int xPosition;
    int yPosition;
    int battery;

public:
    Rover();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    void displayStatus();
};

#endif