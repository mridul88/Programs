#include<stdio.h>
#include<conio.h>
int check(int *d,int n)
{
	int j=-1;
	for(int i=0;i<n;i++)
	{
		if(d[i]>=i+1)
			j=i;
	}
	return j;
}
void sort(int **a,int  n)
{
   int i,j;
	for(i=0;i<n;i++)
	{
	   for(j=0;j<n;j++)
		{
		if(a[i][1]>a[j][1])
		{
			int t,q;
			t=a[i][1];
			q=a[i][0];
			a[i][1]=a[j][1];
			a[i][0]=a[j][0];
			a[j][1]=t;
			a[j][0]=q;

		   }
		}
	}
}
int main()
{

	
	int n,i,j,k,p=0,*d,**a,dmax=0,count=0;
	printf("enter the no.of jobs\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		*(a+i)=new int[3];
	printf("deadline     profit");
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&a[i][0],&a[i][1]);
		a[i][2]=0;
		if(dmax<a[i][0])
			dmax=a[i][0];
	}
	d=new int[dmax];
	for(i=0;i<dmax;i++)
		d[i]=0;
	sort(a,n);
	for(i=0;i<n && count<dmax;i++)
	{
		k=check(d,dmax);
		if(a[i][0]>d[a[i][0]-1] && (a[i][0]-1)>k)
		{
			count++;
			for(int j=0;j<i;j++)
				d[a[i][0]-1]+=d[a[j][0]-1];
			d[a[j][0]-1]+=1;
			p=p+a[i][1];
			a[i][2]=1;
		}
	}
	printf("\nprofit:=%d\n job selected :\n",p);
	for(i=0;i<n;i++)
	{
		if(a[i][2]==1)
			printf("\n%d\t%d",a[i][0],a[i][1]);
	}

    getch();
	return 0;
}


