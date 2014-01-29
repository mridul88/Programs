#include<cstdio>

using namespace std;

int permu(int a[]);
void print(int a[]);
void rotate(int a[]);
void swap(int *, int *);
int c=1;
int main()
{
	int a[3]={1,2,3};
	permu(a);
	getchar();
	return 0;
}

int permu(int a[3])
{
	int i;
	if(a[0]!=a[1])
	{
		print(a);
		swap(&a[0],&a[1]);
		print(a);
	}
	else
		print(a);
	for(i=0;i<c;i++)
		rotate(a);
	if(a[0]==1&&a[1]==2&&a[2]==3)
	{
		c++;
		if(c==3)
			goto q;
		else
			goto w;
	}
	else
	w:	permu(a);
 q:	return 0;

}
void rotate(int a[3])
{
	int temp,i;
	temp=a[2];
	for(i=1;i>=0;i--)
		  a[i+1]=a[i];
	a[0]=temp;

}
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void print(int a[3])
{
	int i;
	for(i=0;i<3;i++)
		printf("%d",a[i]);
	printf("\t");
}
