//
// = FILENAME
//    MyWorld.cc
//    
// = AUTHOR(S)
//    Mario Loera
//
/*----------------------------------------------------------------------*/

#include "MyWorld.hh"


MyWorld::MyWorld() //constructur
{
  std::cout <<"call constructor MyWorld\n";
}

MyWorld::~MyWorld() {}

bool MyWorld::readObstacles(std::istream &fs){
    
    //read file line per line
    std::vector<std::string> file;
    for (std::string line; getline(fs, line);)
        file.push_back(line);

    unsigned long numLines=file.size();
    std::string kind, valueString;//kind of obstacle
    double p[5];//obstacle parameters
    int j;
    //in every line, read words
    for(int i=0;i<numLines;i++){
        j=0;
        kind=ReadWord(file,i,j);//find kind of obstacle
        int n=0; //cycle depende of the kynd
        if(kind=="RECTANGLE"){n=5;std::cout << kind<<":\n";}
        else if (kind=="CIRCLE"){n=3;std::cout << kind<<":\n";}
        for(int k=0;k<n;k++){
            valueString=ReadWord(file,i,j);
            p[n] = ::atof(valueString.c_str());
            printf(" p%d=%.4f",k,p[n]);
        }
        std::cout<<std::endl;
    }
    printf("\nRead obstacles from file done!\n");

//
//    std::cerr << std::endl
//    << "MyWorld::readObstacles this function has not been overloaded"
//    << std::endl
//    << "and there thus is no way to read obstacles from file."
//    << std::endl
//    << "A static map may be in use" << std::endl << std::endl;
    return true;
}

void MyWorld::writeMatlabDisplayCode(std::ostream &fs)
{
    std::cerr << std::endl
    << "MyWorld::writeMatlabDisplayCode not overloaded"
    << std::endl
    << "Not writing any matlab code"
    << std::endl << std::endl;
}


//function to read words in a file (separate for spaces or new line)
std::string MyWorld::ReadWord(std::vector<std::string> &file, int &i, int &j){
    std::string word="";
    while(file[i][j]!='\0' && file[i][j]!=' '){
        word=word+file[i][j];
        j++; //skip space for next search
    }
    j++;
    return word;}
