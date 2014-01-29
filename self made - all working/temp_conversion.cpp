#include<iostream>

using namespace std;

class temp
{
	  float c;
  public:
	  float f;
	  float	result(float f);
};
float temp:: result(float f)
{
	c=(f-32)*5/9;
	cout<<"celsius ="<< c;
	return 0;
}

int main()
{
	temp t;
	cout<<"enter temp in faherheut";
	cin>>t.f;
	t.result(t.f);
	while(getchar()!='\n');
	getchar();
	 return 0;
}
