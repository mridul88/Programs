/*program to implement GCD by Eycledian Method*/
#include<stdio.h>

int main()
{
	int n,m,k;
	scanf("%d %d",&n,&m);
	while(n>0)
	{
			k=n%m;
			if(k==0)
			{
				printf("%d",m);
				getchar();
				return(m);
			}
			n=m;
			m=k;

	}
    getchar();
    return 0;
}
