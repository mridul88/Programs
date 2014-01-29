#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	int i,n,*a,*b,*c,m,j;
	printf("enter the degree of polynomial in x \n");
	scanf("%d",&n);
	printf("enter the degree of polynnomial in y \n") ;
	scanf("%d",&m);
	a= (int *)malloc (sizeof(int)*(n+1)*(m+1));
	b=(int *)malloc (sizeof(int)*(n+1)*(m+1));
	c=(int *)malloc (sizeof(int)*(n+1)*(m+1));
	printf("enter the coefficients of x & y of power as in index \n");
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<m+1;j++)
		{

			printf("a[%d][%d]=",i,j);
			scanf("%d",(a+i*(m+1)+j+1));
			printf("b[%d][%d]=",i,j );
			scanf("%d",(a+i*(m+1)+j+1));
			*(c+i*(m+1)+j+1)=*(a+i*(m+1)+j+1)+ *(b+i*(m+1)+j+1);
		}
	}
	printf("sum of polynomial");
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<m+1;j++)
		{
			printf("+(%d X^%dY^%d)",*(c+i*(m+i)+j+1),i,j);
		}
	}
	 while(getchar()!='\n');
	getchar();
	return 0;
}
