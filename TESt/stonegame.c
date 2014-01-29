///---------codechef easy stone game problem----------------///
#include<stdio.h>

int main()
{
      int i,stone[101],n,t,count=0;
      scanf("%d",&t);
      while(t--)
      {
                scanf("%d",&n);
                count=0;
                for(i=1;i<=n;i++)
                {
                         scanf("%d",&stone[i]);
                         if(stone[i]>=i)
                         {
                                   count+=stone[i]/i;
                         }
                }
                if(count%2==0)
                     printf("BOB\n");
                else
                     printf("ALICE\n");
      }
      getchar();
      getchar();
      return 0;
}             
