#include<cstdio>
#include<cstring>

using namespace std;

void counting(int n,int a[])
{
	int i,*c,*b,max=0;
	b=new int[n];
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	c=new int[max+1];
	for(i=0;i<=max;i++)
		c[i]=0;
	for(i=0;i<n;i++)
		c[a[i]]=c[a[i]]+1;
	for(i=1;i<=max;i++)
		c[i]=c[i-1]+c[i];
	for(i=n-1;i>=0;i--)
	{
		b[c[a[i]]-1]=a[i];
		c[a[i]]=c[a[i]]-1;
	}
	delete a;
	delete c;
	for(i=0;i<n;i++)
		printf("\n%d",b[i]);
}
int main()
{
	int *a,i=0,j,d;
	char **c[1],n,z[1];
	//printf("enter the no. of digits");
	d=4;
	//n=getchar();
	while((n=getchar())!='#')
	{
		i++;
		j=0;
		*(*(*(c)+i)+j)=n;
		//n=getchar();
		while((n=getchar())>='0' && (n=getchar())<='9')
		{
			j++;
			*(*(*(c)+i)+j)=n;
		}
		*(*(*(c+1)+i)+j+1)='\0';
		while(d-j>0)
		{
			z[0]='0';
			z[1]='\0';
			strcat(z,*(*(c)+i));
			strcpy(*(*(c)+i),z);
			d--;
		}
		//printf("%s",*(*(c)+i));
	   //	n=getchar();
	}
   //	printf(" %d ",i);
	for(j=1;j<=i;j++)
		printf("\n%s",*(*(c)+j));
}





