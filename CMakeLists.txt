cmake_minimum_required(VERSION 3.6)
project(ex11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(BOOST_ROOT CACHE PATH "/usr/include/boost/")
find_package(Boost 1.58.0 COMPONENTS serialization system)
include_directories(${Boost_INCLUDE_DIR})
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
set(SOURCE_FILES src/main.cpp src/Point.cpp src/Point.h Tests/PointTest.cpp Tests/PointTest.h src/AbstractNode.cpp
        src/AbstractNode.h src/NodePoint.cpp
        src/NodePoint.h src/Grid.cpp src/Grid.h src/Matrix.cpp src/Matrix.h Tests/MatrixTest.cpp Tests/MatrixTest.h
        src/Bfs.cpp src/Bfs.h Tests/BfsTest.cpp src/Bfs.h
        src/AbstractCab.cpp src/AbstractCab.h src/StandardCab.cpp src/StandardCab.h src/LuxuryCab.cpp src/LuxuryCab.h
        src/Passanger.cpp src/Passanger.h src/Socket.cpp src/Socket.h src/Udp.cpp src/Udp.h
        Tests/PassangerTest.cpp Tests/PassangerTest.h src/TaxiCenter.cpp src/TaxiCenter.h src/Driver.cpp src/Driver.h
        Tests/DriverTest.cpp
        Tests/DriverTest.h src/TripInformation.cpp src/TripInformation.h Tests/TripInformationTest.cpp
        src/TripInformation.h
        Tests/LuxuryCabTest.cpp Tests/LuxuryCabTest.h Tests/standardCabTest.cpp Tests/standardCabTest.h
        Tests/NodePointTest.cpp Tests/NodePointTest.h
        Tests/TaxiCenterTest.cpp Tests/TaxiCenterTest.h src/Menu.cpp src/Menu.h src/Client.cpp src/Server.cpp)
add_executable(ex11 ${SOURCE_FILES})
target_link_libraries(ex11 ${Boost_LIBRARIES})
target_link_libraries(ex11 gtest gtest_main)
