//
// = FILENAME
//    Rectangle.cc
//    
// = AUTHOR(S)
//    Mario Loera
//
/*----------------------------------------------------------------------*/

#include <cmath>


//#include "Rectangle.hh"
#include "Obstacle.hh"

//constructor
Rectangle::Rectangle(){
    m_Xc = 5;
    m_Yc = 5;
    width = 2;
    height=1;
    angle=3.1617/2;
    calcVertices();

    std::cout << "call constructor Rectangle"  << std::endl;
}

Rectangle::~Rectangle(){}

void Rectangle::calcVertices(){
//  width, height, angle;
    // double m_Xc;// The center X coordinate of the object
    //double m_Yc;
    double j,k,l,m;
    
    j=width*sin(angle)/2;
    k=height*sin(angle)/2;
    l=width*cos(angle)/2;
    m=height*cos(angle)/2;
    
    a[0]=m_Xc-l+k;
    b[0]=m_Xc-l-k;
    c[0]=m_Xc+l-k;
    d[0]=m_Xc+l+k;
    
    a[1]=m_Yc-j-m;
    b[1]=m_Yc-j+m;
    c[1]=m_Yc+j+m;
    d[1]=m_Yc+j-m;
    
    
}

bool Rectangle::collidesWith(double x, double y)
{
    //double dx = x - m_Xc;
    //double dy = y - m_Yc;
    
    
    double t=x-m_Xc;
    double z=y-m_Yc;
    double theta=atan(t/z);
    double hip= sqrt(t*t+z*z);
    double dx=(hip*cos(theta+angle));
    double dy=abs(hip*sin(theta+angle));
    

    
    
    return (dx<width/2 && dy<height/2);//true if collide
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
