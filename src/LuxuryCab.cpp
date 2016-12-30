//
// Created by yoav on 02/12/16.
//
#include "AbstractCab.h"
#include "LuxuryCab.h"
//constructor.
LuxuryCab::LuxuryCab(int cabId1 ,int meters1, char manufacturer1,
                     char color1, AbstractNode*& l){
    cabId=cabId1;
    meters=meters1;
    manufacturer = manufacturer1;
    color=color1;
    coefficient=2;
    type =2;
    location = l;
    speed =2;
    navigator=new Bfs();
}
//getters and setters.
void LuxuryCab::setSpeed(int speed1){
    speed=speed1;
}
int LuxuryCab::getSpeed(){
    return speed;
}
float LuxuryCab::getTariff(){
    return coefficient;
}
int LuxuryCab:: moveOneStep(){
    if(shortestPath->size()>=2){
        shortestPath->pop();
        location=shortestPath->top();
        shortestPath->pop();
        return 2;
    } else {
        location=shortestPath->top();
        shortestPath->pop();
        return 1;
    }
}

int LuxuryCab::getType() {
    return 2;
}
AbstractNode* LuxuryCab::getLocation() {
    return location;
}
int LuxuryCab::getCabId() {
    return cabId;
}

 void LuxuryCab::setShortestPath(stack<AbstractNode*>& path){
    shortestPath= &path;
}

Bfs*& LuxuryCab::getNavigator() {
    return navigator;
}

void LuxuryCab::addMetersPassed(int meters1) {
    meters+=meters1;
}

int LuxuryCab::getMeterPassed() {
    return meters;
}
LuxuryCab::~LuxuryCab(){
    delete(navigator);
};//destructor.