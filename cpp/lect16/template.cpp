#include <iostream>
using namespace std;


template <class T> T getMax (T a, T b) {
    if(a>b) {return a;}
    else {return b;} }


// Main function for the program
int main( )
{


     cout << "\ngetMax<int>(4,5)= " << getMax<int>(4,5) <<endl;
    cout << "\ngetMax<double>(4.2, 4.1)= " << getMax<double>(4.2, 4.1)<<endl;
    
  

    
    return 0;
}