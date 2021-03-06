#include<iostream>
#include<cmath>
using namespace std;
class vector
{
	float x,y,z,a_,b_,c_;
	public:
		vector(){}
		vector(float,float,float);
		void 		getdata();
		vector(float,float);
		vector(float);
		vector operator +(vector);
		vector operator - (vector);
		friend vector dotprod(vector,vector);
		friend vector operator *(vector,vector);
		friend float mod(vector);
		void display();
};
vector :: vector(float a,float b,float c)
{
	x=a;
	y=b;
	z=c;
}
vector::vector(float a,float b)
{
	x=a;
	y=b;
	z=0;
}
vector::vector(float a)
{
	x=a;
	y=0;
	z=0;
}
vector vector::operator+(vector v)
{
	vector r;
	r.x=v.x+x;
	r.y=v.y+y;
	r.z=v.z+z;
	return (r);
}
vector vector:: operator -(vector v)
{
	vector r;
	r.x=x-v.x;
	r.y=y-v.y;
	r.z=z-v.z;
	return (r);
}
void vector::getdata(void)
{
	cin>>x>>y>>z;
}
void vector::display(void)
{
	cout<<x<<"i + "<<y<<"j + "<<z<<"k"<<endl; ;
}
float mod(vector v)
{
	float mod;
	mod=sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
	return (mod);
}
vector dotprod(vector v,vector w)
{
	vector u;
	u.x=v.x*w.x;
	u.y=v.y*w.y;
	u.z=v.z*w.z;
	return u;
}
vector operator *(vector v,vector w)
{
	vector u;
	u.x=v.y*w.z - v.z*w.y;
	u.y=v.x*w.z - v.z*w.x;
	u.z=v.x*w.y - v.y*w.x;
	return u;
}
int main()
{
	vector a,b(2),c(2,3),d(2,3,4),e,f,g;
	a.getdata();
	e=b+c;
	f=e-d;
	g=e*a;
	dotprod(e,a);
	mod(b);
	a.display();  d.display();  g.display();
	b.display();  e.display();
  c.display() ;  f.display();
	getchar();
	return 0;
}
