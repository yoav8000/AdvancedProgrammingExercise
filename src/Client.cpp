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


using namespace std;
using namespace boost::archive;





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

    Bfs* p = new Bfs;
    string serializedPoint ;
    boost::iostreams::back_insert_device<std::string> inserter(serializedPoint);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
    boost::archive::binary_oarchive oa(s);
    oa << p;
    s.flush();

    Bfs* p1;
    boost::iostreams::basic_array_source<char> device(serializedPoint.c_str(), serializedPoint.size());
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::binary_iarchive ia(s2);
    ia >> p1;


    Matrix matrix(10, 10);
    NodePoint node1(0,0), node2(3, 5);
    AbstractNode* start = matrix.getNode(&node1);
    AbstractNode* end = matrix.getNode(&node2);
    stack<Point> pointsStack;
    for (unsigned i = 5, j = 3; j > 0; --j) {
        pointsStack.push(Point(j,i));
    }
    for (int i = 5; i >= 0; --i) {
        pointsStack.push(Point(0, i));
    }
    stack<AbstractNode*> stack = p1->theShortestWay(start, end);
    while (!stack.empty() && !pointsStack.empty()) {

        NodePoint* node =(NodePoint*) stack.top();
        int x =(node->getPoint() == pointsStack.top());
        pointsStack.pop();
        stack.pop();
    }

    int x=2;


}
