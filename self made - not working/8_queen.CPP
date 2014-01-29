#include<cstdio>

using namespace std;

int danger(int r,int c,int n,int **m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		if(m[i][c]==1)
			 return 1;
		if(m[r][i]==1)
			 return 1;
	}
	for(i=r,j=c;i>=0&&j>=0;i--,j--)
	{
		if(m[i][j]==1)
			return 1;
	}
	for(i=r,j=c;i>=0&&j<n;i--,j++)
	{
		if(m[i][j]==1)
			return 1;
	}
	for(i=r,j=c;i<n&&j<n;i++,j++)
	{
		if(m[i][j]==1)
			return 1;
	}
	for(i=r,j=c;i<n&&j>=0;i++,j--)
	{
		if(m[i][j]==1)
			return 1;
	}
	return 0;
}
int check(int **m,int r,int n)
{
	for(int i=0;i<n;i++)
	{
		if(m[r][i]==1)
			return 1;
	}
	return 0;
}
void print(int **m,int n)
{
	printf("\n");
 for(int i=0;i<n;i++)
    {
	for(int j=0;j<n;j++)
	{
		if(m[i][j]==1)
			printf("Q\t");
		else
			printf("X\t");
	}
	printf("\n");
    }
 }
int main()
{
    int n,i,j,**m,*a,k,top=0,l;
    printf("enter the value of n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
	*(m+i)=new int[n];
	for(j=0;j<n;j++)
		m[i][j]=0;
    }
    a=new int[n];
    i=j=0;
    while(i<n)
    {
	while(j<n)
	{
		k=danger(i,j,n,m);
		if(k==0)
		{
			m[i][j]=1;
			a[top]=j;
			top++;
			break;
		}
		j++;
	}
	l=check(m,i,n);
	if(l==0)
	{
		i--;
		top--;
		j=a[top]+1;
		m[i][j-1]=0;
	}
	else
	{
		i++;
		j=0;
	}
    }
    print(m,n);
    getchar();
    return 0;
}










