#include<stdio.h>

int main()
{
    int i,t,n,a[700],count=0;
    scanf("%d",&t);
    while(t--)
    {
          scanf("%d",&n);
          if(n<10)
          {
                n=10+n;
                printf("%d\n",n);
                continue;
          }
          while(n>1)
          {
                 for(i=9;i>0;i--)
                 {
                       if(n%i==0)
                       {
                              n=n/i;
                              a[count++]=i;
                              break;
                       }
                 }
          }
          for(i=0;i<count;i++)
              printf("%d ",a[i]);
    }                  
                        
    getchar();
    getchar();
    return 0;
}
