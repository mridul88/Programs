#include<stdio.h>
#include<conio.h>
int q[10];
int f=-1,r=-1;
void insert()
{   int n;
	scanf("%d",&n);
	int temp=r;
	if(r==9)
		r=1;
	else
		r++;
	if(r==f)
	{
		printf("overflow");
		r=temp;
		return;
	}
	q[r]=n;
	if(f==-1)
		f=0;
}
void qdelete()
{
	if(f==-1)
	{
		printf("underflow");
		return;
	}
	if(f==r)
		f=r=-1;
	else if(f==9)
		f=0;
	else
	f++;
}
void print(void)
{
	int i;
	if(f!=-1)
	for(i=f;i<=r;i++)
		printf("\t%d",q[i]);
}
void main()
{   clrscr();
	int i=0;
	while(i!=3)
	{
		print ();
		printf("\n\n1.insert\n2.delete\n3.exit\n");
		printf("enter ur choice");
		scanf("%d",&i);
		switch(i)
		{
			case 1: insert();
						break;
			case 2: qdelete();
						break;
			default : printf("enter valid option");
		}
	}
}


