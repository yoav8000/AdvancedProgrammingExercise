//
// Created by liav on 01/12/16.
//

#ifndef EX11_DRIVER_H
#define EX11_DRIVER_H

#include <iostream>
#include "AbstractCab.h"
#include "TripInformation.h"
#include "Bfs.h"
#include "Matrix.h"

using namespace std;
/* class name : Driver
 * Class that create new drivers
 */
class Driver {

private:
    //members.
    int driverId;
    int vehicleId;
    int age;
     char status;
    int yearsOfExperience;
    float avarageSatisfaction;
    bool available;
    AbstractCab* myCab;
    TripInformation* currentTrip;

public:
    // constructors
    Driver(int driverId2, int age2, char maritalStatus);
    Driver(int driverId1, int age1, char maritalStatus,int vid);
    Driver(int driverId1, int age1, char maritalStatus,int vid, int yearsOfExp);

    // get and set functions
    void setAvailable(bool avail);
    bool getAvailable();

    void setAge(int age2);
    int getAge();

    void setMaritalStatus(char maritalStatus);
    int getMaritalStatus();

    void setYearsOfExperience(int years);
    int getYearsOfExperience();

    int getDriverId();
    int getVehicleId();
    void setVehicleId(int id);

    void setCab(AbstractCab*& abstractCab);
    AbstractCab*& getCab();

    void setCurrentTrip(TripInformation*& trip);
    TripInformation* getCurrentTrip();

    void startDriving(Matrix*& matrix);
    // the method notifies the cab to move one step until it gets to the destination.



    // destructor
    ~ Driver();

};


#endif //EX11_DRIVER_H