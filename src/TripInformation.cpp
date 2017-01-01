//
// Created by liav on 01/12/16.
//

#include "TripInformation.h"

TripInformation::TripInformation(){ //for debugging
    rideId = 0;
    source = new NodePoint(0,0);
    destination = new NodePoint(0,0);
    tariff = 0;
    numberOfPassangers=0;
    timeOfStart=0;
    meterPassed = 0;
}

TripInformation::TripInformation(int rideId2, int meterPassed2, AbstractNode* source2,
                                 AbstractNode* destination2 , double tariff2, int pass){
    rideId = rideId2;
    meterPassed = 0;
    source = source2;
    destination = destination2;
    tariff = tariff2;
    numberOfPassangers=pass;

}
TripInformation::TripInformation(int rideId2, int xStart, int yStart, int xEnd, int yEnd,
                                  int pass, double tariff2, int timeOfStart1){
    rideId = rideId2;
    source = new NodePoint(xStart,yStart);
    destination = new NodePoint(xEnd,yEnd);
    tariff = tariff2;
    numberOfPassangers=pass;
    timeOfStart=timeOfStart1;
    meterPassed = 0;
}



void TripInformation::setMetersPassed(int meters){
    meterPassed=meters;
}
int TripInformation::getMetersPassed(){
    return meterPassed;
}

AbstractNode*& TripInformation::getSource(){
    return  source;
}

AbstractNode*& TripInformation::getDestination(){
    return  destination;
}

void TripInformation::setTariff(double tariff1){
    tariff= tariff1;
}

double TripInformation::getTariff(){
    return tariff;
}
int TripInformation:: getRideId(){
    return rideId;
};

 TripInformation::~TripInformation() {
     delete(source);
     delete(destination);
 }