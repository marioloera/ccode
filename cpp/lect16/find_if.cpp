// find_if example
#include <iostream>     // std::cout
#include <algorithm>    // std::find_if
#include <vector>       // std::vector

bool IsOdd (int i) {
    std::cout << "i " << i << std::endl;
    return i%2;
}

bool IsEven (int i) {
    std::cout << "i " << i << std::endl;
    return !(i%2);
}

int main () {
    std::vector<int> myvector;
    
    myvector.push_back(61);
    myvector.push_back(3);
    myvector.push_back(43);
    myvector.push_back(2);
    
    
    //if not odd number is found it, it will return the first element.
    std::vector<int>::iterator numFound;
    numFound= std::find_if (myvector.begin(), myvector.end(), IsOdd);
    std::cout << "The first odd value is " << *numFound << '\n';
    
    //if not even number is found it, it will return the first element.
    numFound = std::find_if (myvector.begin(), myvector.end(), IsEven);
    std::cout << "The first even value is " << *numFound << '\n';
    
    
    
    return 0;
}