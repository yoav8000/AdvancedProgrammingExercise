//
// Created by liav on 21/11/16.
//

#ifndef EX11_POINT_H
#define EX11_POINT_H
#include <iostream>

/* class name : Point
 * class that have 2 value (x and y) that represented his location
 * on the coordinate
 */
class Point {
private:
    int x;
    int y;
public:
    // constructors
    Point(int x1, int y1);
    Point();
    // copy function
    Point(const Point &obj);
    // access to xPoint
    int getX()const;
    // access to yPoint
    int getY()const;

    // define "==" relation between different points
    bool operator==(const Point &p) const;
    // function that know to print the values of point in this way (x,y)
    friend std::ostream &operator<<( std::ostream &output, const Point &r);

};


#endif //EX11_POINT_H
