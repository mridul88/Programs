/* program o implemnt sum of subset (NP -complete) problem, working only in special cases
   as when 2,3,5,7 and sum =5 ; Fail in 5, 10, 15, 20 sum =20.  */
#include<cstdio>

using namespace std;

void print(int *x,int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		if(x[i]==1)
			printf("%d ",a[i]);
	}
	printf("\n");
}
int main()
{
	printf("enter the no. of values\n");
	int n,*a,*x,i,j,m=1,s=0,k;
	scanf("%d",&n);
	a=new int[n];
	x=new int[n];
	printf("enter the values\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	i=0;
	printf("enter the value of m(sum)");
	scanf("%d",&m);
	while(i<n)
	{
		for(k=0;k<n;k++)
			x[k]=0;
		s=a[i];
		x[i]=1;
		if(s==m)
		{
			printf("%d\n",a[i]);
			i++;
			break;
		}
		else if(s>m)
		{
			i++;
			break;
		}
		else
		{
                 j=i+1;
                 while(j<n)
			     {
			             s=s+a[j];
			             x[j]=1;
			             if(s==m)
			             {
				                 print(x,a,n);
                                 x[j]=0;
                         }
			             else if(s>m)
			             {
                                  x[j]=0;  // needs a remove function which really doesn't remove anything
                                           // but check if on removing any subset can it be equal to m, if yes print it.  
                         }
		                 j=j+m;
                }
			    i++;
		}
	}
	while(getchar()!='\n');
	getchar();
	return 0;
}



