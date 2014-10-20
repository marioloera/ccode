#include <stdio.h>
//#include <string.h>
//#include <math.h>
//#include <stdlib.h>

int clamp_int(int value, int low, int high){
    return value < low ? low : (value > high ? high : value);}

double clamp_double(double value, double low, double high){
    return value < low ? low : (value > high ? high : value);}

struct position
{
    double x;
    double y;
};
struct line
{
    struct position start;
    struct position end;
};

int const N=100;
struct pos
{
    double x;
    double y;
    double z;
};
struct vel
{
    double x;
    double y;
    double z;

};

struct boild
{
    struct pos;
    struct vel;
    
};

struct boild b[N];
struct boild *bp=&b[0];

void delay(int max);

void print_pointer(struct line *local)
{
    printf("L[2].start.y=89 = %f\n",local[2].start.y);
    return;
}

void update_pointer(struct line *local,double a)
{
    local[2].start.y=a;
    return;
}

void write_parameters();
double * read_parameters();

int main()
{
    //clam funtion
    printf("Funtion clamp\n");
    int val=300;
    val=clamp_int(val,0,100);
    printf("val=300; val=clamp(val,0,100)=%d\n",val);
    
    double q=-300.3;
    q=clamp_double(q,0.2,100);
    printf("val=-300; val=clamp(val,0,100)=%.2f\n",q);
    
    //Struct\n");
    printf("\nStruct\n");

    
    struct position po;
    po.y=39;
    po.x=40;
    printf("po.y=%f\npo.x=%f\n",po.y,po.x);
    
    //pointer to a array of structure\n");
    printf("\npointer to a array of structure\n");
    struct position man[10];
    man[0].x=302;
    man[9].y=23;
    struct position *manptr=&man[0];
    printf("man[9].y=23 : %f\n",manptr[9].y);
    
    //structure of structure
    printf("\nstructure of structure\n");

    struct line li;
    li.start.x=7.3;
    struct line *lp=&li;
    lp->start.y=9;
    printf("l.start.x=%f\nlp->start.y=%f\n",li.start.x,lp->start.y);
    
    //pointer to a array of structure of structre\n");
    printf("\npointer to a array of structure of structure \n");
    struct line L[3];
    struct line *Lp=&L[0];
    L[3].end.x=30;
    L[2].start.y=89;
    printf("L[3].end.x=30 = %f\n",Lp[3].end.x);
    printf("L[2].start.y=89 = %f\n",Lp[2].start.y);

    //pointer to a array of structure of structre Funtion\n");
    printf("\npointer to a array of structure of structure Funtion\n");
    update_pointer(Lp,23.34);
    print_pointer(Lp);
    
    write_parameters();
    while(1)
    {
        double * param=read_parameters();//pointer to acces the parameters
            //* param    = k_centre
            //* (param+1)= k_repulsion
            //* (param+2)= k_cohesion
            //* (param+3)= k_target
            //* (param+4)= V_MAX
            //* (param+5)= REPULSION_DISTANCE
        
        printf("\nnew paramenter from text file: %lf %lf %lf %lf %lf \n\n",*param, *(param+2), *(param+3), *(param+4), *(param+5));
        delay(4);//delay in miliseconds
    }
    return 0;
}


void write_parameters()
{
    printf("Task 12 write to a file \n ");
    FILE *fw = NULL;
    fw = fopen("parameters_boids.txt", "w");
    /////////////////CREATE A FILE/////////////////
    fprintf(fw, "k_centre = 0.0001\nk_repulsion = 0.5\nk_cohesion = 0.00025\nk_target = 0.005\nV_MAX = 45.0\nREPULSION_DISTANCE = 30.0");
    fclose(fw);
    return;
}
double * read_parameters()
{
    static double parameters[6];//static point to store the parameter and acces with pointer
    //* param    = k_centre
    //* (param+1)= k_repulsion
    //* (param+2)= k_cohesion
    //* (param+3)= k_target
    //* (param+4)= V_MAX
    //* (param+5)= REPULSION_DISTANCE
    /////////////////READ A FILE/////////////////
    FILE *fr = NULL;
    fr = fopen("parameters_boids.txt", "r");
    fscanf(fr, "k_centre = %lf\nk_repulsion = %lf\nk_cohesion = %lf\nk_target = %lf\nV_MAX = %lf\nREPULSION_DISTANCE = %lf",&parameters[0],&parameters[1],&parameters[2],&parameters[3],&parameters[4],&parameters[5]);
    fclose(fr);
    //printf("I read parameters: %lf %lf %lf %lf %lf %lf \n",parameters[0],parameters[1],parameters[2],parameters[3],parameters[4],parameters[5]);
    return &parameters[0];//return a point to the first element of the array
}

void delay(int max)
{
    int i;
    for (i=0;i<100000000*max;i++)
    {
        //printf("\ni=%d\n",i);
    }
    return;
}