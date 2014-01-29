#include<stdio.h>  //to take the input of a paragraph
#include<conio.h>
#include<math.h>
#define pi 3.142857
int hit(int d,int a,int r)
{
	float m;
	m=d/(2*r*sin(a*pi/180));
	return m;
}
typedef struct name
{
	int d[10],a[10],r;
}input;
void main()
{
	int d,i=0,r,a,k,j=0;
	input *ptr[1];
	scanf("%d",&r);
	while(r!=0)
	{
		i++;
		j=0;
		(*(ptr)+i)->r=r;
		scanf("%d %d",&d,&a);
		while(d!=0 && a!=0)
		{
			j++;
			(*(ptr)+i)->d[j]=d;
			(*(ptr)+i)->a[j]=a;
			scanf("%d %d",&d,&a);
		}
		scanf("%d",&r);
	}
	for(int m=1;m<=i;m++)
	{
		printf("Test rig %d",m);
		for(int n=1;n<=j;n++)
		{
			k=hit((*(ptr)+m)->d[n],(*(ptr)+m)->a[n],(*(ptr)+m)->r);
			printf("\n%d",k);
		}
	}
	getch();
}

