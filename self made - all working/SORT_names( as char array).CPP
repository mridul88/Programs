#include<cstdio>
#include<cstdlib>

using namespace std;

int compare(char*a,char*b);
int main()
{
	int i,j,n=0;
	char *temp,*a[]={"rohit","roshan","poorva","anurag","mridul"};
	while(n<5)
	{
		for(j=1;j<5;j++)
		{
			i=compare(a[j-1],a[j]);
			if(i>0)
			{
				temp=a[j-1];
				a[j-1]=a[j];
				a[j]=temp;
			}
		}
	n++;
	}
	for(j=0;j<5;j++)
		printf("%s\n",*(a+j));
	while(getchar()!='\n');
	getchar();
 return 0;
}
int compare(char*a,char*b)
{
	while(*a==*b)
	{
		if(*a=='\0')
			return 0;
		a++;
		b++;
	}
	return(*a-*b);
}
