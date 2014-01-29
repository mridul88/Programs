//--------its solution too the easy question factorial in codechef---
#include<stdio.h>

int z(int n)
{
      int z=0,f=5;
      while(f<=n)
      {
              z=z+n/f;
              f=f*5;
      }       
      return z;
}
      
int main()
{
      int n,t;
      scanf("%d",&t);
      while(t--)
      {
                scanf("%d",&n);
                printf("%d\n",z(n));
      }
      /*for(t=0;t<i;t++)
      {
                  printf("%d\n",a[t]);
      } 
      getchar();
      getchar();*/
      return 0;
}
                
