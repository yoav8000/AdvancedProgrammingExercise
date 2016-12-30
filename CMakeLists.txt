cmake_minimum_required(VERSION 3.6)
project(ex11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
set(SOURCE_FILES main.cpp Point.cpp Point.h PointTest.cpp PointTest.h AbstractNode.cpp AbstractNode.h NodePoint.cpp
        NodePoint.h Grid.cpp Grid.h Matrix.cpp Matrix.h MatrixTest.cpp MatrixTest.h Bfs.cpp Bfs.h BfsTest.cpp Bfs.h
        AbstractCab.cpp AbstractCab.h StandardCab.cpp StandardCab.h LuxuryCab.cpp LuxuryCab.h Passanger.cpp Passanger.h
        PassangerTest.cpp PassangerTest.h TaxiCenter.cpp TaxiCenter.h Driver.cpp Driver.h DriverTest.cpp
        DriverTest.h TripInformation.cpp TripInformation.h TripInformationTest.cpp TripInformation.h
        LuxuryCabTest.cpp LuxuryCabTest.h standardCabTest.cpp standardCabTest.h NodePointTest.cpp NodePointTest.h
        TaxiCenterTest.cpp TaxiCenterTest.h Menu.cpp Menu.h)
add_executable(ex11 ${SOURCE_FILES})
target_link_libraries(ex11 gtest gtest_main)
