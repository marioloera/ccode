#include <stdio.h>


int main()
{
    
    int C[2][2]={{1,3},{2,4}};
    //int B[2][1]={10,20};//declare matrix
    //int B[1][2]={10,20};//declare matrix
    int B[3][2]={1,2,3,4,5,6};//declare matrix
    
    
    int NumRowC=sizeof(C)/sizeof(C[0]);
    int NumColC=sizeof(C[0])/sizeof(C[0][0]);
    int NumRowB=sizeof(B)/sizeof(B[0]);
    int NumColB=sizeof(B[0])/sizeof(B[0][0]);
    
    int n,x,y;//delcare counters
        printf("NumRowC=%d, NumColC=%d\n",NumRowC,NumColC);
    
    
    //print C
    printf("C[%d][%d]=\n",NumRowC,NumColC);
    for(y=0;y<NumRowC;y++)
    {
        for(x=0;x<NumColC;x++)
            printf("%3d",C[y][x]);
        printf("\n");
    }
    

    printf("NumRowB=%d, NumColB=%d\n",NumRowB,NumColB);
    
    //print b
    printf("B[%d][%d]=\n",NumRowB,NumColB);
    for(y=0;y<NumRowB;y++)
    {
        for(x=0;x<NumColB;x++)
            printf("%3d",B[y][x]);
        printf("\n");
    }

    //matrix multiplication B*C ---> NumColB==NumRowC
    if(NumColB==NumRowC)
    {
        int BC[NumRowB][NumColC];
        printf("multiplicacion B*C[%d][%d]=\n",NumRowB,NumColC);
        for(y=0;y<NumRowB;y++)
        {
            for(x=0;x<NumColC;x++)
            {
                BC[y][x]=0;
                for(n=0;n<NumColB;n++)
                    BC[y][x]+=B[y][n]*C[n][x];
                printf("%4d",BC[y][x]);
            }
            printf("\n");
        }
        
    }else
    {
        printf("multiplicacion B*C not posible\n");
    }
    //matrix multiplication C*B ---> NumColC==NumRowB
    
    if(NumColC==NumRowB)
    {
        int CB[NumRowC][NumColB];
        printf("multiplicacion C*B[%d][%d]=\n",NumRowC,NumColB);
        for(y=0;y<NumRowC;y++)
        {
            for(x=0;x<NumColB;x++)
            {
                CB[y][x]=0;
                for(n=0;n<NumColC;n++)
                    CB[y][x]+=C[y][n]*B[n][x];
                printf("%4d",CB[y][x]);
            }
            printf("\n");
        }
    }else
        printf("multiplicacion C*B not posible\n");

    
    
    return 0;
} //close-Main

