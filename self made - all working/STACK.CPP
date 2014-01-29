#include<cstdio>
#include<cstdlib>

using namespace std;

int a[10];
int top=-1;
void push(void)
{  int n;
	printf("enter the number");
	scanf("%d",&n);
	top=top+1;
	if(top>=10)
	{
		printf("overflow");
		return;
	}
	else
		a[top]=n;
}
void pop()
{
	if(top<0)
	{
		printf("underflow");
		return;
	}
	else
		top=top-1;
}
void print(void)
{
	int i;
	for(i=0;i<=top;i++)
		printf("\n%d",a[i]);
}
int main()
{
	int i=0;
	while(i!=3)
	{
		print ();
		printf("\n\n1.insert\n2.delete\n3.exit\n");
		printf("enter ur choice");
		scanf("%d",&i);
		switch(i)
		{
			case 1: push();
						break;
			case 2: pop();
						break;
		}
	}
	while(getchar()!='\n');
	getchar();
	return 0;
}
