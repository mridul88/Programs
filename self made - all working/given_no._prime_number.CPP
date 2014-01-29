/* program to print the specified number of prime numbers, we sore the prime numbers so thst other numbers should only be
divided by them to check whether they are prime or not*/
#include<cstdio>

using namespace std;

int main()
{
	int n,i,j,num,count=1,flag,a[1000]={0};
	printf("enter the value of n <1000\n");
	scanf("%d",&n);
	if(n<=0)
	{
		printf("Nothing to print\n");
		return 0;
	}
	else if(n>1000)
	{
		printf("no. should be less than 1000");
		return 0;
	}
	for(num=2;count<=n;num++)
	{
		flag=0;
		for(j=0;a[j]<num/2;j++)
		{
			if(num%a[j]==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
            a[count]=num;       
			printf("%3d.)%3d\n",count,num);
			count++;
		}
	}
	while(getchar()!='\n');
	getchar();
	return 0;
}
