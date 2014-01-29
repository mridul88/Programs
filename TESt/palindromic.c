/*First Program*/
#include<stdio.h>
#include<math.h>

int main()
{
    int t,flag;
    long long i,b,n;
    scanf("%d",&t);
    while(t-- > 0)
    {
              scanf("%lld", &n);
              flag=0;
              b=n-1;
              if( n==1  || n==3 || n==5 )
              {
                   b=2;
                   flag=1;
              }
              
              else if( n==2  || n==4 )
              {
                   b=3;
                   flag=1;
              }
              
              else if( n==6)
              {
                   b=5;
                   flag=1;
              }
              else
              {
                 for( i = 2; i<n/2 ; i++) 
                  {
                      if( n%i == 0) 
                      {
                              b = n/i-1;
                              flag=1;
                      }
                  }                      
                        
              } 
              if(flag==0)
              {
                         b=sqrt(n)-1;
              }
              
              printf("%lld\n",b);  
    }
    return 0;   
}
