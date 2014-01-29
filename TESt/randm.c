#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
    int i;
    float k;
    for(i=0;i<100;i++)
    {
                      k=(float)rand()/RAND_MAX - 0.5;
                       printf("%f\n",k); 
    }
    getchar();
    getchar();
    return 0;
}                      
