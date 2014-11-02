// example: one class, two objects
#include <iostream>
using namespace std;

class Rectangle {
    int width, height; //No access specifier specified ⇒ assumes it is private
public:
    Rectangle();
    ~Rectangle();
    void set_values (int,int);
    int area () {return width*height;}
};


////constructor
Rectangle::Rectangle () {
    cout << "call constructor"  << endl;
}


//destructor
Rectangle::~Rectangle () {
    cout << "call destructor"  << endl;
}

void Rectangle::set_values (int x, int y) {
    width = x;
    height = y;
}

//Each object has its own member variables and member functions.
int main () {
    Rectangle rect, rectb;
    rect.set_values (3,4);
    rectb.set_values (5,6);
    
    //rect.width; //ERROR Private member

    cout << "rect area: " << rect.area() << endl;
    cout << "rectb area: " << rectb.area() << endl;
    return 0;
}