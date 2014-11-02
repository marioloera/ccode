//Every object in C++ has access to its own address through an important pointer called this pointer.
//Only member functions have a this pointer.

#include <iostream>

using namespace std;

class Box
{
public:
    // Constructor definition
    Box(double l=2.0, double b=2.0, double h=2.0){
        //cout <<"Constructor called." << endl;
        length = l;
        breadth = b;
        height = h;
        cout <<"Constructor called " << length << " " << breadth << " "<<height <<endl;
    }
    
    double Volume(){return this->length * this->breadth * this->height;}
    
    int bigger(Box boxX){
        //cout<<"\nMy volume  is    " << this->Volume()  <<endl;
        //cout<<"other volume is  " << boxX.Volume()   <<endl;
        //cout<<"My size is " << this->length << " "<<this->breadth << " "<<this->height <<endl;
        return this->Volume() > boxX.Volume();
    }
    
    int smaller(Box boxX){ return this->Volume() < boxX.Volume();}
    
private:
    double length;     // Length of a box
    double breadth;    // Breadth of a box
    double height;     // Height of a box
};

int main(void)
{
    Box BoxA(3.7, 1.7, 1.7);    // Declare box1
    Box BoxB(3.7, 1.7, 1.7);    // Declare box1
    
    cout<<endl;
    cout<<"BoxA volume: " << BoxA.Volume()<<endl;
    cout<<"BoxB volume: " << BoxB.Volume()<<endl;
    
    if(BoxA.bigger(BoxB)){
        cout << "\nBoxA is larger than BoxB" <<endl;
    }
    else if (BoxA.smaller(BoxB)){
        cout << "\nBoxA is smaller than BoxB" <<endl;
    }else {
        cout << "\nBoxA is equal to BoxB" <<endl;
    }
    
    
    
    return 0;
}
