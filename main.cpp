#include <iostream>
#include "NodePoint.h"
#include "Matrix.h"
#include "Bfs.h"
#include "gtest/gtest.h"
#include "TaxiCenter.h"
#include "LuxuryCab.h"
#include "StandardCab.h"
#include "Menu.h"

using namespace std;


int main(int argc , char**argv) {
    TaxiCenter* taxiCenter = new TaxiCenter();
    Menu menu(taxiCenter);
    menu.getInput();
    delete(taxiCenter);
    return 0;
}