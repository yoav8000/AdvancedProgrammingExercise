//
// Created by liav on 22/11/16.
//

#ifndef EX11_BFS_H
#define EX11_BFS_H


#include <stack>
#include "AbstractNode.h"
/* class name : Bfs
 * class that implementation BFS algoritem
 */
class Bfs {


public:
    // return the shortest way from star point to the end in stack
    std::stack<AbstractNode*> theShortestWay(AbstractNode* start,
                                             AbstractNode* end);
    ~Bfs();//destructor.
};


#endif //EX11_BFS_H
