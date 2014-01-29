//------- codechef easy problem oDD ---------//
#include<stdio.h>

int main()
{
       unsigned int t,n,i,k=0;  // must use unsigned int as it signed depends on machine
       scanf("%u",&t);     // to act uniformily ude unsigned, whever deal with the bts.
       while(t--)
       {
                 scanf("%u",&n);
                 for(i=0;i<32;i++)
                 {
                         if( (n&(1<<i)) >0 )
                              k=i;
                 }
                 printf("%u\n",1<<k);
       }
       getchar();
       getchar();
       return 0;
}           
