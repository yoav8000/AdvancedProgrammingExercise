//
// Created by liav on 21/11/16.
//

#ifndef EX11_ABSTRACTNODE_H
#define EX11_ABSTRACTNODE_H

#include <iostream>
#include <deque>
/* class name : AbstractNode
 * Abstract class that have some virtual functions, this allow to the Bfs
 * being generic
 */
class AbstractNode {
protected:
    bool isObstacle;// flags if the node is an obstacle or not.
    // a function that get the printing from the "sons" classes
    virtual std::ostream& print(std::ostream &output) const = 0;
public:
    // set function
    virtual void setPapa(AbstractNode* node) = 0;
    // return if the Node marked
    virtual int getFlag() = 0;
    // mark the Node
    virtual void setFlag() = 0;
    virtual void setNotFlag() = 0;
    // return deque with the neighbor of this Node in order
    virtual std::deque<AbstractNode*> getNeighbors() = 0;
    // return the father of this Node
    virtual AbstractNode* getPapa() = 0;

    // function that know to print the values of point in this way (x,y)
    friend std::ostream &operator<<( std::ostream &output, const AbstractNode &r);

    virtual void setIsObstacle() = 0;// set the node as an obastacle.
    virtual int getIsObstacle() = 0;// set the node as not an obstacle.
    virtual ~AbstractNode()=0;

};


#endif //EX11_ABSTRACTNODE_H
