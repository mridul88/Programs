#include<conio.h>
#include<stdio.h>
int min(int **a,int *s,int n,int* cost)
{
	int i,j,node;
	for(i=0;i<n;i++)
	{
		if(s[i]==1)
		{
			for(j=0;j<n;j++)
			{
				if(a[i][j]<*cost && s[j]==0 && a[i][j]!=0)
				{
					node=j;
					*cost=a[i][j];
				}
			}
		}
	}
	return node;
}

int main()
{
	int **a,n,i,j,k,*s,c,cost=0,flag=0;
	printf("enter the no. of nodes\n");
	scanf("%d",&n);
	s=new int [n];
	for(i=0;i<n;i++)
	{	*(a+i)=new int [n];
		s[i]=0;
		for(j=0;j<n;j++)
			a[i][j]=0;
	}
	printf("enter the edge and distance\n to quit write  0 0 0\n");
	printf("\nnode1\tnode2\tdistance\n");
	scanf("%d %d %d",&i,&j,&k);
	while(j!=0 || i!=0 ||k!=0)
	{
		a[i-1][j-1]=k;
		a[j-1][i-1]=k;
		scanf("%d %d %d",&i,&j,&k);
	}
	s[0]=1;
	while(flag==0)
	{
		c=9999;
		k=min(a,s,n,&c);
		s[k]=1;
		cost=cost+c;
		printf("\ncost = %d\ntree is:\n",cost);
		for(i=0;i<n;i++)
		{
			if(s[i]==1)
				printf("%d\t",i+1);
			flag=1;
			if(s[i]==0)
			{
				flag=0;
				break;
			}
		}
	}
	printf("\ncost of min. spannig tree = %d",cost);
	getch();
	return 0;
}