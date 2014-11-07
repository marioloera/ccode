////
//// = FILENAME
////    Rectangle.hh
////
//// = AUTHOR(S)
////    Mario Loera
////
///*----------------------------------------------------------------------*/
//
//#ifndef Rectangle_hh
//#define Rectangle_hh
//
////#include <vector>
//#include <iostream>
//#include "MyWorld.hh"
//#include "Obstacle.hh"
//
//
//
//// Derived class
//class Rectangle : public Obstacle{
//public:
//    Rectangle();//constructor
//    ~Rectangle();//destructor
//    double  width, height, angle;/// The radius of the circle
//    double a[2],b[2],c[2],d[2];
//    /**
//     * Use this function to check if a certain point collides with any
//     * of the obstales in the world
//     *
//     * @param x x-coordinate of point to check for collision
//     * @param y y-coordinate of point to check for collision
//     * @return true if point (x,y) collides with any of the obstacles
//     */
//    bool collidesWith(double x, double y);
//    
//    /**
//     * This function will go through all the obstacles in the world and
//     * ask for them to to write matlab display code to the stream.
//     *
//     * @param fs reference to and output stream, for example an fstream (file)
//     * @return N/A
//     */
//    void writeMatlabDisplayCode(std::ostream &fs);
//   
//};
//
//#endif // Obstacle_hh
//
//
