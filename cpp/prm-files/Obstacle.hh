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

//#include <vector>
#include <iostream>
#include "MyWorld.hh"


//the base class for representing the objects

class Obstacle: public MyWorld {
public:
  static int objectCount;
  Obstacle(); //constructor
  ~Obstacle();//destructor
  double m_Xc;// The center X coordinate of the object
  double m_Yc;// The center Y coordinate of the object
};

// Derived class
class Circle : public Obstacle{
public:
    Circle();//constructor
    ~Circle();//destructor
    double m_Radius;/// The radius of the circle
    /* Use this function to check if a certain point collides with any
     * of the obstales in the world
     * @param x x-coordinate of point to check for collision
     * @param y y-coordinate of point to check for collision
     * @return true if point (x,y) collides with any of the obstacles
     */
    bool collidesWith(double x, double y);
    /**
     * This function will go through all the obstacles in the world and
     * ask for them to to write matlab display code to the stream.
     *
     * @param fs reference to and output stream, for example an fstream (file)
     * @return N/A
     */
    void writeMatlabDisplayCode(std::ostream &fs);
};

// Derived class
class Rectangle : public Obstacle{
public:
    Rectangle();//constructor
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
    bool collidesWith(double x, double y);
    
    /**
     * This function will go through all the obstacles in the world and
     * ask for them to to write matlab display code to the stream.
     *
     * @param fs reference to and output stream, for example an fstream (file)
     * @return N/A
     */
    void writeMatlabDisplayCode(std::ostream &fs);
};


#endif // Obstacle_hh


