#include<stdio.h>

int original_order(int w[],int a[],int n)
{
      int i,j,k,adjust[20001]={-1},temp=0;
      
      for(i=1;i<=n;i++)
      {
              adjust[i]=-1;
      }
      adjust[0]=0;
      adjust[n-w[n]]=0;
      for(i=n;i>0;i--)
      {
               k=i-w[i];       
               for(;adjust[k]==-1;k--);
               printf("i=%d,k=%d  ",i,k);
               a[i]=(i-w[i])+adjust[k];
               if(w[i]>0)
                    adjust[i-1]=adjust[i]+1;
               adjust[i-w[i]]=(adjust[i-w[i]+1]==-1?1:adjust[i-w[i]+1]+1); 
               
               for(j=1;j<=n;j++)
      {
         printf("%d ",adjust[j]);
      }
      printf("\n");

/*                    int temp,k;
                    k=i-w[i];
                    temp=a[k];
                    for(j= w[i];j>0;j--)
                    {
                          a[k]=a[k+1];
                          k++;
                    }
                    a[i]=temp;*/
      }
      for(i=1;i<=n;i++)
      {
         printf("%d ",a[i]);
      }
      return 0;
}                                                   

int main()
{
      int t;
      //scanf("%d",&t);
      t=1;
      while(t--)
      {
              int i,n,w[200001],a[200001];  
              scanf("%d",&n);
              for(i=1;i<=n;i++)
              {
                       scanf("%d",&w[i]);
                       //w[i]=i-1;
              }
              
              original_order(w,a,n);
              
      }         
      getchar();
      getchar();
      return 0;
}
      
