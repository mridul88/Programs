#include<stdio.h>

int main()
{
      int *s,i=2,j=4,k=9,*p=&i,*q=&j,*r=&k;
      
      (int *)s=(unsigned int)p +(unsigned int)q;
      (int *)s=(unsigned int)s -(unsigned int)p;
      printf("%d",*s);
      getchar();
      return 0;
}
      
      
