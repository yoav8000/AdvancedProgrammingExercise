//
// Created by liav on 21/11/16.
//

#ifndef EX11_MATRIX_H
#define EX11_MATRIX_H


#include "Grid.h"
#include "NodePoint.h"
/* class name : Matrix
 * class which inherit from Grid, this class allow us create
 * a map with AbstractNode objects
 */
class Matrix: public Grid {
private:
    int x;
    int y;
    NodePoint* nodes[10][10];
public:
    // constructor
    Matrix(int xSize, int ySize);
    // destructor
    ~Matrix();
    // implementation of virtual function
    AbstractNode* getNode(AbstractNode* node);
};


#endif //EX11_MATRIX_H
