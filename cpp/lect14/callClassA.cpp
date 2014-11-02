#include <iostream>
#include "A.h"

int main() {
    //A::A();//call constructor without create an object, useless
    A a;
    std::cout << "a.mX="<< a.getmX()<<std::endl;
    std::cout << "a.z="<< a.z<<std::endl;
    
    //A(1,2); //call constructor without create an object, useless
    //A::A(3, 4);  //call constructor without create an object, useless
    A aa(3,2);
    std::cout << "aa.z="<< aa.z<<std::endl;
    std::cout << "aa.mX="<< aa.getmX()<<std::endl;
}