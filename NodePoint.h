//
// Created by liav on 21/11/16.
//

#ifndef EX11_NODEPOINT_H
#define EX11_NODEPOINT_H


#include <iostream>
#include "AbstractNode.h"
#include "Point.h"

/* class name : NodePoint
 * class which inherit from AbstractNode, by this class we can
 * create a map that every object from this class is a square on the map
 */
class NodePoint: public AbstractNode {
private:
    bool flag;
    AbstractNode* papa;
    Point p;
    std::deque<AbstractNode*> neighbors;
    int isObstacle;
protected:
    std::ostream& print(std::ostream &output) const;
public:

    // constructors
    NodePoint(Point point, NodePoint* father);
    NodePoint(int x, int y, NodePoint* father);
    NodePoint(Point point);
    NodePoint(int x, int y);
    NodePoint();


    // "==" definition
    bool operator==(const NodePoint &r) const;

    // "!=" definition
    bool operator!=(const NodePoint &r) const;


    // get and set functions
    void setPapa(AbstractNode* node);
    AbstractNode* getPapa();
    void setPoint(int x, int y);
    Point getPoint()const;
    void setFlag();
    void setNotFlag();
    int getFlag();
    void setIsObstacle();
    int getIsObstacle();
    std::deque<AbstractNode*> getNeighbors();

    // copy function
    NodePoint(const NodePoint &obj);
    // add to the deque Node which near to this NodePoint
    void addNeighbor(AbstractNode* node);
    ~NodePoint();
};


#endif //EX11_NODEPOINT_H
