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

    void moveUp(int gridHeight);
    void moveDown(int gridHeight);
    void moveLeft(int gridWidth);
    void moveRight(int gridWidth);
  
    int getX();
    int getY();

    void displayStatus();
};

#endif