#include<cstdio>  //to take the input of a paragraph
#include<cmath>
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
int main()                         // the code will take input like
{                                   // 5
	int d,i=0,r,a,k,j=0;            // 3 4
	input *ptr[1];                  // 45 78
	scanf("%d",&r);                 // 78 6
	while(r!=0)                     //7 6
	{                             // so on
		i++;                       // important for input case
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
		printf("Test rig %d\n",m);
		for(int n=1;n<=j;n++)
		{
			k=hit(((*(ptr)+m)->d[n])-1,(*(ptr)+m)->a[n],(*(ptr)+m)->r);
			printf("%d\n",k);
		}
	}
	while(getchar()!='\n');
	getchar();
	return 0;
}

