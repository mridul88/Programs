#include<cstdio>
#include<cstdlib>
using namespace std;

int maxheap(int a[], int i, int n)
{
	int j,item,temp;
	j=2*i;
	item=a[i];
	while(j<=n)
	{
		if(j<n && a[j]<a[j+1])
			j++;
		if(item>a[j])
			return 0;
		else
			a[j/2]=a[j];
		j=2*j;
	}
   a[j/2]=item;
}
void buildmaxheap(int a[],int n)
{
	for(int i=(n+1)/2;i>0;i--)
		maxheap(a,i,n);
}
void heapsort(int a[],int n)
{   int i;
	buildmaxheap(a,n);
	for(i=0;i<=n;i++)
		printf("%d\t",a[i]);
	for(i=n;i>0;i--)
	{
		int temp=a[1];
		a[1]=a[i];
		a[i]=temp;
		buildmaxheap(a,i-1);
	}
}
int main()
{  
	int *a,n=5,i;
	printf(" enter the size of array");
	scanf("%d",&n);
	a=new int[n+1];
	a[0]=0;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	heapsort(a,n);
	for(i=1;i<=n;i++)
		printf("\n%d",a[i]);
	while(getchar()!='\n');
    getchar();
    return 0;
}
