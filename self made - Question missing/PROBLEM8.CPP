#include<stdio.h>
int w[3][10];
int *a;
static int flag;
void sort(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(w[1][j]<w[1][i])
			{
				int t;
				t=w[1][i];
				w[1][i]=w[1][j];
				w[1][j]=t;
			}
		}
	}
}
int fun(int i,int s,int n)
{
	int j,k,l=1,ans=1,b;
	for(j=0;j<n;j++)
	{
		if(a[i]==w[1][j]||a[i]==w[1][j]-1||a[i]==w[1][j]+1)
			return ans ;
	}
	if(i==s-1)
	{
		ans++;
		flag=0;
		int index=0;
		for(j=0;j<s;j++)
		{
			for(k=0;k<n;k++)
			{
				if(a[j]<w[1][k]-1)
				{	b=k-1;
					break;
				}
			}
			a=new int[l*3];
			for(k=0;k<3;k++)
			{
				a[index]=a[j]-w[1][b]+(k-1);
				index++;
			}
		}
		fun(0,l*3,n);
	}
	if(a[i]<w[0][0]-1)
		flag++;
	if(flag==s)
		return -1;
	fun(i+1,s,n);
	return ans;
}

int main()
{
	int n,i=1,j,ch,sum=0;
	while((ch=getchar())!='\n')
	{
		w[1][0]=ch-31;
		scanf("%d",&w[1][i]);
		i++;
	}
	n=i;
	a=new int[1];
	scanf("%d",&a[0]);
	sort(n);
	for(i=0;i<n;i++)
	{
		w[0][i]=w[1][i]-1;
		w[2][i]=w[1][i]+1;
		sum=sum+w[2][i];
	}
	if(a[0]<w[0][0] || a[0]>sum)
	{
		printf("-1");
		while(getchar()!='\n');
	    getchar();
		return 0;
	}
	int ans=fun(0,1,n);
	printf("%d",ans);
	while(getchar()!='\n');
	getchar();
	return 0;
}
