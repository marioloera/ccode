#include <stdio.h>
#include <string.h>

int main()
{
    printf("Task 12 write to a file \n ");
    double x=1, y=2, theta=0.5;
    FILE *fd = NULL;
    fd = fopen("test.txt", "w");
    /////////////////CREATE A FILE/////////////////
    fprintf(fd, "Robot pose is %f %f %f\n", x,y,theta);
    fclose(fd);
    /////////////////READ A FILE/////////////////
    double a,b,c;
    FILE *fe = NULL;
    fe = fopen("test.txt", "r");
    fscanf(fe, "Robot pose is %lf %lf %lf\n",&a,&b,&c);
    fclose(fe);
    
    printf("I read: Robot pose is %lf %lf %lf\n",a,b,c);
    return 0;
}


