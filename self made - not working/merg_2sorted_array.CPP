#include<cstdio>
using namespace std;
/* this program is to merge two sorted array into a sorted array*/
int c[7];
void enter(int n)
{
	 int static k=0;
	 c[k]=n;
	 k++;
}
int main()
{
	int i,j,l,*a,*b,n,m;
	char flag='z';
	printf("enter the size of one array");
	scanf("%d",&n);
	printf("\n enter the elements of first array");
	a=new int[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("enter the size of second array");
	scanf("%d",&m);
	b=new int [m];
	printf("\n enter the elements of second array");
	for(i=0;i<m;i++)
		scanf("%d",&b[i]);
	j=i=0;
	while(flag=='z')
	{
		while(a[i]>=b[j])       /* first the element of first array is compared */
		{
			enter(b[j]);
			if(j<m-1)
			j++;
			else
			{   flag='b';
				break;
			}
		}
		while(b[j]>a[i])
		{
			enter(a[i]);
			if(i<n-1)
			i++;
			else
			{   if(flag=='b')
					flag='c';
				else
					flag='a';
				break;
			}
		}
	}
	if(flag=='a')
		for(l=0;l+j<m;l++)
			enter(b[j+l]);

	else if (flag=='b')
		for(l=0;l+i<n;l++)
			enter(a[i+l]);


	for(i=0;i<(m+n);i++)
		printf("\t%d",c[i]);
    while(getchar()!='\n');
    getchar();
    return 0;
}
