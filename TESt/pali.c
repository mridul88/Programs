#include<stdio.h>
long long n;
int palindrome(int base )
{
   long long rev = 0, pp = n;
   while( pp)
   {
      rev = base * rev + pp %base;
      pp  /= base;
   }
   return rev == n;
}
int main()
{
   int tests;
   long long int i,k,b;
   for(scanf("%d",&tests);tests--;)
   {
      scanf("%lld",&n);
      b = n - 1;
      if( n <= 2 ) printf("%d\n",n==1?2:3);
      else
      {
	 for(i = 2; i*i < n; i++)
	 {
	    if( palindrome(i))
	    {
	       b = i;
	       break;
	    }
	 }
	 if( i * i >= n ) 
	    for( i = 2; i * ( i + 1) < n ; i++) if( n%i == 0) b = n/i-1;
	 printf("%lld\n",b);
      }
   }
   return 0;
}
