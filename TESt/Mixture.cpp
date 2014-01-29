//-- Mixture Problem on codechef(medium level) using concept of matrix multiplication program using cormen---------//

#include<cstdio>

using namespace std;

int s[100][100]={0},c[100][100]={0};

int max_smoke(int *p,int n)
{
    int temp,i,j,k,len;
    for(i=0;i<n;i++)
    {
           c[i][i]=p[i];
    }         
    for(len=1;len<n;len++)
    {        
          for(i=0;i<n-len;i++)
          {
                   j=i+len;
                  // printf("i=%d, j=%d\n",i,j);
                   s[i][j]= ~(1<<31);
                   for(k=i;k<j;k++)
                   {
                         temp=s[i][k]+s[k+1][j]+ c[i][k]*c[k+1][j];
                         if(s[i][j]>temp)
                         {
                                  s[i][j]=temp;
                                  c[i][j]= (c[i][k]+c[k+1][j])%100;
                         }
                   }
                  // print();
          }
    }
    return 0;
}         

/*void print()
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
}*/
         
     
    
int main()
{
    int i,n,*p,ans[1000],j=0;
    while(scanf("%d",&n)!= EOF)
    {
           p=new int[n];                   
           for(i=0;i<n;i++)
           {
                scanf("%d",&p[i]);
           }
           max_smoke(p,n);
           ans[j]=s[0][n-1];
           j++; 
    } 
    for(i=0;i<j;i++)
    {
              printf("%d\n",ans[i]);
    }      
    return 0;
}        
