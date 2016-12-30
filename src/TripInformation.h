//
// Created by liav on 01/12/16.
//

#ifndef EX11_TRIPINOFRMATION_H
#define EX11_TRIPINOFRMATION_H

#include <iostream>
#include "NodePoint.h"
using namespace std;

class TripInformation {
private:
    int rideId;
    int meterPassed;
    AbstractNode* source;
    AbstractNode* destination;
    int numberOfPassangers;
    double tariff;

public:
    // constructor
    TripInformation (int rideId2, int meterPassed2, AbstractNode* source2,
                     AbstractNode* destination2 ,double tariff2,
                     int pass);
    TripInformation (int rideId2, int numberOfPass, int xStart,
                     int yStart, int xEnd, int yEND
            ,double tariff2, int pass);

    // get and set functions
    int getRideId();

    void setMetersPassed(int meters);
    int getMetersPassed();
    AbstractNode*& getSource();
    AbstractNode*& getDestination();
    void setTariff(double tariff);
    double getTariff();
    ~TripInformation();


};


#endif //EX11_TRIPINOFRMATION_H
