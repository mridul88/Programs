#include<cstdio>

using namespace std;

int main()
{
	int a[10]={1, 1, 1, 1, 1, 1, 1, 1, 1, 1},*f;
	int*fun(int *);
	f=fun(a+4);
	for (int i=0;i<10;i++)
		printf("%d\n",a[i]);
	getchar();
}
int * fun(int *a)
{
	for(int i =0;i<6;i++)
		*(a+i)=2+*(a+i);
	return(a);
}
