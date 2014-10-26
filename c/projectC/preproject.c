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

void text_write();
float text_read();

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
    
    text_write();
    while(1)
    {
        float num;
        num=text_read();
        printf("\nnew paramenter from text file: %f\n\n",num);
        delay(4);//delay in miliseconds
    }
    
    
    printf("\n******END******\n\n");
    
    return 0;
}


void text_write()
{
    printf("Task 12 write to a file \n ");
    double x=1, y=2, theta=0.5;
    FILE *fd = NULL;
    fd = fopen("test.txt", "w");
    /////////////////CREATE A FILE/////////////////
    fprintf(fd, "Robot pose is %f %f %f\n", x,y,theta);
    fclose(fd);
    printf("write: Robot pose is %f %f %f\n", x,y,theta);
    return;
}
float text_read()
{
    /////////////////READ A FILE/////////////////
    double a,b,c;
    FILE *fe = NULL;
    fe = fopen("test.txt", "r");
    fscanf(fe, "Robot pose is %lf %lf %lf\n",&a,&b,&c);
    fclose(fe);
    printf("I read: Robot pose is %lf %lf %lf\n",a,b,c);
    return a;
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