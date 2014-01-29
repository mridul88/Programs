/*THIS IS THE SOLUTION TO PROBLEM 8
THIS SOLUTION IS FOR GENERAL 'NO.' BUT HAVE TO GIVEN IN THE PROGRAM ONLY

	BY DEFAULT IT IS  6*/
#include<cstdio>

using namespace std;

static int s[27][27],a[27][2];
int chkzero(int i)
{
	for(int j=0;j<27;j++)
	{
		if(s[i][j]==1)
			return 0;
	}
	return 1;
}
void setzero(int i)
{
	for(int j=0;j<27;j++)
	{
		s[j][i]=0;
	}
}
int chk1()
{
	for(int i=0;i<27;i++)
	{
		if(a[i][0]==0)
			return 1;
	}
	return 0;
}

int main()
{
	int ans=0;
	char ch,gch;
	int n,i;
	ch=getchar();
	while(ch!='\n')
	{
		scanf("%d",&n);
		a[ch-64][1]=n;
		while((gch=getchar())!='\n')
		{
			s[ch-65][gch-65]=1;
		}
		ch=getchar();
	}
		s[0][21]=s[1][21]=0;
		while(chk1())
		{
			int max=0;
			for(i=0;i<27;i++)
			{
				int k=chkzero(i);
				if(k)
				{

					a[i][0]=1;
					if(a[i][1]>max)
					{
						max=a[i][1];
						a[i][1]=0;
					}
				}
			}
			ans=ans+max;
			for(i=0;i<27;i++)
			{
				if(a[i][0]==1)
					setzero(i);
			}
		}
		printf("%d",ans);
		getchar();
		getchar();
}




