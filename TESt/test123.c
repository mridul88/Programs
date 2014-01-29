#include<stdio.h>

int main()
{
    int *p;
    p=malloc(sizeof(int)*5);
    p[0]=-5;
    p[1]=-7;
    p[2]=3;
    p[3]=4;
    p[4]=5;
    p=p+3;
    free(p);
    printf("%p %u",p,0);
    getchar();
    return 0;
}
