#include<cstdio>
#include<cstdlib>
#include<iostream.h>
int prime(int, int[]);
int main()
{
	int n,*a,i,j,count=0,s;      //this program is to find the no. of pairs of prime no.
  cin.clear();                             // such that sum of the pair is the no.*/
	printf("enter the no.");
	scanf("%d",&n);
	a=(int *)malloc (sizeof(int)*n);
	s=prime(n,a);
	//printf("%d",s);
	printf("pairs are");                       //s is the no. of the prime nos less than no. n
	for(i=0;i<=(s/2+((s%2==0)?0:1));i++)
	{
		for(j=(s/2+((s%2==0)?0:1)); j<=s;j++)
		{
			if(a[i]+a[j]==n)
			  {	count++;
					printf("\n %d %d",a[i],a[j]);
			  }
		}
	}
	printf("\n no. of ways is= %d",count);
	while(cin.get()!='\n');
	cin.get();
	return 0;
}

int prime (int n,int a[])     //generate prime nos and store
{                             //in the array a
	int m,r,i,flag,s=0;
	for(m=2;m<n;m++)
	{
		flag=0;
		for(i=2;i<m;i++)
		{
			r=m%i;
			if(r==0)
				flag=1;
		}
		if(flag==0)
		{
			a[s]=m;
			s++;
		   //	printf("%d \n",m );

		}
	}
  return(s);
}
