//---this is the problem oof codechef medium level - byletandian coins-----------//

#include<cstdio>
#include<map>

using namespace std;

map<int,int> m;  

long long find(long long n)
{
     long long d,p,q,r,temp;
     d=n;
     while(n>4)
     {
 
              temp=(n/2)+(n/3)+(n/4);
              if(temp>d)
              {
                        d=temp;
                        if( m[n/2]!=0)
                        {
                                p=m[n/2];
                        }
                        else
                        {         
                                  p=m[n/2]=find(n/2);
                                  
                        }
                         if( m[n/3]!=0)
                        {
                                q=m[n/3];
                        }
                        else
                        {         
                                  q=m[n/3]=find(n/3);
                                  
                        }
                         if( m[n/4]!=0)
                        {
                                r=m[n/4];
                        }
                        else
                        {         
                                  r=m[n/4]=find(n/4);
                                  
                        }
                        
                        if(p+q+r>d)
                              d=p+q+r;
              }
              return d;
     }
     return d;
}

int main()
{
      long long n,i=0,j=0,a[10];
      
      while((scanf("%lld",&n))!=EOF)
      {               
              a[i]=find(n);
              i++;
      }
      for(j=0;j<i;j++)
             printf("%lld\n",a[j]);           
      return 0;
}
