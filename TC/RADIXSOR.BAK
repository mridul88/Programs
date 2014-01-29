#include<conio.h>
#include<stdio.h>
#include<string.h>
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
void main()
{
	clrscr();
	int **a,i,d=0,ch,size=0;
	ch=getchar();
	while(ch!='e'||!='E')
	{
		i=0;
		a[size][digit]=(int)(ch-48);
		//printf("%d",a[size][digit]);
		while((ch=getchar())!='\n')
		{
			//printf("%d",size);
			digit++;
			a[size][digit]=(int)(ch-48);
			//printf("%d",a[size][digit]);
		}
		size++;
		//printf("%d",a[0][0]);
		ch=getchar();
	}
   //	printf("%d",a[0][0]);
	for(int n=0;n<size;n++)
	{
		for(int i=0;i<=digit;i++)
			printf("%d",a[n][i]);
		printf("\n");
	}
	getch();
}





