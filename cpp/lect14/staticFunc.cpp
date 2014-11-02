/*
 1) By declaring a function member as static, you make it independent of any particular object of the class.
 2) A static member function can be called even if no objects of the class exist.
 3) The static functions are accessed using only the class name and the scope resolution operator ::.
 4) A static member function can only access static data member, other static member functions and any other functions from outside the class.
 5) Static member functions have a class scope and they do not have access to the this pointer of the class.
 6) You could use a static member function to determine whether some objects of the class have been created or not.
 */

#include <iostream>

using namespace std;

class Box
{
public:
    static int objectCount;
    static int getCount(){return objectCount;}
    // Constructor definition
    Box(double l=2.0, double b=2.0, double h=2.0){
        cout <<"Constructor called." << endl;
        length = l;
        breadth = b;
        height = h;
        objectCount++;// Increase every time object is created
    }
    double Volume(){return length * breadth * height;}
    
private:
    double length;
    double breadth;
    double height;
};

// Initialize static member of class Box
int Box::objectCount = 0;

int main(void)
{
    
    cout << "Inital Stage Count: " << Box::getCount() << endl;
    
    Box BoxA(3.5, 1.5, 1.7);
    Box BoxB(8.8, 6.4, 2.3);
    //Box(3,3,3);
    cout << "Final Stage Count: " << Box::getCount() << endl;
    
    return 0;
}