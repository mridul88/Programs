#include<stdio.h>

int main()
{
      int n,i,state=0;
      scanf("%d",&n);
      for(i=2;i<n;i++)
      {
              if(n%i==0)
                   state=(state==0?1:0);
      }
      (state==0?printf("No"):printf("Yes"));
      getchar();
      getchar();
      return 0;
}        
