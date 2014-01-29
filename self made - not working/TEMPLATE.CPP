#include<cstdio>

using namespace std;

template <class x,class y>void swap(x &a,y &b)
{
	x t;
	t=a;
	a=b;
	b=t;
}
int main()
{
	int i=10,j=1;
	float a=2.343,b=3.432;
	swap(i,a);
	swap(j,b);
	printf("%d %f\t%d %f",i,a,j,b);
	return 0;
}
