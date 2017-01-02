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
BOOST_CLASS_EXPORT(StandardCab);
BOOST_CLASS_EXPORT(LuxuryCab);
/*
int main(int argc, char *argv[]){
/*
    int portNumber = atoi(argv[1]); // getting the port number from the arguments of the main.
    Socket* socket = new Udp(0,portNumber);//creating a new socket -udp.
    socket->initialize();

    char buffer[1024];
    int id,age,experience,vehicleId;
    char status, dummy;
    cin>>id>>dummy>>age>>dummy>>status>>dummy>>experience>>dummy>>vehicleId;
    Driver* driver = new Driver(id,age,status,vehicleId,experience);

    string serializedDriver = 0;
    boost::iostreams::back_insert_device<std::string> inserter(serializedDriver);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
    boost::archive::binary_oarchive oa(s);
    oa << driver;
    s.flush();


    string serializedNodePoint = 0;
    boost::iostreams::back_insert_device<std::string> inserter(serializedNodePoint);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
    boost::archive::binary_oarchive oa(s);
    oa << serializedNodePoint;
    s.flush();

    cout << serializedNodePoint << endl;

    AbstractNode *an;
    boost::iostreams::basic_array_source<char> device(serializedNodePoint.c_str(), serializedNodePoint.size());
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::binary_iarchive ia(s2);
    ia >> serializedNodePoint;

   // cout << *gp2;
*/
/*
    TaxiCenter* taxiCenter = new TaxiCenter();
    Matrix* matrix= new Matrix(3,3);
    TripInformation *p = new TripInformation(1,2,2,0,1,2,30,8);
    Bfs* b = taxiCenter->getNavigator();//get the navigator from the taxi center.
    AbstractNode* source = matrix->getNode(p->getSource());// get the source of the trip.
    AbstractNode* destination = matrix->getNode(p->getDestination()); // get the dest.
    //finds a path from the drivers current location and where the passanger awaits.
    deque<AbstractNode*> deque1 = b->theShortestWay(source,destination);//get the path of the trip.
    p->setShortestPath(deque1);



    /*
    Driver* p = new Driver (123, 30, 'M', 12345, 10);
    */
/*
     string serializedPoint ;
    boost::iostreams::back_insert_device<std::string> inserter(serializedPoint);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
    boost::archive::binary_oarchive oa(s);
    oa << p;
    s.flush();
    TripInformation* p1;
    boost::iostreams::basic_array_source<char> device(serializedPoint.c_str(), serializedPoint.size());
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::binary_iarchive ia(s2);
    ia >> p1;
    deque<AbstractNode*> deque2 = b->theShortestWay(source,destination);
    int x=2;


}
*/