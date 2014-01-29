#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
class user
{
	char name[36];
	float bill,unit;

  public:

	 float  input(void);
	 void output(void);

};
float user:: input (void)
{
	cin>>name;
	cin>>unit;
	return 0;

}
void  user::output(void)
{
	bill=0.60*((unit<=100)?unit:100) + 0.80*((unit<=300&&unit>100)?(unit-100):0)
		  +0.90*((unit>300)?(unit-300):0)+50+((unit>300)?160:0);
	if(bill>300)
		 bill = bill+(0.15*bill);
	printf("bill of %s = %f \n" ,name,bill);
}

int main()
{
	int n;
	printf("enter the no. of consumers");
	cin>>n;
	user *u;
	u=(user *)malloc(sizeof(int)*n);
	for(int i=0; i<n; i++)
	{
		printf("enter the name of user and unit consumed by user[%d]:",i);
		u[i].input();
		u[i].output();
		printf("do you want to quit 'Y' or 'N'\n");
		if(getchar()=='y'||getchar()=='Y')
			return 0;
	}
	while(getchar()!='\n');
	getchar();
	return 0;
}





