/* Add two polynomials of one variable and degree as input*/
#include<cstdio>
#include<cstdlib>

using namespace std;
int main()
{
	int i,n,*a,*b,*c;
	printf("enter the degree of polynomial in x \n");
	scanf("%d",&n);
	a= (int *)malloc (sizeof(int)*n+1);
	b=(int *)malloc (sizeof(int)*n+1);
	c=(int *)malloc (sizeof(int)*n+1);
	printf("enter the coefficients of x of power as in index \n");
	for(i=0;i<n+1;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
		printf("b[%d]=",i );
		scanf("%d",&b[i]);
		c[i]=a[i]+b[i];
	}
	printf("sum of polynomial");
	for(i=0;i<n+1;i++)
	{  printf("+");
			printf("%dX^%d",c[i],i);
	}
	while(getchar()!='\n');
	getchar();
 return 0;
}
