//
// Created by yoav on 13/12/16.
//

#include <cstring>
#include <sstream>
#include "Menu.h"
#include "StandardCab.h"
#include "LuxuryCab.h"


/*
 * Class name: Menu
 * the class is in charge of the entire input recieving and the entire flow of the program.
 */
Menu::Menu(TaxiCenter*& t) {
    taxiCenter =t;
}
/*
 * the method gets a string and an array of strings, and returns nothing.
 * the method parses the string into strings with the delimiter of "," and puts each
 * token in its place in the array.
 */
    void Menu::parseInput(string s,string* inputArr) {
    int i=0;
    istringstream iss(s);
    string token;
    while (getline(iss, token, ',')) {
        inputArr[i++] = token;
    }
}


/*
 * the method is in charge of receiving the input from the user and create
 * the right objects accordingly
 * then it activates the moving method of each object according to the input.
 */
void Menu::getInput(){
    int x,y, numberOfObstacles=0;
    cin>>x>>y;// gets the size of the matrix.
    matrix = new Matrix(x,y);//create the proper matrix with the right measurments.
    cin>>numberOfObstacles;//gets the amount of obstacles.
    while (numberOfObstacles){//get each obstacle.
        int xObstacle, yObstacle;
        char dummy;
        cin>>xObstacle>>dummy>>yObstacle;
        NodePoint point(xObstacle,yObstacle);//get the proper node from the matrix.
        matrix->getNode((&point))->setIsObstacle();
        numberOfObstacles--;
    }
    int switchFlag=0;
    int choice;
    cin>>choice;//gets the choice from the user.
    int flag =0;
    while(flag!=1) {// the loop is active until the user hits the 7 key.
        if(switchFlag !=0) {// the input receiving from the 2nd iteration.
            cin >> choice;
        }
        switch (choice) {
            case 1: {// add Driver.
                switchFlag = 1;
                string input;
                string inputArr[10];
                int age, id, experience, vehiclId;;
                string status;
                cin >> input;
                parseInput(input, inputArr);
                id = atoi(inputArr[0].c_str());
                age = atoi(inputArr[1].c_str());
                status = inputArr[2];
                experience = atoi(inputArr[3].c_str());
                vehiclId = atoi(inputArr[4].c_str());
                Driver *driver = new Driver(id, age, *status.c_str(), vehiclId, experience);
                //create a new driver.
                taxiCenter->addDriver(driver);//add the driver to the taxicenter.
                break;
            }
            case 2: {// add trip.
                switchFlag = 1;
                string input;
                string inputArr[10];
                int id, startX, startY, endX, endY, numOfPassangers;
                double tariff;
                cin >> input;
                parseInput(input, inputArr);
                id = atoi(inputArr[0].c_str());
                startX = atoi(inputArr[1].c_str());
                startY = atoi(inputArr[2].c_str());
                endX = atoi(inputArr[3].c_str());
                endY = atoi(inputArr[4].c_str());
                numOfPassangers = atoi(inputArr[5].c_str());
                tariff = atof(inputArr[6].c_str());
                TripInformation *tripInformation = new TripInformation(id, 0,
                                                                       startX, startY,
                                                                       endX, endY, tariff,
                                                                       numOfPassangers);
                //create a new trip.
                taxiCenter->addTrip(tripInformation);// add the trip to the taxicenter.
                break;
            }
            case 3: {// add Cab.
                switchFlag = 1;
                string input;
                string inputArr[10];
                int id, taxiType;
                string carMan, color;
                cin >> input;
                parseInput(input, inputArr);
                id = atoi(inputArr[0].c_str());
                taxiType = atoi(inputArr[1].c_str());
                carMan = inputArr[2];
                color = inputArr[3];
                if (taxiType == 1) {
                    NodePoint* n = new NodePoint(0,0);
                    AbstractNode* n1 = matrix->getNode(n);
                    delete n;
                    //create the new cab.
                    StandardCab *standardCab = new StandardCab(id, 0, *carMan.c_str(),
                                                               *color.c_str(),n1);
                    taxiCenter->addCab((AbstractCab *&) standardCab);
                    //add the cab to the taxicenter.
                } else if (taxiType == 2) {
                    NodePoint* n = new NodePoint(0,0);
                    AbstractNode* n1 = matrix->getNode(n);
                    delete n;
                    LuxuryCab *luxuryCab = new LuxuryCab(id, 0, *carMan.c_str(),
                                                         *color.c_str(),n1);
                    taxiCenter->addCab((AbstractCab *&) luxuryCab);
                }
                break;
            }
            case 4: {// get the location of a certain driver.
                switchFlag = 1;
                string input;
                string inputArr[10];
                int id;
                cin >> input;
                parseInput(input, inputArr);
                id = atoi(inputArr[0].c_str());
                NodePoint *location = (NodePoint *) taxiCenter->getDriverLocation(id);
                cout << *location ;
                break;
            }
            case 6: {// notify the taxis to start drive.
                map<int, Driver *>::iterator it;//matches drivers and cabs.
                for (it = taxiCenter->getDriversMap().begin(); it !=
                        taxiCenter->getDriversMap().end(); it++) {
                    int cabid = it->second->getVehicleId();
                    for (int i = 0; i < taxiCenter->getCabVector().size(); i++) {
                        if (taxiCenter->getCabVector()[i]->getCabId() == cabid) {
                            it->second->setCab(taxiCenter->getCabVector()[i]);
                        }
                    }
                }
                unsigned long numOfTrips = 0;//check if there are more trips than taxis or not.
                if (taxiCenter->getTripDeque().size() > taxiCenter->getCabVector().size()) {
                    numOfTrips = taxiCenter->getCabVector().size();
                } else {
                    numOfTrips = taxiCenter->getTripDeque().size();
                }

                for (unsigned long i = 0; i < numOfTrips; i++) {//matches trips to drivers.
                    for (it = taxiCenter->getDriversMap().begin(); it !=
                            taxiCenter->getDriversMap().end(); it++) {
                        if (it->second->getVehicleId() == taxiCenter->
                                getCabVector()[i]->getCabId()) {
                            it->second->setAvailable(false);
                            it->second->setCurrentTrip(taxiCenter->getTripDeque().front());
                            taxiCenter->getTripDeque().pop_front();
                            it->second->startDriving(matrix);//notify each driver to drive.
                        }
                    }
                }
                break;
            }
            case 7: {// delete all the objects and quit from the program.
                map<int, Driver *>::iterator it;//matches drivers and cabs.
                for (it = taxiCenter->getDriversMap().begin(); it !=
                        taxiCenter->getDriversMap().end(); it++) {
                    delete (it->second);
                }

                delete (matrix);
                for(unsigned long i=0;i<taxiCenter->getCabVector().size();i++) {
                    delete (taxiCenter->getCabVector()[i]);
                    //check the erase.
                }
                flag=1;
                break;
            }
            default: {
                switchFlag=1;
                cout << "wrong input"<<endl;
            }
        }
    }
}


Menu::~Menu() {};