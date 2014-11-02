// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <array>

int main () {
    
    int myints[8] = {32,71,12,45,26,80,53,33};
    
    printf("sizeof(myints) %d \n",sizeof(myints)/sizeof(*myints));
    printf("original: \n");
    int i;
    for (i = 0; i <sizeof(myints)/sizeof(*myints); i++) {
        printf("%d ",myints[i]);
    }
    
    std::cout<<std::endl;
    
    std::vector<int> myvector (myints, myints+8);
    
    
    int a=4;
    // using default comparison (operator <):
    std::sort (myvector.begin(), myvector.begin()+a);
    
    // print out content:
    i=0;//resest it
    std::cout << "sort first 4:\n";
    for (std::vector<int>::iterator it = myvector.begin(); it!=myvector.end(); ++it){
        std::cout  << *it << ' ';
        i++;
        if (i==a)
            std::cout << "- ";
        
    }
    
    
    std::cout << std::endl;
    
    return 0;
}