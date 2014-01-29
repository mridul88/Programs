//-- Mixture Problem on codechef(medium level) using concept of matrix multiplication program using cormen---------//

#include<cstdio>

int max_smoke(int *p,int n)
{
    int temp,i,j,k,len;
    for(len=1;len<n;len++)
    {        
          for(i=0;i<n-len;i++)
          {
                   j=i+len;
                   printf("i=%d, j=%d\n",i,j);
                   c[i][j]= ~(1<<31);
                   for(k=i;k<j;k++)
                   {
                         temp=c[i][k]+c[k+1][j]+ p[i]*p[j+1]*p[k+1];
                         if(c[i][j]>temp)
                         {
                                  c[i][j]=temp;
                                  s[i][j]=k;
                         }
                   }
                   print();
          }
    }
    return 0;
}         

void print()
{
     for(int i=0;i<SIZE;i++)
     {
             for(int j=0;j<SIZE;j++)
             {
                     printf("%5d ",c[i][j]);
             }
             printf("\n");
     } 
     printf("\n\n\n");
}                    

void print_seq(int b,int e)
{
     if(b==e)
     {
             printf("A%d",b);
             return;
     }
     else
     {
         printf("( ");
         print_seq(b,s[b][e]);
         print_seq(s[b][e]+1,e);
         printf(" )");
     }
}
         
     
    
int main()
{
    int i,n,*p,**s,**c,**a;
    while(scanf("%d",&n)!=EOF)
    {
           p=new int[n+1];
           *a=new (int *)[n];
           for(i=0;i<=n;i++)
           {
                scanf("%d",&p[i]);
           }
           max_sum(p,n); 
    printf("%d",c[0][n-1]);  
    print_seq(0,n-1);
    getchar();
    getchar();
    return 0;
}        
