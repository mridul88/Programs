#include<stdio.h>
/* In am maze, therea are gold coins distributed;
   you can move only in right or down, collect as many points as u can
   
   DP Problem
   
   value(i,j)= max( value(i-1,j), value(i,j-1)) + value (i,j);
   path can be found, at each location which oint we seelcted
   
    PROBLEM 
    How to pass 2d dynamic allocated array to a function;
    you can pass using int **a; but this a points to some other location;
    
    in case of static array, we can as: int  a[][10] || int (*a)[10] 
    and also lile int *a -> here acess 2d array elemnts as a[i*row+col];
    
    */

int max(int a,int b)
{
    return(a>b?a:b);
}
 
int maxcoins(int m,int n,int a[10][10]) // learn how to pass a 2d array, int a[][10] is correct 
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
         a[0][i+1]+=a[0][i];
         a[i+1][0]+=a[i][0];
    }
    for(i=1;i<m;i++)
    {
          for(j=1;j<n;j++)
          {
                 a[i][j]=max(a[i-1][j],a[i][j-1]) + a[i][j];
                // printf("%d\n",a[i][j]);
          }
    }
    return a[m-1][n-1];
}                              

int main()
{
    int a[10][10],m,n,i,j;
    printf("Enter the row,column of maze\n");
    scanf("%d%d",&m,&n);
    /*a=(int **)malloc(sizeof(int)*m);
    for(i=0;i<m;i++)
    {
            a[i]=(int *)malloc(sizeof(int)*n);
    }*/
    for(i=0;i<m;i++)
    {
             for(j=0;j<n;j++)
             {
                     scanf("%d",&a[i][j]);
             }
    }

    printf("\n\n MAX=%d\n",maxcoins(m,n,a));
    getchar();
    getchar();
    return 0;
}                
