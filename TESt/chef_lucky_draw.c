#include<stdio.h>

#define MAX 1000

int a[MAX],ans[MAX];

void solve(int n)
{
     int i,curr,j,ld[2][MAX],N;
     //  memset(ld,51,8000);  learn how to use memeset
     
     for(i=0;i<n;i++)
     {
            ld[0][i]=ld[1][i]=1;
            printf("ld_1=%d    ld_2=%d    ans=%d\n",ld[0][i],ld[1][i],ans[i]);
     }  
     
     
     for(i=0;i<n;i++)  // longest decreasing subsequence starting from a[0]
     {
           curr=0;
           for(j=0;j<i;j++)
           {
                  if(a[j]>a[i] && ld[0][j]>curr)
                  {
                      curr=ld[0][j];
                  }
           }
           ld[0][i]=curr+1;
     }
     
     for(i=n-1;i>=0;i--)  // longest decreasing subsequence starting from a[n]
     {
           curr=0;
           for(j=n-1;j>i;j--)
           {
           //       printf("---a[i]=%d  a[j]=%d\n",a[i],a[j]);
                  if(a[j]>a[i] && ld[1][j]>curr)
                  {
                      curr=ld[1][j];
             //         printf("j=%d  i=%d  curr=%d",j,i,curr);
                  }
           }
           ld[1][i]=curr+1;
     }
                                                   
     for(i=0;i<n;i++)
     {
             ans[i]=ld[0][i] + ld[1][i] - 1;
     }
     
     for(i=0;i<n;i++)
     {
            printf("ld_1=%d    ld_2=%d    ans=%d\n",ld[0][i],ld[1][i],ans[i]);
     }         
     return;
}        
     
int main()
{
    int t,n,i,max;
    scanf("%d",&t);
    while(t--)
    {
          scanf("%d",&n);
          for(i=0;i<n;i++)
          {
              scanf("%d",&a[i]);
          }
     
          solve(n);
     
          max=ans[0];
          for(i=0;i<n;i++)
          {
                  if(ans[i]>max)
                      max=ans[i];
          }        
          printf("%d\n",max);
    }
    getchar();
    getchar();
    getchar();
    getchar();
    return 0;
}                
