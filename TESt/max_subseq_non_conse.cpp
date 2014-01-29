#include<cstdio>

using namespace std;

int main()
{
      int n,i,j=0,*a,*m;
      scanf("%d",&n);
      a=new int[n];
      m=new int[n];
      for(i=0;i<n;i++)
      {
              scanf("%d",&a[i]);
      } 
      for(i=n-1;a[n-1]<0&&i>=0;i--);
      if(i<0)
      {
              m[0]=-89868;
              for(i=0;i<n;i++)
              {
                     if(a[i]>m[0])
                     {
                             m[0]=a[i];
                             j=i;
                     }
              }
              printf("Max Sum= %d   at index %d",m[0],j+1);
                while (getchar()!='\n');
               getchar();
               getchar();
              return 0;
      }         
      
      m[i]=a[n-1];
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
      while (getchar()!='\n');
      getchar();
      getchar();
      return 0;
}                     
      
      
      
