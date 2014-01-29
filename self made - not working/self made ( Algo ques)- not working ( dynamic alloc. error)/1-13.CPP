#include<stdio.h>
#include<conio.h>

int getindex(int n,int*l, int index)
{
	for(int i=0;i<index;i++)
	{
		if(n==l[i])
			return(i);
	}
	return 0;
}
void histogram(int *l,int n)
{
	int max=0,i,**a,index;
	for(i=0;i<n;i++)
	{
		if(max<l[i])
			max=l[i];

	}
	for(i=0;i<max;i++)
	{
		*(a+i)=new int[2*n];
	}
	for(i=max;i>=0;i--)
	{
			int k= getindex(i,l,index);
			for(int j=0;j<2*k;j++)
			{
				printf(" ");
			}
			printf("*");
	}
}

main()
{
	char ch;
	int count=0,*l,index=0;
	ch=getchar();
	while(ch!='\n')
	{
		count=0;
		while(ch!='\n'&&ch!=' ' &&ch!='\t')
		{
			count++;
			ch=getchar();
		}
		l[index]=count;
		index++;
		ch=getchar();
	}
	histogram(l,index);
	getchar();
	return 0;
}


