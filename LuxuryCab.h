//
// Created by yoav on 02/12/16.
//

#ifndef EX11_LUXURYCAB_H
#define EX11_LUXURYCAB_H

#include "AbstractCab.h"
#include <string>
using namespace std;
/*
 * clasas name: luxuryCab which inherits from AbstractCab.
 */
class LuxuryCab: public AbstractCab {
public:
    //constructor.
    LuxuryCab(int cabID1 ,int kilometers1,char manufacturer1, char color1, AbstractNode*& l);
    //getters and setters.
    void setSpeed(int speed1);
    int getSpeed();
    float getTariff();
    int getType();
    AbstractNode* getLocation();
    int getCabId();
    Bfs*& getNavigator();
    void setShortestPath(stack<AbstractNode*>& path);
    //sets a stack got as a reference as the path.
    // the method that moves the cab.
    int moveOneStep();
    void addMetersPassed(int meters);
    int getMeterPassed();
    ~LuxuryCab();//destructor.

};


#endif //EX11_LUXURYCAB_H
