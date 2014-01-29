//-------codechef easy problem - ATM---------//

#include<stdio.h>

int main()
{
      int x;
      float b;
      scanf("%d %f",&x,&b);
      if(x<=(b-0.5)&& x%5==0)
      {
              b=b-(0.5+x);
      }
      printf("%.2f",b);
      return 0;
}
