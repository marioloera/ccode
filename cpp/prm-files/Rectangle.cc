//
// = FILENAME
//    Rectangle.cc
//    
// = AUTHOR(S)
//    Mario Loera
//
/*----------------------------------------------------------------------*/

#include <cmath>


#include "Obstacle.hh"
#include "Rectangle.hh"

//constructor
Rectangle::Rectangle(){
    m_Xc = 5;
    m_Yc = 5;
    width = 4;
    height=2;
    angle=0;
    
    a[0]=6;
    a[1]=0;
    b[0]=3;
    b[1]=5;
    c[0]=12;
    c[1]=9;
    d[0]=14;
    d[1]=4;
    

    std::cout << "call constructor Rectangle"  << std::endl;
}

Rectangle::~Rectangle(){}

bool Rectangle::collidesWith(double x, double y)
{
    double dx = x - m_Xc;
    double dy = y - m_Yc;
    
    return (sqrt(dx*dx+dy*dy) <= width);
}

void Rectangle::writeMatlabDisplayCode(std::ostream &fs)
{
    fs << "plot("
    << m_Xc << " + " << width << "*cos((0:5:360)/180*pi),"
    << m_Yc << " + " << width << "*sin((0:5:360)/180*pi))"<< std::endl
    
    //display vertices
    //%plot(a(1),a(2),'*r')
    << "plot("<<a[0]<<","<<a[1]<<",'*r')"   << std::endl
    << "plot("<<b[0]<<","<<b[1]<<",'*r')"   << std::endl
    << "plot("<<c[0]<<","<<c[1]<<",'*r')"   << std::endl
    << "plot("<<d[0]<<","<<d[1]<<",'*r')"   << std::endl
    
    //display lines between vertices
    //%plot([a(1) b(1)],[a(2) b(2)])
    <<"plot(["<<a[0]<<" "<<b[0]<<"],["<<a[1]<<","<<b[1]<<"])"<<std::endl
    <<"plot(["<<c[0]<<" "<<b[0]<<"],["<<c[1]<<","<<b[1]<<"])"<<std::endl
    <<"plot(["<<a[0]<<" "<<d[0]<<"],["<<a[1]<<","<<d[1]<<"])"<<std::endl
    <<"plot(["<<c[0]<<" "<<d[0]<<"],["<<c[1]<<","<<d[1]<<"])"<<std::endl
    ;
}
