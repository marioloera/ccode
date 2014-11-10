#include <stdio.h>
#include <string.h>
#include <stdlib.h>     /* atof */


int * f1(char *new_pointer,int l);


//acces a funtion with pointers
int add(int x, int y)
{   printf("add\n");
    return x+y;
}

int sub(int x, int y)
{   printf("sub\n");
    return x-y;
}



int main()
{
    printf("Task 11 \n ");
    
    //task 10.3 acces a funtion with pointers.
    int (*f[2])(int,int)={&add,&sub};

    int x=0x0f;
    int y=0x0a;
    
    //printf("hexadecima sum %x + %x =%x\n",x,y,x+y);
    printf("hexadecima sum %x + %x =%x\n",x,y,(*f)(x,y));
    
    printf("hexadecima sub %x - %x =%x\n",x,y,(*(f+1))(x,y));
    printf("hexadecima sub %x - %x =%x\n",x,y,(f[1])(x,y));

    
    //define a struct
    struct person
    {
        char *name; //mas 10 characters
        int age; //years
        float height; //meter
        int grades[5];// mat, spanish, fisic, chemstry, science.
    };
    
    struct person p1 = {"Juan Perez",32,1.39,{10,9,7,10,9},};//follow the order in the structure
    struct person p2 = {.age=32, .name="toño lopez", .height=1.89}; //define the fiel in the structre;
 
    //pointer to structures
    struct person *p1_ptr = &p1;
    p1_ptr->height=2.00;
    

    
    
    printf("person p1.name: %s\n",p1_ptr->name);
    printf("person p1.age: %d\n",p1.age);
    printf("person p1.height: %.2f\n",p1.height);
    printf("person p1.grades: %d %d %d %d %d\n",p1_ptr->grades[0],p1.grades[1],p1.grades[2],p1.grades[3],p1.grades[4] );
    
 
    
    //typedef can be used to give types a new name, synonym
    typedef struct person per;
    per p3 ={.name="sandra", .height=1.70, .age=14};
    per p4,p5,p6;
    
    
    p5=p2;
    p6=p3;
    
    p4.age=45;
    p4.name="jorge torres";
    p4.height=p1.height;
    p4.grades[0]=p1_ptr->grades[0];
    
    printf("person p4.name: %s\n",p4.name);
    printf("person p4.age: %d\n",p4.age);
    printf("person p4.height: %.2f\n",p4.height);
    printf("person p1.grades: %d %d %d %d %d\n",p4.grades[0],p4.grades[1],p4.grades[2],p4.grades[3],p4.grades[4] );
    
    
    //structure of structure
    
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
    struct line l;
    l.start.x=7.3;
    struct line *lp=&l;
    lp->start.y=9;
    
    printf("\nl.start.x=%f;lp->start.y=%f\n",l.start.x,lp->start.y);

    
    

    //arrays, pointers, strings, function with pointer arrguments.
    int const char_size=10;
    
    char num[char_size];
    double n;

    int  game=1;
    char cont;
    char *num_point= NULL;
    int *p = NULL;
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
        n*=10;//n=n*10;
        printf("the number is %.4f\n",n);
        
        int i;
        int length=0;
        printf("sizeof(num)is %lu\n",sizeof(num));
        
        for (i=0;i<sizeof(num);i++)
        {
            printf("num[%d] is %c\n",i,num[i]);
            if ((!(num[i]==' ')) && (!(num[i]=='\n')))
                length++;
            else
                 break;
        }
        printf("the length number is %.d\n",length);
        
        num_point=&num[0];
        printf("pasin pointer to a function\n");
        
        //f1(&num[0],length);
        p=f1(num_point,length);

        printf("\nprint return pointer for a function p=%d\n",*p);
        printf("\nprint return pointer for a function p+%d=%d\n",2,*(p+2));
        


        printf("Do you need to get another number y/n:");
        scanf("%s",&cont);
        if (cont=='y' || cont=='Y')
            game=1;
        else
            game=0;
        getchar();//clear stdin for the next fgets

    };
    printf("\nValues for pointer function f1 functions\n");
    
    return 0;
} //close-Main

int * f1(char *local_pointer,int l)
{
    int i;
    for (i=0;i<l;i++)
    {
        //printf("num[%d] is %c\n",i,*local_pointer);
        //local_pointer++;
        printf("num[%d] is %c\n",i,local_pointer[i]);
    }
    int results[3];
    results[0]=100;
    results[1]=101;
    results[2]=102;
    int *m=&results[0];
    printf("\nprint pointer in function m=%d\n",*m);
    printf("\nprint pointer in function  m+4=%d\n",*(m+1));
    
    static int roll[3]; //static variables stay after the exit the function
    roll[0]=33;
    roll[1]=34;
    roll[2]=35;
    
    //m=&roll[0]; // =m=roll;
    m=roll;
    printf("\nprint in function static roll m=%d\n",*m);
    
    return m;
}

