//
// Created by yoav on 02/12/16.
//

#ifndef EX11_ABSTRACTCAB_H
#define EX11_ABSTRACTCAB_H

#include <string>
#include <stack>
#include "NodePoint.h"
#include "Bfs.h"

using namespace std;



/*
 * clas name: AbstractCab.
 * the class is and abstract class which 2 other classes implements its method.
 */

class AbstractCab {



protected:
    //members
    stack <AbstractNode*>* shortestPath;
    Bfs* navigator;
    int cabId;
    int type;
    int meters;
    char manufacturer;
    char color;
    float coefficient;
    int speed;
    AbstractNode* location;
    virtual void setSpeed(int speed1) =0;

public:
    //getters and setters.
    virtual int getType()=0;
    virtual AbstractNode* getLocation()=0;
    virtual int getCabId()=0;
    virtual int getMeterPassed()=0;
    virtual void setShortestPath(stack<AbstractNode*>& path)=0;
    virtual Bfs*& getNavigator()=0;

    virtual int moveOneStep() =0;//returns the amount of steps did and moves the cab.
    virtual void addMetersPassed(int meters)=0;// add meters to the meters member.
    virtual ~AbstractCab()=0;//destructor.


};


#endif //EX11_ABSTRACTCAB_H
