/* This is a solution to the problem of BIO 2001- question 1*/
#include<cstdio>
#include<cstdlib>

using namespace std;
void time(int t)
{
	static int mintime;
	if(t==0)
		printf(" minimun time : %d",mintime);
	else
		mintime=mintime+t;
}
void sort( int a[],int n)
{   int i=0,j=0,temp,c;
	for(c=0;c<n;c++)
	{  i=0;j=1;
		while(j<n)
		{
			if(a[i]>=a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
			i++;
			j++;
		}
		c++;
	}
}
int  least(int b[])
{
	int i;
	for(i=0;b[i]==0;i++);
	return(i);
}
int max(int a[], int n)
{   int max=0;
	for(int i=0; i<n;i++)
	{
		if(a[i]>a[max])
			max=i;
	}
	return(max);
}

void print(int a[],int n)
{  printf("\n");
	for(int i=0;i<n;i++)
		printf("%d",a[i]);
}
int solution(int a[],int b[] , int n)
 {                        // first min. two of'a' is send then least of b come back
	b[0]=a[least(a)];      //              then max two of 'a' is send then least of
	b[1]=a[(least(a)+1)];    //               of 'b' is back
	a[least(a)]=a[(least(a)+1)]=0;//         recursively,*/
	time(b[1]);
	time(0);
	sort(a,n);
	print(a,n);
	print(b,n);
	if(a[max(a,n)]==0)
		return 0;
	a[0]=b[(least(b))];
	time(a[0]);
	time(0);
	b[(least(b))]=0;
	sort(a,n);
	sort(b,n);
	print(a,n) ;
	print(b,n);
	b[0]=a[n-2];
	b[1]=a[n-1];
	time(b[1]);
	time(0);
	a[n-1]=a[n-2]=0;
	sort(b,n);
	sort(a,n);
	print(a,n);
	print(b,n);
	if(a[max(a,n)]==0)
		return 0;
	a[0]=b[least(b)];
	b[least(b)]=0;
	time(a[0]);
	time(0);
	sort(a,n);
	sort(b,n);
	print(a,n);
	print(b,n);
	solution(a,b,n);
	return 0;
}

int main()
{
	int *a,*b,n,i,j,c=0;
 
	printf("enter the no.of persons");
	scanf("%d",&n);
	a=new  int [n];
	b=new int[n];
	puts("enter the time taken by persons");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=0;
	}
	if(n==1)
	{
		printf("minimun time :%d",a[0]);
			while(getchar()!='\n');
			getchar();
		return 0;
	}
	else
	{
	sort(a,n);
	solution(a,b,n);
	time(0);
	}
		while(getchar()!='\n');
		getchar();
	return 0;

}
