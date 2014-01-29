#include<stdio.h>
#include<conio.h>
int main()
{
	
	printf("enter the no.of events");
	int n,i,**a;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		*(a+i)=new int[2];
	printf("enter the activity start and end time\nstart time\tend time");
	int *k,s,e;
	scanf("%d %d",&a[0][0],&a[0][1]);
	for(int b=1;b<n;b++)
	{
		scanf("%d%d",&s,&e);
		i=b-1;
		while((i>=0)&&(a[i][1]>e))
		{
			a[i+1][1]=a[i][1];
			a[i+1][0]=a[i][0];
			i=i-1;
		}
		a[(i+1)][1]=e;
		a[(i+1)][0]=s;
	}
	for(i=0;i<n;i++)
	{
		printf("\n%d   %d",a[i][0],a[i][1]);
	}
	s=0;
	k[s]=0;
	for(i=1;i<=n;i++)
	{
		if(a[i][0]>=a[k[s]][1])
		{
			s++;
			k[s]=i;
		}
	}
	printf("the max no of events feasible are:%d",s+1);
	printf("events are:\nstart time \tend time");
	for(i=0;i<=s;i++)
	{
		 printf("\n%d\t%d",a[k[i]][0],a[k[i]][1]);
	}
	getch();
	return 0;
}




