int factorial(int a)
{
    int result =1;
     // printf("funtion %d\n",a);
        if (a>1)
        {
              result=a*factorial(a-1);
        }
     return result;
}

