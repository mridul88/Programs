#include<conio.h>
#include<stdio.h>
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
