/* This program is not working in case of prime nos, i.e when input is itself a prime no, than ans must be himself, but not so
     for resy, it' working*/
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	long int n,p=2;
	scanf("%ld",&n);
	printf("\nprime factors are:- \n");
	while(p<sqrt(n))
	{
		int flag=0;
		for(int i=2;i<p;i++)
		{
			int r=p%i;
			if(r==0)
			{	
        flag=1;
				break;
			}
		}
		if(flag==0)
		{
			int r=n%p;
			if(r==0)
				printf("%ld\n",p);
		}
		p++;
	}
	getchar();
	getchar();
	return 0;
}

