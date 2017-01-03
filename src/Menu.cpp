//
// Created by yoav on 13/12/16.
//

#include <cstring>
#include <sstream>
#include "Menu.h"
#include "StandardCab.h"
#include "LuxuryCab.h"
#include <iostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/export.hpp>
#include "Socket.h"
#include "Udp.h"
#include "Driver.h"
#include "StandardCab.h"
#include "LuxuryCab.h"
#include "TaxiCenter.h"


/*
 * Class name: Menu
 * the class is in charge of the entire input recieving and the entire flow of the program.
 */
Menu::Menu(TaxiCenter*& t,Socket* socket1) {
    taxiCenter =t;
    socket = socket1;
    socket->initialize();
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
    char buffer[1024];
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
                int amountOfDrivers;
                string serializedAbstractCab ;
                cin>>amountOfDrivers;
                for(int i=0; i<amountOfDrivers; i++){
                    Driver* driver;
                    // desirialize the driver received from the client.
                    char buffer[1024];
                    socket->reciveData(buffer,sizeof(buffer));
                    boost::iostreams::basic_array_source<char> device(buffer,sizeof(buffer));
                    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
                    boost::archive::binary_iarchive ia(s2);
                    ia>>driver;
                    taxiCenter->addDriver(driver);
                    map<int, Driver *>::iterator it;//matches drivers and cabs.
                    for (it = taxiCenter->getDriversMap().begin(); it !=
                                                                   taxiCenter->
                                                                           getDriversMap().end();
                         it++) {
                        int cabid = it->second->getVehicleId();
                        for (int i = 0; i < taxiCenter->getCabVector().size(); i++) {
                            if (taxiCenter->getCabVector()[i]->getCabId() == cabid) {
                                it->second->setCab(taxiCenter->getCabVector()[i]);
                                // match the driver to the cab.
                                boost::iostreams::back_insert_device<std::string> inserter
                                        (serializedAbstractCab);
                                boost::iostreams::stream<boost::iostreams::back_insert_device<std::string>>
                                        s(inserter);
                                boost::archive::binary_oarchive oa(s);
                                oa << taxiCenter->getCabVector()[i];
                                s.flush();
                                socket->sendData(serializedAbstractCab);

                            }
                        }
                    }

                }

                break;
            }
            case 2: {// add trip.
                switchFlag = 1;
                string input;
                string inputArr[10];
                int id, startX, startY, endX, endY, numOfPassangers,timeOfStart;
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
                timeOfStart =atoi(inputArr[7].c_str());
                TripInformation *tripInformation = new TripInformation(id,
                                                                       startX, startY,
                                                                       endX, endY, numOfPassangers,
                                                                       tariff, timeOfStart);
                Bfs* b = taxiCenter->getNavigator();//get the navigator from the taxi center.
                AbstractNode* source = matrix->getNode(tripInformation->getSource());// get the source of the trip.
                AbstractNode* destination = matrix->getNode(tripInformation->getDestination()); // get the dest.
                //finds a path from the drivers current location and where the passanger awaits.
                deque<AbstractNode*>* deque1 =new deque<AbstractNode*> (b->theShortestWay(source,destination));
                if(!deque1->empty()){
                    deque1->pop_front();
                }
                //get the path of the trip.
                tripInformation->setShortestPath(deque1);
                //create a new trip.
                taxiCenter->addTrip(tripInformation);
                // add the trip to the taxicenter.
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
                NodePoint *location = (NodePoint *)taxiCenter->getDriverLocation(id);
                cout << *location ;
                break;
            }


            case 7: {// delete all the objects and quit from the program.
                map<int, Driver *>::iterator it;//matches drivers and cabs.
                socket->sendData("ShutDown");
                for (it = taxiCenter->getDriversMap().begin(); it !=
                        taxiCenter->getDriversMap().end(); it++) {
                    delete (it->second);
                }
                delete (matrix);
                for(unsigned long i=0;i<taxiCenter->getCabVector().size();i++) {
                    delete (taxiCenter->getCabVector()[i]);
                    //check the erase.
                }
                for(unsigned long i=0;i<taxiCenter->getTripDeque().size();i++) {
                    delete (taxiCenter->getTripDeque()[i]);
                    //check the erase.
                }

                flag=1;
                break;
            }
            case 9: {   //signals the occupied drivers that it needs to move one step,+ moving the clock.
                switchFlag = 1;
                int clientFlag =0;
                taxiCenter->increaseClockBy1();
                map<int, Driver *>::iterator it;
                unsigned long numOfTrips = taxiCenter->getTripDeque().size();
                socket->sendData("Drive");
                for (it = taxiCenter->getDriversMap().begin(); it != taxiCenter->getDriversMap().end(); it++){
                    it->second->moveOneStep(clientFlag);
                }
              for(unsigned long i=0;i < numOfTrips; i++) {// checks if there is a trip that needs to start.
                  if (taxiCenter->getTripDeque()[i]->getStartTime() == taxiCenter->getTime()) {
                      for (it = taxiCenter->getDriversMap().begin(); it != taxiCenter->getDriversMap().end(); it++) {
                          if (it->second->getAvailable()) {
                              it->second->setCurrentTrip(taxiCenter->getTripDeque()[i]);
                              socket->sendData("AssignTrip");
                              string serializedTrip;
                              boost::iostreams::back_insert_device<std::string> inserter(serializedTrip);
                              boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
                              boost::archive::binary_oarchive oa(s);
                              oa << taxiCenter->getTripDeque()[i];
                              s.flush();
                              socket->sendData(serializedTrip);
                          }
                      }
                  }
              }
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