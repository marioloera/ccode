#include <iostream>

class MyClass {

public:

MyClass():mX(1) {}

MyClass(int value):mX(value) {}

int getValue() { return mX; }

private:
	
int mX;
};



int main()
{
MyClass a; // Default constructor
MyClass aa(42); // Constructor with argument
std::cout << a.getValue() << std::endl;
std::cout << aa.getValue() << std::endl;
}


