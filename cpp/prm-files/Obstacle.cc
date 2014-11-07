//
// = FILENAME
//    Obstacle.cc
//    
// = AUTHOR(S)
//    Mario Loera
//
/*----------------------------------------------------------------------*/

#include <cmath>

#include "Obstacle.hh"


int Obstacle::objectCount = 0;

Obstacle::Obstacle(){
    std::cout << "call constructor Obstacle"  << std::endl;
    objectCount++;
}

Obstacle::~Obstacle(){}

