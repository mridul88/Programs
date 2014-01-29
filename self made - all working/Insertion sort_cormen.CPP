#include<cstdio>

using namespace std;

int main()
{   
	int i,j,*a,n,m;
	printf("enter the no. of elements");
	scanf("%d",&n);
	a=new int[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]); //advantage sorting can also be done by taking input
	for(i=1;i<n;i++)     // one by one
	{
	   //	scanf("%d",&a[i]);
		m=a[i];
		j=i-1;
		while(j>=0&&a[j]>m)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=m;
	}
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
	while(getchar()!='\n');
    getchar();
    return 0;
}
