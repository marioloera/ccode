#include <stdio.h>//add library
#include <stdlib.h>
#include <time.h>

#define maxRand 9//limit for higher random number 
main()//main funtion

{
   	/* Intializes random number generator */
	printf("time: %d\n",time(NULL));
   	time_t t;
	srand((unsigned) time(&t));
	
	int numRandom=rand()%(maxRand+1);
	printf("Random number [0,%d]=%4d\n",maxRand,numRandom);
	switch (numRandom)
	{
		case 0:
			printf("random is zero\n");
			break;	
		case 1:
			printf("random is one\n");
			break;
		default:
			printf("randon is betwen 2 and %d\n",maxRand);
	}
	printf("print time=%f\n",time(NULL));
//print table of themperatures F=32+9/5*C;
	int c;
	printf("Celcius  Fahernheit\n");
	float f;
	for(c=-10;c<=10;c++)
	{
		f=32+9.0*c/5.0;
		printf("%7d%12.2f\n",c,f);
	}

}//close main funtion

