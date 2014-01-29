#include<iostream.h>
#include<math.h>
void main()
{
	cout<<"enter the coeffecients of quadratic equation  ax^2 + bx + c = 0\n";
	float a,b,c,d,r1,r2;
	cin>>a>>b>>c;
	d=b*b-4*a*c;
	if(d>=0)
	{
		r1=(-b+sqrt(d))/2;
		r2=(-b-sqrt(d))/2;
		cout<<"the roots are: \n"<<r1<<"\n"<<r2;
	}
	else
		cout<<"roots are not real";
}
