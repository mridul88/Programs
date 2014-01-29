#include <stdio.h>


int a[101][101][101],b[101][101][101];

int ans(int i,int j,int k)
{
     int sum=0;

    if(i>0 &&j>0 && k>0)
    {

         sum= b[i-1][j][k] + (b[i][j-1][k] - b[i-1][j-1][k])+ (  b[i][j][k-1] -b[i-1][j][k-1]) - ( b[i][j-1][k-1]-b[i-1][j-1][k-1]);
    }

    else if( i==0 && j>0 && k>0)
    {
            sum= b[i][j-1][k]+b[i][j][k-1] - b[i][j-1][k-1];
    }
    else if( j==0 && i>0 && k>0)
    {
            sum= b[i-1][j][k]+b[i][j][k-1] - b[i-1][j][k-1];
    }
    else if( k==0 && j>0 && i>0)
    {
            sum = b[i-1][j][k] + b[i][j-1][k] - b[i-1][j-1][k];
    }

    else if(i==0&&j==0&& k>0)
    {
          sum= b[i][j][k-1];

    }
    else if(i==0 && k==0 && j>0)
    {
        sum=b[i][j-1][k];
    }
    else if(k==0 && j==0&& i>0)
    {
          sum= b[i-1][j][k];

    }
    else if(i==0 && j==0 && k==0)
    {

        sum=0;
    }

    a[i][j][k]= b[i][j][k]-sum;

    //printf("sum=%d\n",sum);

    return a[i][j][k];
}

int main()
{
    int i,j,k,t,x,y,z;
    scanf("%d",&t);
    while(t--)
    {

        scanf("%d%d%d",&x,&y,&z);
        for(i=0;i<x;i++)
        {
            for(j=0;j<y;j++)
            {
                for(k=0;k<z;k++)
                {
                    scanf("%d",&b[i][j][k]);
                    a[i][j][k]=0;
                }
            }
        }



        for(i=0;i<x;i++)
        {
            for(j=0;j<y;j++)
            {
                for(k=0;k<z;k++)
                {
                    a[i][j][k]= ans(i,j,k);
                }
            }

        }

        for(i=0;i<x;i++)
        {
            for(j=0;j<y;j++)
            {
                for(k=0;k<z;k++)
                {
                    printf("%d ",a[i][j][k]);
                }
            printf("\n");
            }
        }


    }

    return 0;
}
