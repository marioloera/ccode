// classes example
#include <iostream>
using namespace std;

class Rectangle {
    int width, height; //No access specifier specified ⇒ assumes it is private
  public:
    Rectangle() {cout << "call constructor"  << endl;}
    ~Rectangle();
    void set_values (int,int);
    int area() {return width*height;}
};

////constructor
//Rectangle::Rectangle () {
//    cout << "call constructor"  << endl;
//}


//destructor
Rectangle::~Rectangle () {
    cout << "call destructor"  << endl;
}

void Rectangle::set_values (int x, int y) {
  width = x;
  height = y;
}

int main () {
  Rectangle rect;
  rect.set_values (3,4);
  
    //rect.width; //ERROR Private member

  cout << "area: " << rect.area() << endl;
 
  return 0;
}

//By declaring them private, access from outside the class is not allowed.
// public members are accessible from anywhere where the object is visible.