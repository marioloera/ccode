//
// = FILENAME
//    World.cc
//    
// = AUTHOR(S)
//    Patric Jensfelt
//
/*----------------------------------------------------------------------*/

#include "World.hh"

#include <iostream>

World::World()
{std::cout << "call constructor World"  << std::endl;}

World::~World()
{}

bool World::readObstacles(std::istream &fs)
{
    
  std::cerr << std::endl
            << "World::readObstacles this function has not been overloaded"
            << std::endl
            << "and there thus is no way to read obstacles from file."
            << std::endl
            << "A static map may be in use" << std::endl << std::endl;
  return true;
}

void World::writeMatlabDisplayCode(std::ostream &fs)
{
  std::cerr << std::endl
            << "World::writeMatlabDisplayCode not overloaded"
            << std::endl
            << "Not writing any matlab code"
            << std::endl << std::endl;
}
