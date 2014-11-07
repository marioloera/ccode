//
// = FILENAME
//    Circle.cc
//    
// = AUTHOR(S)
//    Mario Loera
//
/*----------------------------------------------------------------------*/

#include <cmath>

//#include "Circle.hh"
#include "Obstacle.hh"


Circle::Circle(){
    m_Xc = 5;
    m_Yc = 3;
    m_Radius = 2;
    std::cout << "call constructor Circle"  << std::endl;
}

Circle::~Circle(){}

bool Circle::collidesWith(double x, double y){
    double dx = x - m_Xc;
    double dy = y - m_Yc;
    return (sqrt(dx*dx+dy*dy) <= m_Radius);
}

void Circle::writeMatlabDisplayCode(std::ostream &fs){
    fs << "plot("
    << m_Xc << " + " << m_Radius << "*cos((0:5:360)/180*pi),"
    << m_Yc << " + " << m_Radius << "*sin((0:5:360)/180*pi))"
    << std::endl;
}
