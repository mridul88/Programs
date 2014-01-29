#include<stdio.h>

int get_ans(int n)
{
    int i;
    //printf("n=%d\n",n);
    for(i=8;i>=0;i--)
    {
            if((n &(1<<i))>0)
            {
                   //printf("i=%d\n",i);
                   return((1<<(i)) -1);
            }
    }
    return -1;
}                   

int main()
{
      int t,n,ans,k;
      char ch;
      scanf("%d\n",&t);
      while(t--)
      {
              ans=0;  
              while((ch=getchar())!='\n')
              {
                       if( isdigit(ch))
                       {
                            ans=ans+ get_ans(ch-'0');
      //                      printf("ans= %d\n",ans);
                       }
              }
              if(ans%2!=0)
                           printf("Alice\n");
              else
                        printf("Bob\n");
      }
      getchar();
      getchar();
      return 0;
}                   
