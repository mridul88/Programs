#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
long cord(long i,long &x,long &y)
{
  if(i==1)
    {
      x=0;y=0;return(1);
    }      
  long n = 1;long nold=1;long k=0;long p=0;
  while(n<i)
    {
      p+=6;
      nold = n;
      n+=p;
      k++;
    }
  n = nold+1;
  x = k + 1;
  y = k - 1;
  long l=0;
  while(n!=i && l<k-1)
    {
      n++;
      l++;
      x++;
      y--;
    }
  if(n==i)
    return(0);
  l=0;
  while(n!=i && l<p/6)
    {
      l++;
      n++;
      x--;
      y--;
    }
  if(n==i)
    return(0);
  l=0;
  while(n!=i && l<p/6)
    {
      l++;
      n++;
      x--;
      x--;
    }
  if(n==i)
    return(0);
  l=0;
  while(n!=i && l<p/6)
    {
      l++;
      n++;
      x--;
      y++;
    }
  if(n==i)
    return(0);
  l=0;
  while(n!=i && l<p/6)
    {
      l++;
      n++;
      x++;
      y++;
    }
   if(n==i)
    return(0);
  l=0;
  while(n!=i && l<p/6)
    {
      l++;
      n++;
      x++;
      x++;
    }
  while(n!=i)
    {
      x++;
      y--;
    }
  return(0);
}
int main()
{
  long a,b;
  cin>> a>> b;
  long x1,x2,y1,y2;
  cord(a,x1,y1);
  cord(b,x2,y2);
  a = abs(y2-y1);
  b = abs(x2-x1);
  if(a>b)
    cout<<a;
  else
    cout<<a+(b-a)/2;
    cin.clear();
	while (cin.get() != '\n')
		;
	cin.get();
}
