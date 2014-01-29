#include<cstdio>

using namespace std;

int hcf(int a, int b)
{
	if(b==0)
		return a;
	else
		hcf(b,a%b);
}
int main()
{

	int k,r,max,n,i;
	int *a,*b;
	scanf("%d",&n);
	a=new int [n];
	b=new int[n-1];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
	{
		if(a[i+1]>a[i])
			b[i]=a[i+1]-a[i];
		else
			b[i]=a[i]-a[1+1];
	}
	for(i=0;i<n-2;i++)
	{
		k=hcf(b[i],b[i+1]);
		if(k>max)
			max=k;
	}
	r=a[0]-max*(a[0]/max);
	printf("%d %d",max,r);
	while(getchar()!='\n');
	getchar();
	return 0;
}
