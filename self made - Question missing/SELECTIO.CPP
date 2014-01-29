#include<cstdio>

using namespace std;

int main()
{
	int i,j,min,a[5],b[5],temp;
	for(i=0;i<5;i++)
		scanf("%d",&a[i]);
	min=a[0];
	for(i=0;i<5;i++)
		if(a[i]<min)
		   min=a[i];

	b[0]=min;
	for(j=1;j<5;j++)
	{   for(i=0;i<5;i++)
		{
			if(a[i]>b[j-1])
			{	temp=a[i];
				break;
			}
		}
		for(i=0;i<5;i++)
		{
			if(a[i]<temp&&a[i]>b[j-1])
				temp=a[i];
		}
	b[j]=temp;
	}
	for(i=0;i<5;i++)
		printf("%d",b[i]);
		
	while(getchar()!='\n');
  getchar();	
}
