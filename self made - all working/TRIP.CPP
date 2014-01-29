/* Input : number of persons gone to trip and then their respective expense
   Outut:  min no. of amount to be transfered, so that the expense will be equal to all 
*/
#include<cstdio>

using namespace std;

int main()
{
	int n,i;
	float avg=0,m=0,s=0,*a;
	scanf("%d",&n);
	a=new (float [sizeof(n)]);
	for(i=0;i<n;i++)
	{	scanf("%f",&a[i]);
		s=s+a[i];
	}
	avg= s/(float)n;
	for(i=0;i<n;i++)
		if(a[i]<avg)
			m=m+(avg-a[i]);
	printf("\n%f",m);
	while(getchar()!='\n');
	getchar();
	return 0;
}
