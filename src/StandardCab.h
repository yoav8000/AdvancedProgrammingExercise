//
// Created by yoav on 02/12/16.
//

#ifndef EX11_STANDARDCAB_H
#define EX11_STANDARDCAB_H


#include "AbstractCab.h"
#include <string>
using namespace std;
/*
 * class name: StandardCab that inherits from AbstractCab.
 */
class StandardCab: public AbstractCab {
public:
    //constructor.
    StandardCab(int cabId1 ,int kilometers1,char manufacturer1, char color1, AbstractNode*& l);
    // getters and setters.
    void setSpeed(int speed1);
    int getSpeed();
    float getTariff();
    int getType();
    AbstractNode* getLocation();
    int moveOneStep();//the method that moves the cab.
    int getCabId();
    Bfs*& getNavigator();
    void setShortestPath(stack<AbstractNode*>& path);
    void addMetersPassed(int meters);
    int getMeterPassed();
    ~StandardCab();

};


#endif //EX11_STANDARDCAB_H
