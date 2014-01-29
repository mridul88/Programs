#include<iostream>

using namespace std;

int pop(int[], int *);
int push (int[], int ,int *);
int main()
{
	int s[5],top=-1,n,k,i;
	for(i=0;i<5;i++)
	{
		cin>>n;
		push(s,n,&top);
	}
	for(i=0;i<5;i++)
	{
		k=pop(s,&top);
		cout<<k<<"\n";
	}
}
int push(int s[5],int n ,int*top)
{
	*top+=1;
	if(*top>4)
	{
		cout<<"overflow";
		return 0;
	}
	s[*top]=n;
	return 0;
}
int pop(int s[5], int *top)
{
	if(*top<0)
	{
		cout<<"underflow";
		return 0;
	}
	*top=*top-1;
	return ( s[*top +1]);
}
