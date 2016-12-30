//
// Created by yoav on 13/12/16.
//

#ifndef EX11_MENU_H
#define EX11_MENU_H


#include "TaxiCenter.h"
#include "Matrix.h"
/*
 * class name: Menu.
 * the class is in charge of the entire flow of the program.
 *
 */
class Menu {
private:
    void parseInput(string s,string* inputArr);
    // the taxi parses the input received from the user by a delimiter.
    //members.
    TaxiCenter* taxiCenter;
    Matrix* matrix;
public:
    Menu(TaxiCenter*& t);
    void getInput();
    //the method takes an input from the user line by line and operates the
    // proper mission accordingly.
    ~Menu();

};


#endif //EX11_MENU_H