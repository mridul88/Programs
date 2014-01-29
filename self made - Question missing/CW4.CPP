#include<cmath>
#include<cstdio>

using namespace std;

void sort(int *n, int k)
{
	int i,j;
	for(i=0;i<k;i++)
	{
		for(j=0;j<k;j++)
		{
			if(n[i]>n[j])
			{
				int t=n[i];
				n[i]=n[j];
				n[j]=t;
			}
		}
	}
}
int main()
{
	int *n, i, j,k;
	i=0;
	scanf("%d",&n[i]);
	while(n[i]>0)
	{
		i++;
		scanf("%d",&n[i]);
	}
	k=i;
	sort(n,k);
	for(i=0;i<k;i++)
	{
	//	text (n[i]);
	}
	printf("dfghjk");
}
