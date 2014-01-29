// this is teh solution of codechef problem - Rise and fall of the problem (medium), find
// 

#include<stdio.h>
#include<math.h>

int main()
{
      double dummy=0,f;
      int temp,first,n,k,i,j,d=1,m=1,bit[32],last[10]={0};
      
      scanf("%d %d",&n,&k);  // first calculate the mantissa( this only determine the number,  charcteritics only detrmine the )
      f= (double)pow(10,modf((double)n*log10((double)n),&dummy)+k-1); // decimal position; mantissa is the fractional part of log(number)
                            //take then the antilog(i.e pow(10,--)). it will ggive u the number in scirntific form.
      
      first=(int)f;
      temp=k;
      for(; k > 0; k--) 
            m*=10;
      for(i=0;i<32;i++)
      {
              bit[i]=0;         
              if((n&(1<<i))>0)
                   bit[i]=1;
      }
      for(i=31;bit[i]==0;i--);
      for(j=i;j>=0;j--) // get the last k digit using cormen algo
      {
             d=(d*d)%m;
             if(bit[j]==1)
             {
                   d=(d*n)%m;
             }
      }      
      for(i=0;d>0;i++)
      {
              last[i]=d%10;
              d=d/10;
      }
                                 
      printf("\nfirst=%d  last=",first);
      for(i=temp-1;i>=0;i--)
      {
               printf("%d",last[i]);
      }          
                             
      getchar();
      getchar();
      return 0;
}        
