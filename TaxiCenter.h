//
// Created by yoav on 02/12/16.
//

#ifndef EX11_TAXICENTER_H
#define EX11_TAXICENTER_H

#include <map>
#include <string>
#include "Driver.h"
#include "NodePoint.h"
#include "TripInformation.h"
#include "AbstractCab.h"
#include<list>
#include <vector>

using namespace std;
/*
 * class name: TaxiCenter.
 * the class controls the entire taxis and trips.
 */
class TaxiCenter {
private:
    //members.
map<int,Driver*> driversMap;//done.
deque<TripInformation*> tripDeque;//done.
  //  map<int, AbstractCab*> cabsMap;
    vector<AbstractCab*> cabVector;

public:
    TaxiCenter();//constructor.
    void answerCalls();//a method that gets new trip.
    void addDriver(Driver*& driver);//a method that adds driver.
    void addTrip(TripInformation*& trip);// a method that add a trip.
    void addCab(AbstractCab*& abstractCab);// a method that adds a cab.
    map<int,Driver*>& getDriversMap();// a method that returns a map of the drivers.
    deque<TripInformation*>& getTripDeque();// a method that returns a deque of trips.
    vector<AbstractCab*>& getCabVector();// a method that returns a list of cabs.
    AbstractNode* getDriverLocation(int id);
    ~TaxiCenter();

};


#endif //EX11_TAXICENTER_H
