//
// Created by yoav on 02/12/16.
//

#include "StandardCab.h"
//constructor.
StandardCab::StandardCab(int cabId1,int meters1, char manufacturer1,
                         char color1,AbstractNode*& l){
 cabId=cabId1;
 type=1;
 meters=meters1;
 manufacturer = manufacturer1;
 color=color1;
 coefficient=1;
 location = l;
 speed=1;
 navigator=new Bfs();

}
//getters and setters.
 void StandardCab::setSpeed(int speed1){
  speed =speed1;
 }
int StandardCab::getSpeed(){
 return speed;
}

float StandardCab::getTariff(){
 return coefficient;
}

int StandardCab::getType() {
 return type;
}
AbstractNode* StandardCab::getLocation() {
 return location;
}

int StandardCab::getCabId() {
    return cabId;
}

int StandardCab:: moveOneStep(){
  location = shortestPath->top();
  shortestPath->pop();
 return 1;
}// the method that moves the cab.

void StandardCab::setShortestPath(stack<AbstractNode*>& path){
 shortestPath=&path;
}

Bfs*& StandardCab::getNavigator() {
 return navigator;
}


void StandardCab::addMetersPassed(int meters1) {
 meters+=meters1;
}
int StandardCab::getMeterPassed() {
 return meters;
}

StandardCab::~StandardCab() {
 delete(navigator);
};//destructor.
