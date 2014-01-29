#include<stdio.h>

int main()
{
    int a=5,b[10];
    int *p= &a;
    printf("%d %d %u %u",a,*p,b+1,&b+1);
    getchar();
    return 0;
}
