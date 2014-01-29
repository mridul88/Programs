#include<iostream>
#include<cmath>

using namespace std;
int main()
{
	cout<<"enter the sides of triangle\n";
	float a,b,c,area,s;
	cin>>a>>b>>c;
	if(a+b>c&&b+c>a&&c+a>b)
	{
		s=(a+b+c)/2;
		area=sqrt(s*(s-a)*(s-b)*(s-c));
		cout<<"area of a triangle is = "<<area;
	}
	else
		cout<<"triangle doesn't exists";
		
	 while(getchar()!='\n');
	getchar();
	return 0;
}
