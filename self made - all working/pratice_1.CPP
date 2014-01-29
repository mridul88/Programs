#include<stdio.h>
#include<math.h>
int main()
{
	float s,amax,vmax,v,a,k,l,t;
	scanf("%f %f %f",&s,&amax,&vmax);
	v=sqrt(amax*s);
	if(v<=vmax)
	{
		t=2*sqrt(s/amax);
		printf("%f",t);
	}
	else
	{
		k=(vmax*vmax)/(2*amax);
		l=sqrt((2*k)/amax);
		t=2*l+ (s-(2*k))/vmax;
		printf("%f",t);
	}
	getchar();
	return 0;
}

