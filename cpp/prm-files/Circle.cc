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
    std::cout << "call constructor Circle"  << std::endl;
}

//constructor with arguments
Circle::Circle(double p1, double p2, double p3){
    m_Xc = p1;
    m_Yc = p2;
    m_Radius = p3;
    std::cout << "call constructor Circle with arguments"  << std::endl;
}

Circle::~Circle(){}

bool Circle::collidesWith_C(double x, double y){
    double dx = x - m_Xc;
    double dy = y - m_Yc;
    return (sqrt(dx*dx+dy*dy) <= m_Radius);
}

void Circle::writeMatlabDisplayCode_C(std::ostream &fs){
    fs << "plot("
    << m_Xc << " + " << m_Radius << "*cos((0:5:360)/180*pi),"
    << m_Yc << " + " << m_Radius << "*sin((0:5:360)/180*pi))"<< std::endl
    << "plot("<<m_Xc<<","<<m_Yc<<",'*r')"   << std::endl;
}
