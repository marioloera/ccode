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

//default constructor
Rectangle::Rectangle(){
    m_Xc = 5;
    m_Yc = 5;
    width = 7;
    height=7;
    angle=-.3;
    calcVertices();
    std::cout << "call constructor Rectangle"  << std::endl;
}
////constructor wiht arguments
//Rectangle::Rectangle(double p1, double p2, double p3, double p4, double p5){
//     m_Xc = p1;
//     m_Yc = p2;
//     width = p3;
//     height=p4;
//     angle=p5;
//     calcVertices();
//    std::cout << "call constructor Rectangle with arguments"  << std::endl;
// }

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
    double X=x-m_Xc;
    double Y=y-m_Yc;
    double hip= sqrt(X*X+Y*Y);
    
    double theta=atan(Y/X);
    double dx=std::abs(hip*cos(theta-angle));
    double dy=std::abs(hip*sin(theta-angle));
    return (dx<width/2 && dy<height/2);//true if collide
}

void Rectangle::writeMatlabDisplayCode(std::ostream &fs)
{
    //display vertices
    //%plot(a(1),a(2),'*r')
    fs
    << "plot("<<m_Xc<<","<<m_Yc<<",'*r')"   << std::endl
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
