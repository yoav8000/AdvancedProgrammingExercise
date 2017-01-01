#include <iostream>
#include <fstream>
#include <sstream>
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
#include "Point.h"
#include "NodePoint.h"
#include <boost/serialization/export.hpp>

using namespace std;
using namespace boost::archive;



/*
int main(int argc, char *argv[]){
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


    AbstractNode* p = new NodePoint(1,1);
    string serializedPoint ;
    boost::iostreams::back_insert_device<std::string> inserter(serializedPoint);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
    boost::archive::binary_oarchive oa(s);
    oa << p;
    s.flush();


  boost::iostreams::basic_array_source<char> device(serializedPoint.c_str(), serializedPoint.size());
  boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
  boost::archive::binary_iarchive ia(s2);
  ia >> p1;



    AbstractNode* p1;
    boost::iostreams::basic_array_source<char> device(serializedPoint.c_str(), serializedPoint.size());
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::binary_iarchive ia(s2);
    ia >> p1;
    NodePoint* P2 = (NodePoint*)p1;

    int x=2;


}
*/