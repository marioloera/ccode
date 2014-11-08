#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>     /* atof */

//function to read words in a file (separate for spaces or new line)
std::string ReadWord(std::vector<std::string> &file, int &i, int &j){
    std::string word="";
    while(file[i][j]!='\0' && file[i][j]!=' '){
        word=word+file[i][j];
        j++; //skip space for next search
    }
    j++;
    return word;
}

int main(void)
{
    std::string probSpecFile = "problem1.txt";
    std::fstream fs1;
    fs1.open(probSpecFile.c_str(), std::ios::in);
    
    //read file line per line
    std::vector<std::string> file;
    for (std::string line; getline(fs1, line);)
        file.push_back(line);
    
    unsigned long numLines=file.size();
    std::string kind, valueString;//kind of obstacle
    double p[5];//obstacle parameters
    int i,j;
    //in every line, read words
    for(i=0;i<numLines;i++){
        std::cout << file[i] << std::endl;
        //find kind of obstacle
        j=0;
        kind=ReadWord(file,i,j);
        std::cout<<kind<<std::endl;
       
        int n=0; //cycle depende of the kynd
        if(kind=="RECTANGLE"){n=5;}
        else if (kind=="CIRCLE"){n=3;}
            
        for(int k=0;k<n;k++){
            valueString=ReadWord(file,i,j);
            p[n] = ::atof(valueString.c_str());
            printf("p1=%.4f\n",p[n]);
        }
    }
return 0;
}