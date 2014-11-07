////
//// = FILENAME
////    Circle.hh
////
//// = AUTHOR(S)
////    Mario Loera
////
///*----------------------------------------------------------------------*/
//
//#ifndef Circle_hh
//#define Circle_hh
//
////#include <vector>
//#include <iostream>
//#include "Obstacle.hh"
//
//
////the base class for representing the objects
//
//// Derived class
//class Circle : public Obstacle{
//public:
//    Circle();//constructor
//    ~Circle();//destructor
//    double m_Radius;/// The radius of the circle
//     /* Use this function to check if a certain point collides with any
//     * of the obstales in the world
//     * @param x x-coordinate of point to check for collision
//     * @param y y-coordinate of point to check for collision
//     * @return true if point (x,y) collides with any of the obstacles
//     */
//    bool collidesWith(double x, double y);
//    /**
//     * This function will go through all the obstacles in the world and
//     * ask for them to to write matlab display code to the stream.
//     *
//     * @param fs reference to and output stream, for example an fstream (file)
//     * @return N/A
//     */
//    void writeMatlabDisplayCode(std::ostream &fs);
//};
//
//
//#endif // Obstacle_hh
//
//
