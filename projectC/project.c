#include <stdio.h>
//#include <string.h>
//#include <math.h>
//#include <stdlib.h>

#include "boild.h" //definitions of structure, functions


void write_parameters();
double * read_parameters();

int main()
{
    write_parameters();
    
    //pointer to a array of structure of structre Funtion\n");
    printf("Modifiy structure values b[0].pos.x=843.32 \n");
    b[0].pos.x=843.32;
    bp[1].vel.y=3;
    
    printf("Acces structure values\n");
    printf("value b[0].pos.x=%lf;\n",bp[0].pos.x);
    printf("value b[0].pos.x=%lf;\n",b[1].vel.y);
    
 
    
    while(1)
    {
        double * param=read_parameters();//pointer to acces the parameters
            //* param    = k_centre
            //* (param+1)= k_repulsion
            //* (param+2)= k_cohesion
            //* (param+3)= k_target
            //* (param+4)= V_MAX
            //* (param+5)= REPULSION_DISTANCE
        
        printf("\nnew paramenter from text file: %lf %lf %lf %lf %lf %lf \n\n",*param,*(param+1),*(param+2), *(param+3), *(param+4), *(param+5));
        delay(3);//
    }
    return 0;
}








