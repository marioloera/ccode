//
// = FILENAME
//    Circle.cc
//    
// = AUTHOR(S)
//    Mario Loera
//
/*----------------------------------------------------------------------*/

#include <cmath>

#include "Obstacle.hh"

//default constructor
Circle::Circle(){
    //std::cout << "call constructor Circle"  << std::endl;
}

//constructor with arguments
Circle::Circle(double p1, double p2, double p3){
    //c_Xc = p1;
    //c_Yc = p2;
    //c_Radius = p3;
    std::cout << "call constructor Circle with arguments"  << std::endl;
}

Circle::~Circle(){}

bool Circle::collidesWith_C(double x, double y){
    double dx = x - c_Xc;
    double dy = y - c_Yc;
    return (sqrt(dx*dx+dy*dy) <= c_Radius);
}

void Circle::writeMatlabDisplayCode_C(std::ostream &fs){
    fs << "plot("
    << c_Xc << " + " << c_Radius << "*cos((0:5:360)/180*pi),"
    << c_Yc << " + " << c_Radius << "*sin((0:5:360)/180*pi))"<< std::endl
    << "plot("<<c_Xc<<","<<c_Yc<<",'*r')"   << std::endl;
}
