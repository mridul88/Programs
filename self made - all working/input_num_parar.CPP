#include<cstdio>

int main()
{
	int a[20][20],l[20];
	int i=-1,j=0,s,c;
	scanf("%d",&s);
	while(s!=0)
	{
		i=i+1;
		j=0;
		a[i][j]=s;
		while((c=getchar())==' ')
		{
			j++;
			scanf("%d",&s);
			a[i][j]=s;
		}
		l[i]=j;
		//printf("%d",l[i]);
		scanf("%d",&s);
	}
 //	printf("i=%d,l[0]=%d,l[1]=%d",i,l[0],l[1]);
	for(int m=0;m<=i;m++)
		for(int n=0;n<=l[m];n++)
			printf(" %d ",a[m][n]);
		printf("\n");
	getchar();
	getchar();
}

