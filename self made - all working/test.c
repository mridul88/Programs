#include<stdio.h>

int* ret()
{
      int i,a[8];
      for(i=0;i<8;i++)
              a[i]=3;        
      return a;
}
        
int main()
{
         int i,a[8],*u;
         for(i=0;i<8;i++)
              a[i]=2;
         u=ret();
         for(i=0;i<8;i++)
               printf("%d ",u[i]);
         getchar();
         return 0;
}
