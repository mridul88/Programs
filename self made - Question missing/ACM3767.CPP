#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>
void findset(int m,int *a, int n,int sum)
{
	int i,j,k=0,l,*b,s=0;
	b=new int[n];
	for(i=0;i<n;i++)
		b[i]=0;
	//printf("%d %d",a[0],m);
	while(1)
	{
		for(i=s;i<n;i++)
		{
			if(m % a[i]==0)
			{
				m=m/a[i];
				b[i]=1;
				k++;
				l=i;
				//printf("select= %d\n",a[l]);
			}
			if( (k>(n+1)/2||k==(n+1)/2) && m!=1)
			{
				b[l]=0;
				m=m*a[l];
				k=k-1;
			   //	printf("delete = %d\n",a[l]);
				i=l+1;
				for(j=0;j<n;j++)
				{
					if(b[j]==1)
						l=j;
				}
			}
			if(k==(n+1)/2 && m==1)
			{
				int ans=0;
				for(i=0;i<n;i++)
				{
					if(b[i]==1)
						ans=ans+a[i];
				}
				if(ans>sum/2)
				{
					for(i=0;i<n;i++)
					{
						if(b[i]==1)
							printf("%d ",a[i]);
					 }
				}
				else
				{
					for(i=0;i<n;i++)
					{
						if(b[i]==0)
							printf("%d ",a[i]);
					}
				}
				printf("\n");
				return;
			}
		}
		b[l]=0;
		m=m*a[l];
		k=k-1;
		//printf("delete= %d\n ",a[l]);
		s=l+1;
	}

}
int main()
{
	
	int i=0,j=0,n=0,k=0,l[20],a[20][20],r;
	char ch;
	float m=1.000;
	while(1)
	{
		for(i=0;i<20&&(ch=getchar())!='\n'&& isdigit(ch);i++)
			n=10*n+(ch-48);
		a[j][k]=n;
		if(n==0 && k==0)
			break;
		if(isspace(ch))
		{
			n=0;
			k++;
		}
		if(ch=='\n')
		{
			n=0;
			l[j]=k;
			j++;
			k=0;
		}
	}
	r=j;
	for(i=0;i<r;i++)
	{
		m=1;
		int sum=0;
		for(j=0;j<l[i];j++)
		{
			m=m*a[i][j];
			sum=sum+a[i][j];
		}
		int s=sqrt(m);
		findset(s,a[i],l[i],sum);
	}
	getch();
	return 0;
}

