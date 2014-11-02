#include <iostream>

using namespace std;

// Base class
class Shape{
public:
    Shape () {cout << "call constructor"  << endl;}//constructor
    //~Shape () {cout << "call destructor"  << endl;}//destructor
    void setWidth(int w){width = w;}
    void setHeight(int h){ height = h;}
    void setprivNum(int a){privNum=a;}
    int getprivNum (){return privNum;}
    int callResult (){return result();}
    //void callResult (){ result();}
    
protected:
    int width;
    int height;
    void print() { cout << "Protected function: Print"  << endl;};
private:
    int privNum;
    int result(){
        cout << "Result\n";
        return privNum;
    }
};

// Derived class
class Rectangle: public Shape{
public:
    int getArea(){return (width * height);}//can be acces because they are protected, not privete
    void callprint(){ print(); }//call protected function
};


// 2 Derived class
class RectangleTwo: public Rectangle{};

int main(void)
{
    cout << "Shape class object \n";
    Shape shape;//object for normal clas
    shape.setWidth(3);
    shape.setprivNum(22);
    cout << "shape.setprivNum(22)=" << shape.getprivNum() << endl;
    int x=shape.callResult();
    cout << "x=privNum="<<x<<endl;
    //shape.width;//ERROR : declared protected
    //shape.privNum;  //ERROR : declared private
    //shape.getArea(); //ERROR, this function is only on the derived class.
    
    cout << "\nDerived class Rectangle object\n";
    Rectangle Rect;//derived class.
    Rect.setWidth(5);
    Rect.setHeight(7);
    cout << "Total area: " << Rect.getArea() << endl;// Print the area of the object.
    Rect.callprint();//call protected function
    Rect.setprivNum(33);
    cout << "Rect.setprivNum(33)=" << Rect.getprivNum() << endl;
    x=Rect.callResult();
    cout << "x=privNum="<<x<<endl;
    
    //Rect.print();//ERROR : declared protected
    //Rect.height=1;//ERROR : declared protected
    //Rect.privNum; //ERROR : declared private
    
    
    cout << "\n2 Derived class RectangleTwo object\n";
    RectangleTwo Rect2;
    Rect2.setWidth(5);
    Rect2.setHeight(7);
    cout << "Total area: " << Rect2.getArea() << endl;// Print the area of the object.
    Rect2.callprint();//call protected function
    Rect2.setprivNum(44);
    cout << "Rect.setprivNum(44)=" << Rect2.getprivNum() << endl;
    x=Rect2.callResult();
    cout << "x=privNum="<<x<<endl;
    
    
    
    
    return 0;
}