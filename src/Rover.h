#ifndef ROVER_H
#define ROVER_H

class Rover
{
private:
    int xPosition;
    int yPosition;
    int battery;

public:
    Rover(int startX, int startY);

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
  
    int getX();
    int getY();

    void displayStatus();
};

#endif