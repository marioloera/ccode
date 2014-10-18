#include <stdio.h>
#include "function3.h"
int main()
{
    int x,a;
    int  game;
    char cont;
    do{
        printf("Please type in a number to get the factorial: ");
        scanf("%d",&a);
        //printf("you type %d\n",a);
	x=newName(a);
        printf("The factorial of %d is %d\n",a,x);
        getchar();//clean buffer for new scanf
        printf("Do you need to get another number y/n:");
        scanf("%s",&cont);
        if (cont=='y' || cont=='Y')
          game=1;
        else
            game=0;
	getchar();
    }while(game);
    return 0;
} //close-Main

