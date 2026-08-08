#ifndef MISSION_H
#define MISSION_H

class Mission
{
private:
    int targetX;
    int targetY;
    bool completed;

public:
    Mission(int x, int y);

    int getX();
    int getY();

    bool isComplete();

    void checkCompletion(int roverX, int roverY);
    void setTarget(int x, int y);
    void reset(int x, int y);
};

#endif