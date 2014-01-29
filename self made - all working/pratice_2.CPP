#include"cstdio"
#include"cstdlib"

using namespace std;
int main()
{

	int a[]={68,79,8,97,78,64};
	float m=89.87868;
	float*fun(int *,float *),*f;
	f=fun(a+3,&m);
	printf("%u,%f %f",f,*f,m);

	getchar();
	return 0;
}
float*fun(int *a,float *b)
{
	* b=12.28;
	for(int i=0;i<3;i++)
	{
		printf("%d\n",*(a+i));

	}
	float c=70;
	return(&c);
}


