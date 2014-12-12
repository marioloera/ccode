//
// = FILENAME
//    MyWorld.cc
//    
// = AUTHOR(S)
//    Mario Loera
//
/*----------------------------------------------------------------------*/




#include "MyWorld.hh"
#include "Obstacle.hh"
#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <istream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>


//object to save parameters for circle and rectangle
std::vector<Obstacle*> obsdata_c;
std::vector<Obstacle*> obsdata_r;


MyWorld::MyWorld() //constructur
{
  std::cout <<"call constructor MyWorld\n";
}

MyWorld::~MyWorld() {}

bool MyWorld::readObstacles(std::istream &fs){
    
    std::string str;//argument to contain each line from problem
    // loop to get lines
    while (getline(fs,str))
    {
        std::istringstream iss(str);//input line
        std::string token[6];
        std::vector<std::string> get;//vector to contain type and number
        int i = 0;
        // loop to get type and number from a line
        while(std::getline(iss, token[i], ' ')) {
            get.push_back(token[i]);//save into vector
            i++;
        }
        //get parameters of circle
        if(token[0]=="CIRCLE") {
            Circle *c = new Circle;
            std::stringstream ss1(token[1]);
            ss1 >> c->m_Xc;
            std::stringstream ss2(token[2]);
            ss2 >> c->m_Yc;
            std::stringstream ss3(token[3]);
            ss3 >> c->m_Radius;
            obsdata_c.push_back(c);
            
            //get parameters of rectangle
        }else if(token[0]=="RECTANGLE") {
            Rectangle *r = new Rectangle;
            std::stringstream ss1(token[1]);
            ss1 >> r->m_Xc;
            std::stringstream ss2(token[2]);
            ss2 >> r->m_Yc;
            std::stringstream ss3(token[3]);
            ss3 >> r->width;
            std::stringstream ss4(token[4]);
            ss4 >> r->height;
            std::stringstream ss5(token[5]);
            ss5 >> r->angle;
            obsdata_r.push_back(r);
        }
    }
    return true;
}

void MyWorld::writeMatlabDisplayCode(std::ostream &fs){
    for(std::vector<Obstacle*>::iterator i = obsdata_c.begin() ; i != obsdata_c.end(); ++i){
        (*i)->writeMatlabDisplayCode_C(fs);
    };
    for(std::vector<Obstacle*>::iterator i = obsdata_r.begin() ; i != obsdata_r.end(); ++i){
        (*i)->writeMatlabDisplayCode_R(fs);
    };
}
bool collidesWith(double x, double y){
    
    bool collision = false;
    
    // loop to call parameters and function of collision in object
    for(std::vector<Obstacle*>::iterator i = obsdata_c.begin() ; i != obsdata_c.end(); ++i){
        collision = (*i)->collidesWith_C(x, y);
        if (collision){break;}
    };
    
    if (!(collision)){
    for(std::vector<Obstacle*>::iterator i = obsdata_r.begin() ; i != obsdata_r.end(); ++i){
        collision = (*i)->collidesWith_R(x, y);
        if (collision){break;}
    };
    }
    return (collision);//accumulate collision
}


//function to read words in a file (separate for spaces or new line)

//std::string MyWorld::ReadWord(std::vector<std::string> &file, int &i, int &j){
//    std::string word="";
//    while(file[i][j]!='\0' && file[i][j]!=' '){
//        word=word+file[i][j];
//        j++; //skip space for next search
//    }
//    j++;
//    return word;}
