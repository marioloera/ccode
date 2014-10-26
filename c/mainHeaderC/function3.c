#include "function3.h"

int newName(int num)
{
    int result =1;
     // printf("funtion %d\n",num);
        if (num>1)
        {
              result=num*newName(num-1);
        }
     return result;
}

