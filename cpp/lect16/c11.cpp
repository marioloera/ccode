#include <iostream>     // std::cout
#include <algorithm>    // std::find_if
#include <vector>       // std::vector

using namespace std;


int main() {

vector<int> x;

for(int i=1;i<10;i++) 
	{ x.push_back(i);}

auto pos = std::find_if(std::begin(x), std::end(x), [](int n) {return n%2==0;} );

cout << *pos; 
};

//g++ loops.cpp -o loop -std=c++11