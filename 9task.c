#include <stdio.h>
#include <string.h>
#include <stdlib.h>     /* atof */


void f1();
void f2();
int main()
{
    printf("Task 9.1\n ");


    int const char_size=10;
    
    char num[char_size];
    double n;

    int  game=1;
    char cont;
   
    while(game)
    {
        printf("Type a number i.e -39.92 934.8  932 -1: ");
//        char *num_point;
//        scanf("%s",&num_point);
//        printf("The first char is  is: %c\n",num_point);
//        printf("The first char is  is: %c\n",++num_point);

        fgets (num, sizeof(num), stdin); //read a string from keyboar, put in on array
//        printf("num[0] is: %c\n",num[0]);
//        printf("num[1] is: %c\n",num[1]);
        
        n=atof(num);
        n*=10;
        printf("the number is %.4f\n",n);

        printf("Do you need to get another number y/n:");
        scanf("%s",&cont);
        if (cont=='y' || cont=='Y')
            game=1;
        else
            game=0;
        getchar();//clear stdin for the next fgets

    };
    printf("\nValues for locals functions\n");
    printf("f1 first call\n");
    f1();
    printf("f1 second call\n");
    f1();
    
    printf("f2 first call\n");
    f2();
    printf("f2 second call\n");
    f2();
    
    return 0;
} //close-Main

void f1()
{
    int a;
    printf("f1 1 the value of a is: %d\n",a);
    a=5;
    printf("f1 2 the value of a should be 5 and is: %d\n",a);
    return;
}


void f2()
{
    int b;
    printf("f2 1 the value of a is: %d\n",b);
    b=7;
    printf("f2 2 the value of a should be 7 and is: %d\n",b);
    return;
}
