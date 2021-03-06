#include<stdio.h>
#include<conio.h>
#include<math.h>
#define PI 3.14857
typedef struct two
{
	float t,r;
} point;
void swap(float * n,float * m)
{
	float temp;
	temp=*m;
	*m=*n;
	*n=temp;
}
void sort(point* p,int n,point *a,int* count)
{
	for(int k=0;k<n;k++)
	{
	for(int i=0;i<n;i++)
	{
		if(p[i].t>p[i+1].t)
		{
			swap(&p[i].r,&p[i+1].r);
			swap(&p[i].t,&p[i+1].t);
		}
		if(p[i].t==p[i+1].t)
		{
			if(p[i].r>p[i+1].r)
				swap(&p[i].r,&p[i+1].r);
		}
	}
	}
	for(int i=0;i<=n;i++)
	{
		if(p[i].t==p[i+1].t)
			continue;
		else
		{
			a[*count].t=p[i].t;
			a[*count].r=p[i].r;
			(*count)++;
		}
	}
}
int check(int i0,int i1,int i2,point* a)
{
	float x0=a[i0].r*cos(PI*(a[i0].t/180));
	float y0=a[i0].r*sin(PI*(a[i0].t/180));
	float x1=a[i1].r*cos(PI*(a[i1].t/180));
	float y1=a[i1].r*sin(PI*(a[i1].t/180));
	float x2=a[i2].r*cos(PI*(a[i2].t/180));
	float y2=a[i2].r*sin(PI*(a[i2].t/180));
	float det=(x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
	//printf("%f %f %f %f %f %f  %f\n",x0,y0,x1,y1,x2,y2,det);
	if(det>=0)
		return 1;
	else
		return 0;
}
void pop(int n,int *s)
{
	for(int i=1;(i+n)<3;i++)
	{
		s[n+i-1]=s[n+i];
	}
}
void push(int *s)
{
	static int l=3;
	s[2]=l;
	l++;
}
int  main()
{
	point *p,*a;
	printf("enter the point in polar form (theta,distance) 0<theta<360\n enter negative theta to exit\n");
	int i=0,count=0,k,s[3]={0,1,2};
	scanf("%f",&p[i].t);
	while(p[i].t>=0)
	{
		scanf("%f",&p[i].r);
		i=i+1;
		scanf("%f",&p[i].t);
	}
	sort(p,i-1,a,&count);
	while(s[2]<count)
	{
		k=check(s[0],s[1],s[2],a);
		if(k==1)
		{
			printf("%1.0f %1.0f\n",a[s[0]].t,a[s[0]].r);
			pop(0,s);
			push(s);
		}
		else
		{
			pop(1,s);
			push(s);
		}
	}
	printf("%1.0f %1.0f\n%1.0f %1.0f",a[s[0]].t,a[s[0]].r,a[s[1]].t,a[s[1]].r);
	getch();
}

