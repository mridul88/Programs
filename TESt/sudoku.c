#include<stdio.h>
#include<math.h>
#define N 9;

struct cell
{
      int key,set;
};

struct cell m[9][9];

int canPlace(int i,int j,int key,int n,int row_s,int col_s)
{
    int flag=1,a,b,start_r=0,start_c=0,sqrt_n;
   
    for(a=0;a<n;a++)
    {
             if(m[i][a].key==key)
             {
                     //  printf("111111111_");           
                      return 0;
             }
    }  
    for(a=0;a<n;a++)
    {
             if(m[a][j].key==key)
              {
                      // printf("2222222_");           
                      return 0;
             }
    }    
    while( (i-start_r)+1 > row_s)
        start_r+= row_s;
    while( (j-start_c)+1 > col_s )
        start_c+= col_s;
    
   // printf("%d %d\n",start_r,start_c);
    for(a=start_r;a<start_r + row_s && a<n;a++)
    {
             for(b=start_c;b<start_c + col_s && b<n ;b++)
             {
                             if(m[a][b].key==key)
                                  {
                       //            printf("3333333_");           
                                        return 0;
                       }
             }
    }
    return 1;
}                   
  
int print(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
                    for(j=0;j<n;j++)
                    {
                                    printf("%d   ",m[i][j].key);
                    }
                    printf("\n");
    }
    return 0;
} 
        
void sudoku(int i,int j,int n,int a,int b)
{
    int k;
    if(m[i][j].set==1)
    {
            if(j==n-1)
                     sudoku(i+1,0,n,a,b);
            else
                     sudoku(i,j+1,n,a,b);
            return;
    }
    for(k=1;k<=n;k++)
    {
              if( canPlace(i,j,k,n,a,b))
              {
                     // printf(" Yes Placed %d at m[%d][%d]\n",k,i,j);
                      m[i][j].key=k;
                      if(i==n-1 && j==n-1)
                      {
                                print(n);
                      }
                      else if(j==n-1)
                            sudoku(i+1,0,n,a,b);
                     else
                            sudoku(i,j+1,n,a,b);
              }
    }
    return;
}

                     
                              
int main()
{
    int n,i,j,a,b;
    printf("enter the sudoku matrix size and matrix");
    scanf("%d %d %d",&n,&a,&b);
    for(i=0;i<n;i++)
    {
         for(j=0;j<n;j++)
         {
                // scanf("%d",&m[i][j].key);
                  m[i][j].key=0;
                 if(m[i][j].key!=0)
                      m[i][j].set=1;
                 else
                         m[i][j].set=0;
         }
    }
    print(n);
    sudoku(0,0,n,a,b);
    system("pause");
    return 0;
}         
                                     
