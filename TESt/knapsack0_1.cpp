//- knapsack 0/1 problem as given in cormen question greedy ch.-----------//

#include<cstdio>
#include<cstdlib>

using namespace std;

void print(int,int);

struct node
{
       int w,p;
}typedef cell;

int a[100][100];

int knapsack(cell* list,int n,int W)
{
    int temp,i,j;
    /*a= (int **)malloc(sizeof(int)*(n+1));
    for(i=0;i<=n;i++)
    {
              *a=(int *)malloc(sizeof(int)*(W+1));
    }*/
    for(i=0;i<=W;i++)
    {
             a[0][i]=0;
             //printf("%d ",a[0][i]);
    }
    for(i=1;i<=n;i++)
    {
              a[i][0]=0;
              for(j=1;j<=W;j++)
              {
                          if(list[i].w<=j)
                          {
                                 if( (a[i-1][j-list[i].w] + list[i].p) > a[i-1][j] )
                                     a[i][j]=a[i-1][j-list[i].w] + list[i].p;      
                                 else
                                     a[i][j]=a[i-1][j];
                          }
                          else
                          {
                                 a[i][j]=a[i-1][j];
                          }  
              }
             // print(n,W);
    }
    printf("max profit=%d\n",a[n][W]);                   
    return 0;
}

void print(int n,int W)
{
     for(int i=0;i<=n;i++)
     {
             for(int j=0;j<=W;j++)
             {
                     printf("%5d ",a[i][j]);
             }
             printf("\n");
     } 
     printf("\n\n\n");
} 

int main()
{
    int w,n;
    cell *list;
    printf("weigt,profit");
    scanf("%d %d",&n,&w);
    list= new cell[n+1];
    for(int i=1;i<=n;i++)
    {
            scanf("%d %d",&list[i].w,&list[i].p);
    }
    knapsack(list,n,w);
    getchar();
    getchar();
    return 0;
}
    
