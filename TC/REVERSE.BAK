#include<iostream.h>
int nod(int);
void main()
{
	cout<<"enter the no. to be reversed \n";
	long int i,l,r=0,n,k;
	cin>>n;
	k=nod(n);
	for(i=0;i<k;i++)
	{
		l= n%10;
		n=n/10;
		r=r*10+l;
	}
	cout<<"reverse no.is = "<<r;

}
int nod(int n)
{
	int count=0;
	while(n>0)
	{
		n=n/10;
		count++;
	}
	return(count);
}