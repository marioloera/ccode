#include <iostream>
#include <algorithm>
using namespace std;

int main ()
{
    
    int myints[] = { 10, 20, 30 ,29 };
    
    int * p;
    
    int x=30;
    
    p = std::find (myints,myints+4,x);
    
    std::cout << "x="<<*p<<"="<<x<<". position ="<< p<<endl;
    
    
    
    ++p;
    
    std::cout << "x="<<*p<<"="<<x<<". position ="<< p<<endl;
}