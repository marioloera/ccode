//
// = FILENAME
//    MyWorld.cc
//    
// = AUTHOR(S)
//    Patric Jensfelt
//
/*----------------------------------------------------------------------*/

#include "MyWorld.hh"

#include <iostream>
#include <vector>

MyWorld::MyWorld() //constructur
{
  std::cout <<"call constructor MyWorld\n";
}

MyWorld::~MyWorld() {}



bool MyWorld::readObstacles(std::istream &fs){



    
//    double xStart, yStart, xGoal, yGoal;
//    std::string skip;
//    if ( (fs >> skip >> xStart >> yStart >> xGoal >> yGoal) == false) {
//        std::cerr << "Could not read start/goal data from \""
//        << probSpecFile << "\"\n";
//        return -1;
//    }
//    
    
    
    

    std::cerr << std::endl
    << "World::readObstacles this function has not been overloaded"
    << std::endl
    << "and there thus is no way to read obstacles from file."
    << std::endl
    << "A static map may be in use" << std::endl << std::endl;
    return true;
}

void MyWorld::writeMatlabDisplayCode(std::ostream &fs)
{
    std::cerr << std::endl
    << "World::writeMatlabDisplayCode not overloaded"
    << std::endl
    << "Not writing any matlab code"
    << std::endl << std::endl;
}

