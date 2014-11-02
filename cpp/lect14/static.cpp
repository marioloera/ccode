//no matter how many objects of the class are created, there is only one copy of the static member.
//A static member is shared by all objects of the class.
//All static data is initialized to zero when the first object is created, if no other initialization is present.
#include <iostream>

using namespace std;

class Box
{
public:
    static int objectCount; //ERROR objectCount=0;
    // Constructor definition
    Box(double l=2.0, double b=2.0, double h=2.0)
    {
        //cout <<"Constructor called." << endl;
        length = l;
        breadth = b;
        height = h;
        cout <<"Constructor called " << this->length << " " << this->breadth << " "<< this->height <<endl;
        // Increase every time object is created
        objectCount++;
    }
    double Volume()
    {
        return length * breadth * height;
    }
private:
    double length;     // Length of a box
    double breadth;    // Breadth of a box
    double height;     // Height of a box
};

// Initialize static member of class Box
int Box::objectCount = 0;

int main(void)
{
    cout << "Total objects: " << Box::objectCount << endl;
    Box(3,4,5);
    cout << "Total objects: " << Box::objectCount << endl;
    Box::objectCount = 100;
    cout << "Total objects: " << Box::objectCount << endl;
    
    Box Box1(3.2, 1.3, 1.6);    // Declare box1
    Box Box2(8.4, 6.2, 2.4);    // Declare box2
    
    cout<<endl;
    cout<<"Box1 volume: " << Box1.Volume()<<endl;
    cout<<"Box2 volume: " << Box2.Volume()<<endl;
    
    cout<<endl;
    // Print total number of objects.
    cout << "Total objects: " << Box::objectCount << endl;
    
    cout<<endl;
    Box1.objectCount=88;
    Box2.objectCount+=10;
    cout << "Box::objectCount: " << Box::objectCount << endl;
    cout << "Box1.objectCount: " << Box1.objectCount << endl;
    cout << "Box2.objectCount: " << Box2.objectCount << endl;
    
    return 0;
}