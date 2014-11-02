#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    
    vector<double> x;
    
    for(int i=1;i<10;i++)
    { x.push_back(.5*i);}
    
    for(auto buffer:x) {cout << buffer <<" ";};//auto loop
    
    cout<<endl;
    for(auto buffer:x) {cout << buffer << endl;};//auto loop
    
    
};
