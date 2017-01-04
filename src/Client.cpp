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


using namespace std;
using namespace boost::archive;



//BOOST_CLASS_EXPORT_GUID(AbstractCab,"AbstractCab");
//BOOST_CLASS_EXPORT(StandardCab);
//BOOST_CLASS_EXPORT(LuxuryCab);

int main(int argc, char *argv[]){
    int portNumber = atoi(argv[1]); // getting the port number from the arguments of the main.
    Socket* socket = new Udp(0,portNumber);//creating a new socket -udp.
    socket->initialize();   //initialize the socket.
    char buffer[1024];  // define a buffer for the serialization.

    int id,age,experience,vehicleId;// recieving a driver.
    char status, dummy;
    cin>>id>>dummy>>age>>dummy>>status>>dummy>>experience>>dummy>>vehicleId;
    Driver* driver = new Driver(id,age,status,vehicleId,experience);    //receive new driver.

    //serialized the driver.
    string serializedDriver ;
    boost::iostreams::back_insert_device<std::string> inserter(serializedDriver);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
    boost::archive::binary_oarchive oa(s);
    oa << driver;
    s.flush();

    //send the serialized driver to the server.
    socket->sendData(serializedDriver);
    AbstractCab* mycab;

    //received the matching taxi from the server for the driver sent before.
    socket->reciveData(buffer,sizeof(buffer));
    boost::iostreams::basic_array_source<char> device(buffer,sizeof(buffer));
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::binary_iarchive ia(s2);
    ia>>mycab;//deserialize the taxi received.
    driver->setCab(mycab);// setting the taxi as the drivers cab.
    int endFlag = 0;
    int clientFlag =1;
    while(endFlag!=1){
        socket->reciveData(buffer,sizeof(buffer));//wait for a command.
        if(strcmp(buffer,"AssignTrip") == 0) {
            TripInformation* tripInformation;
            socket->reciveData(buffer,sizeof(buffer));// receive the trip.
            boost::iostreams::basic_array_source<char> device(buffer,sizeof(buffer));
            boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
            boost::archive::binary_iarchive ia(s2);
            ia>>tripInformation;// deserialize the trip.
            driver->setCurrentTrip(tripInformation);// set as the current trip.
        }

        if(strcmp(buffer,"Drive") == 0){
            driver->moveOneStep(clientFlag);
        }

        if(strcmp(buffer,"ShutDown") == 0){
            delete (driver->getCab()->getLocation());
            delete (driver);
            delete (mycab);
            endFlag=1;
        }
    }

    delete (socket);

}
