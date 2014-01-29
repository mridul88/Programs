#include<cstdio>

using namespace std;

int hcf(int a, int b)
{
	if(b==0)
		return a;
	else
		hcf(b,a%b);
}
int main()
{
	int k=0,r,b,flag=1,i,j,n,re,max=0;
	int *a;
	scanf("%d",&n);
	a=new int [n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	for(r=0;r<30;r++)
	{
		for(i=0;i<n;i++)
	 {  flag=1;
		k=hcf((a[i]-r),(a[(1+i)]-r));
	   //printf("\n%d %d",k,i);
		for(j=i+2;j<n;j++)      /*to check k is valid*/
		{
			b=a[j]%k;
			if(b!=r)
				flag=0;
		}
		if(flag==1)
		{
			if(max>k)
			 {	max=k; re=r;}
		 }
	  }
	 }
	 printf("%d %d",max,re);
	 while(getchar()!='\n');
	getchar();
	return 0;
}
