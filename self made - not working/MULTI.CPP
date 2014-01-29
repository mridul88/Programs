#include<cstdio>
#include<cstdlib>

using namespace std;
int main()
{
	int n, **a,i,j,k,l;
	printf("enter the no. of nodes");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		*(a+i)=new int[n];
		for(j=0;j<n;j++)
			a[i][j]=-1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	printf("working");
		while(getchar()!='\n');
	getchar();
	return 0;
}



