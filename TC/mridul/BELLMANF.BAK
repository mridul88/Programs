#include<stdio.h>
#include<conio.h>
#define MAX 9999
int main()
{
	int **a,n,i,j,k,*s,*dist;
	printf("enter the no. of nodes\n");
	scanf("%d",&n);
	s=new int [n];
	dist=new int [n];
	for(i=0;i<n;i++)
	{	*(a+i)=new int [n];
		s[i]=0;
		for(j=0;j<n;j++)
		{
			if(i==j)
				a[i][j]=0;
			else
				a[i][j]=MAX;
		}
	}
	printf("enter the edge and distance\n to quit write  0 0 0\n");
	printf("\nnode1\tnode2\tdistance\n");
	scanf("%d %d %d",&i,&j,&k);
	while(j!=0 || i!=0 ||k!=0)
	{
		a[i-1][j-1]=k;
		scanf("%d %d %d",&i,&j,&k);
	}
	printf("enter the starting node");
	scanf("%d",&k);
	s[k-1]=1;
	for(i=0;i<n;i++)
		dist[i]=a[k-1][i];
	for(int l=0;l<n;l++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(dist[j]>(dist[i]+a[i][j]) )
					dist[j]=dist[i]+a[i][j];
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(dist[i]==MAX)
			printf("shortest distance to %d from node %d is = NOT REACHABLE\n",i+1,k);
		else
			printf("shortest distance to %d from node %d is =%d\n",i+1,k,dist[i]);
	}
	getch();
	return 0;
}
