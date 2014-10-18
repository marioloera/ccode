#include <stdio.h>

int factorial(int);
int main()
{
    int x,a;
    int  game;
    char cont;
    do{
        printf("New version for git ");
        printf("Type in a number to get the factorial: ");
        scanf("%d",&a);
        //printf("you type %d\n",a);
        x=factorial(a);
        printf("The factorial of %d is %d\n",a,x);
        printf("Do you need to get another number y/n: ? ");
        scanf("%s",&cont);
        if (cont=='y' || cont=='Y')
          game=1;
        else
            game=0;
    }while(game);
    return 0;
} //close-Main

int factorial(int a)
{
    int result =1;
  //printf("funtion %d\n",a);
  if (a>1)
  {
        result=a*factorial(a-1);
        //printf("funtion %d\n",a);
  }
  return result;
}
