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
#include <boost/serialization/export.hpp>
#include "Socket.h"
#include "Udp.h"
#include "Driver.h"
#include "StandardCab.h"
#include "LuxuryCab.h"


using namespace std;
using namespace boost::archive;



//BOOST_CLASS_EXPORT_GUID(AbstractCab,"AbstractCab");
BOOST_CLASS_EXPORT(StandardCab);
BOOST_CLASS_EXPORT(LuxuryCab);
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

    Matrix matrix(10,10);
    NodePoint* p3 =new NodePoint(0,0);
    AbstractNode* abstractNode = matrix.getNode(p3);
    delete p3;


    AbstractCab* p = new LuxuryCab(12345678, 1000,'H', 'B',abstractNode);
    Bfs bfs;
    NodePoint* start = new NodePoint(0,0);
    NodePoint* end = new NodePoint(1,1);
    deque<AbstractNode*> s1 = bfs.theShortestWay(matrix.getNode(start),matrix.getNode(end));
    p->setShortestPath(s1);
    string serializedPoint ;
    boost::iostreams::back_insert_device<std::string> inserter(serializedPoint);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
    boost::archive::binary_oarchive oa(s);
    oa << p;
    s.flush();

    AbstractCab* p1;
    boost::iostreams::basic_array_source<char> device(serializedPoint.c_str(), serializedPoint.size());
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::binary_iarchive ia(s2);
    ia >> p1;

    deque<AbstractNode*> d = p->getShortestPath();
    deque<AbstractNode*> d1 = p1->getShortestPath();
    d.pop_front();
    d1.pop_front();

    NodePoint* point = (NodePoint*) d.front();
    NodePoint* point1 = (NodePoint*) d1.front();



    NodePoint* point2 = (NodePoint*)p1->getShortestPath().front();
    int x=2;


}
