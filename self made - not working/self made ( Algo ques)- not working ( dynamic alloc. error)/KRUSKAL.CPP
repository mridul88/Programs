#include<conio.h>
#include<stdio.h>
struct pair
{
	int w,f;
};
struct pair min(struct pair **a,int n,int* cost)
{
	int i,j;
	struct pair p;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j].w< (*cost) && a[i][j].f==0 && a[i][j].w!=0)
			{
				p.w=i;
				p.f=j;
				*cost=a[i][j].w;
			}

		}
	}
	a[p.w][p.f].f=1;
	return p;
}
int main()
{
	int n,i,j,k,**s,cost=0,*check,flag;
	struct pair **a,p;
	printf("enter the no. of nodes\n");
	scanf("%d",&n);
	check=new int [n];
	for(i=0;i<n;i++)
	{	*(a+i)=new struct pair [n];
		*(s+i)=new int [n];
		check[i]=0;
		for(j=0;j<n;j++)
		{
			a[i][j].w=0;
			a[i][j].f=0;
			s[i][j]=0;
		}
		s[i][i]=1;
	}
	printf("enter the edge and distance\n to quit write  0 0 0\n");
	printf("\nnode1\tnode2\tdistance\n");
	scanf("%d %d %d",&i,&j,&k);
	while(j!=0 || i!=0 ||k!=0)
	{
		a[i-1][j-1].w=k;
		scanf("%d %d %d",&i,&j,&k);
	}
	for(j=0;j<n;j++)
	{
		int c=9999;
		p=min(a,n,&c);
		flag=0;
		for(i=0;i<n;i++)
		{
			if(s[i][p.w]==1 && s[i][p.f]==1)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			s[p.w][p.f]=1;
			s[p.f][p.w]=1;
			check[p.w]=1;
			check[p.f]=1;
			cost=cost+c;
			printf("\nedge added\t node 1 =%d\tnode 2=%d\tcost:=%d",p.w+1,p.f+1,cost);
		}
		flag=0;
		for(i=0;i<n;i++)
		{
			if(check[i]==0)
				flag=1;
		}

	}
	printf("\ncost of min. spannig tree = %d",cost);
	getch();
	return 0;
}