#include<stdio.h>
#include<conio.h>
int main()
{
	clrscr();
	int **a,i,j,k,l,n,*x;
	printf("enter the no. of vertices\n");
	scanf("%d",&n);
	x=new int [n];
	for(i=0;i<n;i++)
	{	*(a+i)=new int [n];
		x[i]=0;
		for(j=0;j<n;j++)
			a[i][j]=0;
	}
	printf("enter the graph as\tto exit 0 0 0\nnode 1\tnode 2\n");
	scanf("%d%d%d",&j,&k);
	while(j!=0 || k!=0)
	{
		a[j-1][k-1]=1;
		scanf("%d%d%d",&j,&k);
	}
	for(k=0;k<n;k++)
	{
		next();