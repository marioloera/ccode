//
// = FILENAME
//    Obstacle.cc
//    
// = AUTHOR(S)
//    Mario Loera
//
/*----------------------------------------------------------------------*/

#include <cmath>
#include <string>
#include "Obstacle.hh"

int Obstacle::objectCount = 0;

Obstacle::Obstacle(){
    //std::cout << "call constructor Obstacle"  << std::endl;
    objectCount++;
}

Obstacle::~Obstacle(){objectCount--;}


bool Obstacle::collidesWith_R(double, double ){}

void Obstacle::writeMatlabDisplayCode_R(std::ostream &){}

bool Obstacle::collidesWith_C(double , double ){}

void Obstacle::writeMatlabDisplayCode_C(std::ostream &){}
