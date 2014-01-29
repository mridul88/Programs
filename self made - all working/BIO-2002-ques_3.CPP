/* this question is a solutioin of bio 2002 paper - question 3 regarding Mop */

#include<cstdio>

using namespace std;
int main()
{
	long int n,ans=0,f,s,sum,flag=0;
	scanf("%ld",&n);
	sum=n+1;
	while(n>5)
	{
		flag=0;
		for(int i=2;i<n/2;i++)
		{
			if(n%i==0)
			{
				flag=1;
				f=n/i;  // n=f*i
				s=f+i;  // maximum ans = f+i;
				if(s<sum) 
				{
					sum=s;  
					n=f;   // i is already min, further find min 1's for f
					ans=ans+i; // add i to ans as it is already minium
					i=2; // start the loop again for n=f
				}
			}
		}
		if(flag!=1)
		{
			n=n-1;   // check for n-1 in next loop
			ans=ans+1; 
		}
	}
	ans=ans+n;
	printf("%ld ",ans);
	while(getchar()!='\n');
	getchar();
}
