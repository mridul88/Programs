#include<stdio.h>
int a[2][50];
void genrate(int m,int n)
{
	if(2*m<=n)
	{
		a[1][2*m]=1;
		a[1][2*m+1]=1;
		m=2*m;
		genrate(m,n);
		genrate(m+1,n);
	}
	return;
}
int main()
{
	int i=2,j,m,ch,n,ans=0;
	scanf("%d",&a[0][1]);
	while((ch=getchar())!='\n')
	{
		scanf("%d",&a[0][i]);
		i++;
	}
	n=i;
	scanf("%d",&m);
	m++;
	a[1][m]=1;
	genrate(m,n);
	for(i=1;i<n;i++)
	{
		if(2*i>n-1 && a[1][i]!=1)
			ans++;
	}
	printf("%d",ans);
	while(getchar()!='\n');
	getchar();
	return 0;
}


