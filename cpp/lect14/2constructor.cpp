// classes example
#include <iostream>
using namespace std;

class MyClass { public:
    MyClass():m(1) {cout << "call constructor 0"  << endl;}
    MyClass(int value):m(value) {cout << "call constructor 1"  << endl;}
    MyClass (int, int);
    int getValue() { return m; }
private:
    int m;
};

MyClass::MyClass (int a, int b){
    m=a+b;
    cout << "call constructor 2"  << endl;
    
}
MyClass a; // Default constructor
MyClass aa(42); // Constructor with argument
MyClass ab(43);
MyClass ac(2,3);

//ERROR MyClass ab(42,2);



int main () {
    std::cout << a.getValue() << std::endl;
    std::cout << aa.getValue() << std::endl;
    std::cout << ab.getValue() << std::endl;
    std::cout << ac.getValue() << std::endl;

    
    return 0;
}

//By declaring them private, access from outside the class is not allowed.
// public members are accessible from anywhere where the object is visible.
