#include <stdio.h>//add library

main()//main funtion

{

int numero=10;
float decima=98.463;
char letra='a';

int a,x,y,z;
short int b=1;
long int c=1;


	printf("Helo world!\n");//print on the scrren
	printf("numero =%4d, decimal=%.3f\n",numero,decima);//print on the scrren
	printf("numero =%6d, decimal=%010.3f\n",numero,decima);	
        printf("numero =%6d, decimal=%10.5f\n",numero*numero,decima);
//	prinrf("print the characther z=%c\n",letra);
	printf("print hexadecimal=%x\n",numero+1);
	printf("print octal value=%o\n",8);

	a=sizeof(int);
	x=sizeof b;
	printf("size of int=%d \n ", a);
	printf("size of a=%d \n",x );
	
	printf("\n");
	printf("size of int=%d\n",sizeof(int));
       	printf("size of short int=%d\n",sizeof(short int));
	printf("size of long int=%d\n",sizeof(long int));	
	printf("size of char=%d\n",sizeof(char));

	if(-1)
		printf("the logical condition of -1 is true\n");
			
	else
		printf("the logical condition of -1 is false\n");

}//close main funtion

