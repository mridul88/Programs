//--matrix multiplication program using cormen---------//

#include<cstdio>
#define SIZE 6

int c[SIZE][SIZE]={0},s[SIZE][SIZE]={0};
void print();

int matrix_mul(int *p,int n)
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
    int i,n,*p;
    printf("enetr the number of matrices");
    scanf("%d",&n);
    p=new int[n+1];
    for(i=0;i<=n;i++)
    {
          scanf("%d",&p[i]);
    }
    matrix_mul(p,n); 
    printf("%d",c[0][n-1]);  
    print_seq(0,n-1);
    getchar();
    getchar();
    return 0;
}        
