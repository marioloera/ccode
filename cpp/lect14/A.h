#include <iostream>
using namespace std;

class A{
public:
    int z;
    A() : z(1), mX(1) {
        cout<< "call constructor 1. z and mX initialized to "<< mX << endl;
    };
    A (int, int);
    int getmX () {return (mX);}
private:
    int mX;
};

A::A (int a, int b){
    cout << "call constructor 2. z initialized to "<<b<< ". mX initialized to "<<a  << endl;
    mX=a;
    z=b;
}
