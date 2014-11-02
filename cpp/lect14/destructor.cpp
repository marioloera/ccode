#include <iostream>
//destructor can neither return a value nor can it take any parameters. 
//useful for releasing resources: closing files, releasing memories etc.

using namespace std;
 
class B
{
   public:
      void setLength( double len );
      double getLength( void );
      B();   // This is the constructor declaration
      ~B();  // This is the destructor: declaration
 
   private:
      double length;
};
 
B::B(void)
{
    cout << "Object is being created" << endl;
}
B::~B(void)
{
    cout << "Object is being deleted" << endl;
}
 
void B::setLength( double len )
{
    length = len;
}
 
double B::getLength( void )
{
    return length;
}


int main( )
{
   B b;

   b.setLength(5.0); 
   cout << "Length : " << b.getLength() <<endl;
 
   return 0;
}