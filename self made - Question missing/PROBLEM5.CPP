#include<stdio.h>
int main()
{
	long int n,sum;
	int l,i,k,*t;
	scanf("%ld %d",&n,&l);
  while(l<n/2)
  {
	sum=0;
	t=new int[l];
	for(i=0;i<l;i++)
		t[i]=(int)n/l;
	if(l%2==0)
		k=l/2-1;
	else
		k=l/2;
	for(i=0;i<k;i++)
		t[i]=t[i]-(k-i);
	for(i=l;i>k;i--)
		t[i]=t[i]+(i-k);
	for(i=0;i<l;i++)
		sum =sum+t[i];
	if (sum==n)
	{
		printf("{");
		for(i=0;i<l;i++)
			printf(" %d, ",t[i]);
		printf("}");
		while(getchar()!='\n');
		getchar();
		return 0;
	}
	else
	{
		delete t;
		l++;
	}
  }
	printf("{  }");
	while(getchar()!='\n');
	getchar();
	return 0;
}
