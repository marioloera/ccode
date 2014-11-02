
// class templates
#include <iostream>
using namespace std;

template <class T>
class mypair {
    T a, b; //No access specifier specified ⇒ assumes it is private
public:
    //constructor
    mypair (T first, T second){
        a=first;
        b=second;
        cout << "call constructor a="<<a<<" b="<<b  << endl;
    }
    T myfunction (); //template function
};

template <class T>
T mypair<T>::myfunction ()
{
    T returnValue;
    returnValue = a>b? a : b;
    return returnValue;
}

int main () {
    mypair <double> myobject(1.03, 2.3);
    cout<<myobject.myfunction()<<endl;
    
    mypair <int> myobject2(1, 2);
    cout<<myobject2.myfunction()<<endl;
    
    
    return 0;
}