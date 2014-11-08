//
// = FILENAME
//    solvePlanningProblem.cc
//
// = AUTHOR(S)
//    Patric Jensfelt
//
/*----------------------------------------------------------------------*/

//#define WIN32

#include "SingleCircleWorld.hh"
#include "MyWorld.hh"
#include "Obstacle.hh"
#include "PRM.hh"

//test

#ifndef WIN32
#include <unistd.h>  
#endif
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char **argv)
{
  std::string probSpecFile = "problem1.txt";
  std::string worldModel = "SingleCircleWorld";
  
  int numNodes = 100;
  int numEdges = 10;
  double stepSize = 0.1;
  const double xMin = 0;
  const double xMax = 10;
  const double yMin = 0;
  const double yMax = 10;
  bool alwaysDisplayEdges = false;
  
#ifndef WIN32
  const char *optstring = "hp:n:e:s:w:D";
  const char *args = "[-h help] [-p inputfile with problem spec] "
    "[-n number of nodes] [-e number of edges per node] "
    "[-s step size for collision check] [-w world model] "
    "[-D always display edges]";
  char o = getopt(argc, argv, optstring);
  while (o != -1) {
    switch (o) {
    case 'p':
      probSpecFile = optarg;
      worldModel=probSpecFile;
      //std::cout<<probSpecFile<<" ***"<<std::endl;
      break;
    case 'n':
      numNodes = atoi(optarg);
      break;
    case 'e':
      numEdges = atoi(optarg);
      break;
    case 's':
      stepSize = atof(optarg);
      break;
    case 'w':
      worldModel = optarg;
      break;
    case 'D':
      alwaysDisplayEdges = true;
      break;
    case 'h':
    case '?':
      fprintf(stderr, "Usage: %s %s\n", argv[0], args);
      return -1;
    }
    o = getopt(argc, argv, optstring);
  }
#endif
    

    World* world = 0;
//    std::fstream fs1;
//    fs1.open(probSpecFile.c_str(), std::ios::in);

    //if (worldModel == "SingleCircleWorld") {world = new SingleCircleWorld;}
    if (worldModel == "SingleCircleWorld") {world = new Rectangle;}
    // By adding to this if-statement you can easily make the program
    // create an instance of your own class

    else if (worldModel == "problem0.txt"){world = new Circle;}

    else if (worldModel == "problem1.txt"){world = new Rectangle;}
    
    //else if (worldModel == "problem2.txt"){world = new Rectangle(5,5,4,5,.2);}
        
    //else if (worldModel == "problem3.txt"){world = new Circle(5,5,3.9);}
    
  
  else {
    std::cerr << "worldModel \"" << worldModel << "\" is unknown,"
              << "specify a correct model with -w option or leave out" 
              << std::endl;
    return -1;
  }
  
    

    std::fstream fs;
    fs.open(probSpecFile.c_str(), std::ios::in);
    if (fs <= 0) {
        std::cerr << "Failed to open problem spec file \""
        << probSpecFile << "\"\n";
        return -1;
    }
    
    // Read the start and goal position
    double xStart, yStart, xGoal, yGoal;
    std::string skip;
    if ( (fs >> skip >> xStart >> yStart >> xGoal >> yGoal) == false) {
        std::cerr << "Could not read start/goal data from \""
        << probSpecFile << "\"\n";
        return -1;
    }


  std::cout << std::endl
            << "Parameter setup" << std::endl
            << "===============" << std::endl
            << "#nodes=" << numNodes << std::endl
            << "#edges per node" << numEdges << std::endl
            << "step size for collision check " << stepSize << std::endl
            << "xStart=" << xStart << std::endl
            << "yStart=" << yStart << std::endl
            << "xGoal=" << xGoal << std::endl
            << "yGoal=" << yGoal << std::endl
            << "xMin=" << xMin << std::endl
            << "xMax=" << xMax << std::endl
            << "yMin=" << yMin << std::endl
            << "yMax=" << yMax << std::endl
            << "worldModel=\"" << worldModel << "\"" << std::endl
            << std::endl
            << "Reading problem specification file \""
            << probSpecFile << "\"" << std::endl << std::endl;
    
    

  if (!world->readObstacles(fs)) {
      
        
    std::cerr << "Failed to read obstacle, exiting\n";
      
     
    return -1;
  }
  fs.close();
    
    
  std::cout<<"Number of obstacles created: "<< Obstacle::objectCount << std::endl;
  
  PRM prm;

  std::list<Position> path;

  // Build the road map used for planning. This map could be used for
  // several queries.
  prm.buildRoadMap(*world, 
                   xMin, xMax, yMin, yMax,
                   numNodes, numEdges, stepSize);

  // Try to find a path
  bool foundPath = prm.findPath(*world, xStart, yStart, xGoal, yGoal, path);

  if (foundPath) {
    std::cout << "Found a path with "
              << path.size() 
              << " nodes, look at it by running dispPRM in matlab"
              << std::endl << std::endl;
  } else {
    std::cerr << "DID NOT FIND A PATH, you may want to try again\n\n";
  }
    
  std::cout<<"mark1\n";


  // We output matlab code so that the problem can be visualized
  std::fstream matlabCode;
  matlabCode.open("dispPRM.m", std::ios::out);
  matlabCode << "% Automatically generated by solvePlanningProblem using\n"
             << "% #nodes=" << numNodes << std::endl
             << "% #edges per node" << numEdges << std::endl
             << "% step size for collision check " << stepSize << std::endl
             << "% xMin=" << xMin << std::endl
             << "% xMax=" << xMax << std::endl
             << "% yMin=" << yMin << std::endl
             << "% yMax=" << yMax << std::endl
             << "% worldModel=\"" << worldModel << "\"" << std::endl
             << "% problem spec file \"" << probSpecFile << "\"\n\n";
  matlabCode << "clf\nhold on\n";

  world->writeMatlabDisplayCode(matlabCode);

  if (!foundPath) {
    // If we did not find a path we show the edges as well always
    prm.writeMatlabDisplayCode(matlabCode, true);
  } else {
    prm.writeMatlabDisplayCode(matlabCode, alwaysDisplayEdges);
  
    std::list<Position>::iterator p1, p2;    
    for (p1 = path.begin(), p2 = p1, p2++; p2 != path.end(); p1++, p2++) {
      matlabCode << "plot(["
                 << p1->getX() << ", "
                 << p2->getX() << "], ["
                 << p1->getY() << ", "
                 << p2->getY() << "], 'r', 'LineWidth', 2)\n";
    }
  }

  matlabCode << "text(" << xStart << ", " << yStart 
             << ",\'S\',\'FontSize\',12)\n";
  matlabCode << "text(" << xGoal << ", " << yGoal 
             << ",\'G\',\'FontSize\',12)\n";
  
  matlabCode << "hold off\n";
  matlabCode << "title(\'Number of nodes is "
             << numNodes << " and K (number of edge attempts) is "
             << numEdges << "\')\n";
  matlabCode << "axis equal";
  
  matlabCode.close();

  delete world;
  return 0;
}
