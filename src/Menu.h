//
// Created by yoav on 13/12/16.
//

#ifndef EX11_MENU_H
#define EX11_MENU_H


#include "TaxiCenter.h"
#include "Matrix.h"
#include "Socket.h"

/*
 * class name: Menu.
 * the class is in charge of the entire flow of the program.
 *
 */
class Menu {
private:
    void parseInput(string s,string* inputArr);
    // the taxi parses the input received from the user by a delimiter.
    //members.
    TaxiCenter* taxiCenter;
    Matrix* matrix;
    Socket* socket;
public:
    Menu(TaxiCenter*& t, Socket* socket1);
    void getInput();
    void assignTrips();
    void moveDriversInServer();
    void signalClientToDrive();
    void shutDownProgram();
    void getNewCab(int id,int taxiType, int meters, char carMan,char color);
    //the method takes an input from the user line by line and operates the
    // proper mission accordingly.
    void getNewTrip(int id,
                    int startX, int startY,
                    int endX, int endY, int numOfPassangers,
                    double tariff, int timeOfStart);
    void sendProperTaxi(int cabId);
    int receiveNewDriver();
    void initializeObstacles();
    void initializeMatrix();
    ~Menu();

};


#endif //EX11_MENU_H
