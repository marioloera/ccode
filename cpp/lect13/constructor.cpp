// example: class constructor
#include <iostream>
using namespace std;

//create class Rectangle
class Rectangle {
    int width, height;//No access specifier specified ⇒ assumes it is private
public:
    
    Rectangle (int,int); //constructor
    ~Rectangle ();//desturctor
    int area () {return (width*height);}
    int perimeter (){        return (2*width+2*height);    }
    int z;
    //int y=10; //WARNING
    //x=3;  //ERROR
    
};

//constructor
Rectangle::Rectangle (int a, int b) {
    cout << "call constructor"  << endl;
    width = a;
    height = b;
}

//destructor
Rectangle::~Rectangle () {
    cout << "call destructor\n" ;// << endl;
}

int main () {
    
    Rectangle rect (1,1); //create intance (object) rect
    Rectangle rectb (2,2);//create intance (object) rect
    
    //call clas funciton
    cout << "rect area: " << rect.area() << endl;
    cout << "rectb area: " << rectb.area() << endl;
    
    cout << "rect perimeter : " << rect.perimeter() << endl;
    cout << "rectb perimeter : " << rectb.perimeter() << endl;
    
    //cout << "rect.y=0:  " << rect.y << endl;
    cout << "ran not initializaed rect.z=" << rect.z << endl;
    rect.z=2;
    cout << "set it to 2 rect.z=" << rect.z << endl;
    
    //rect.width; //ERROR Private member
    
    return 0;
}