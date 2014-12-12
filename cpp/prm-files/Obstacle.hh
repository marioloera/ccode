//
// = FILENAME
//    Obstacle.hh
//
// = AUTHOR(S)
//    Mario Loera
//
/*----------------------------------------------------------------------*/

#ifndef Obstacle_hh
#define Obstacle_hh

#include <vector>
#include <iostream>
#include <string>
#include "MyWorld.hh"


//the base class for representing the objects

class Obstacle  {
public:
  static int objectCount;
  Obstacle(); //constructor
  ~Obstacle();//destructor
  virtual bool collidesWith_C(double , double );
  virtual void writeMatlabDisplayCode_C(std::ostream &);
  virtual bool collidesWith_R(double , double );
  virtual void writeMatlabDisplayCode_R(std::ostream &);
};

// Derived class
class Circle : public Obstacle{
public:
    Circle();//default constructor
    double c_Xc;// The center X coordinate of the object
    double c_Yc;// The center Y coordinate of the object

    Circle(double p1, double p2, double p3);//constructor with arguments
    ~Circle();//destructor
    double c_Radius;/// The radius of the circle
    /* Use this function to check if a certain point collides with any
     * of the obstales in the world
     * @param x x-coordinate of point to check for collision
     * @param y y-coordinate of point to check for collision
     * @return true if point (x,y) collides with any of the obstacles
     */
    bool collidesWith_C(double , double );
    /**
     * This function will go through all the obstacles in the world and
     * ask for them to to write matlab display code to the stream.
     *
     * @param fs reference to and output stream, for example an fstream (file)
     * @return N/A
     */
    void writeMatlabDisplayCode_C(std::ostream &);
};

// Derived class
class Rectangle : public Obstacle{
public:
    Rectangle();////default constructor
    double r_Xc;// The center X coordinate of the object
    double r_Yc;// The center Y coordinate of the object

    Rectangle(double p1, double p2, double p3, double p4, double p5);//constructor with arguments
    ~Rectangle();//destructor
    double  width, height, angle;/// The radius of the circle
    double a[2],b[2],c[2],d[2];//variable for vertices a[0]=ax a[1]=ay
    void calcVertices();
    /**
     * Use this function to check if a certain point collides with any
     * of the obstales in the world
     *
     * @param x x-coordinate of point to check for collision
     * @param y y-coordinate of point to check for collision
     * @return true if point (x,y) collides with any of the obstacles
     */
    bool collidesWith_R(double , double );
    
    /**
     * This function will go through all the obstacles in the world and
     * ask for them to to write matlab display code to the stream.
     *
     * @param fs reference to and output stream, for example an fstream (file)
     * @return N/A
     */
    void writeMatlabDisplayCode_R(std::ostream &);
};


#endif // Obstacle_hh


