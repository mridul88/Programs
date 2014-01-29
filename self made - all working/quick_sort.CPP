#include<cstdio>
#include<cstdlib>

using namespace std;

int partition(int a[],int p,int r)
{
	int i,j,temp;
	i=p-1;
	for(j=p;j<r;j++)
	{
		if(a[j]<=a[r])
		{
			i++;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp =a[i+1];
	a[i+1]=a[r];
	a[r]=temp;
	return(i+1);
}
int quicksort(int a[],int p, int r)
{
	int q;
	if(p<r)
	{
		q=partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}

int main()
{
	int *a,p=0,r;
	printf("enter the no. of elements");
	scanf("%d",&r);
	a=new int[r];
	printf(" enter the value of elements");
	for(p=0;p<r;p++)
		a[p]=rand()%100;
	p=0;r--;
	quicksort(a,p,r);
	for(p=0;p<r+1;p++)
		printf("\n%d",a[p]);
	getchar();
	getchar();
	return 0;
}
