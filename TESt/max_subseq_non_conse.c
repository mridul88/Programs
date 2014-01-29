#include<stdio.h>

int main()
{
      int n,i,j,*a,*m;
      scanf("%d",n);
      a=new int[n];
      m=new int[n];
      for(i=0;i<n;i++)
      {
              scanf("%d",&a[i]);
      }        
      m[n-1]=a[n-1];
      if(a[n-1]>a[n-2])
              m[n-2]=a[n-1];
      else
           m[n-2]=a[n-2];
      for(i=n-3;i>=0;i--)
      {
              if(a[i]+m[i+2]>m[i+1])
                     m[i]=a[i]+m[i+2];
              else
                    m[i]=m[i+1];
      }
      printf("Max Sum =%d",m[0]);
      return 0;
}                     
      
      
      
