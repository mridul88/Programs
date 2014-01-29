#include<stdio.h>

int main()
{
      int *s,i=2,j=4,k=9,*p=&i,*q=&j,*r=&k;
      s=p^q;
      s=s^p;
      printf("%d",*s);
      getchar();
      return 0;
}
      
      
