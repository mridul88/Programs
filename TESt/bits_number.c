#include<stdio.h>

int main()
{
    int i,n,ans=0,temp=0;
    scanf("%d",&n);
    if(n&(n-1)==0)
    {
             ans=n/2;
    }
    else
    {     
          for(i=1;i<32;i++)
          {
               temp= n&(1<<i);
               if(temp>0)
               {
                      ans=ans + (1<<(i-1));
                      printf("%d  ans=%d\n",1<<(i-1),ans);
               }   
          }
          if(n%2!=0)
               ans++;
    }
    printf("%d",ans);
    getchar();
    getchar();
    return 0;
}            
