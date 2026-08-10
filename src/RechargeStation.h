#ifndef RECHARGESTATION_H
#define RECHARGESTATION_H

class RechargeStation
{
private:
    int xPosition;
    int yPosition;

public:
    RechargeStation(int x, int y);
    void setPosition(int x, int y);

    int getX();
    int getY();
};


#endif