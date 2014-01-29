#include<stdio.h>
#define NUM 99999999

int water( int a, int b, int c)          // if answer is in bigger vessel, here only change bigger vessel & search ans there
{
    int counter=0,step=0,r=1,f=0,temp=0,bmax=b;
    
    for(counter=0;counter<a && r!=0;counter++)
    {
             r=b%a;
             f=b/a;       
             if(a*((c-r)/a)==(c-r))
             {
                        //printf("a=%d,b=%d\n",a,b);          
                        temp=(f-((c-r)/a));
                       /* if(temp<0)
                             printf("FUCK");*/
                        //printf("r=%d f=%d\n",r,f);
                        step=step+temp*2;
                        //printf("tepm=%d, step=%d\n",temp,step);
                        return step;
             }
             b=bmax-(a-r);
             step=step+4+(f*2);
    }
    //printf("-1");
    return NUM;
}

int water1(int a, int b, int c)   // if answer is in smaller vessel, here only change in smaller vessel & search there only
{
    int counter=0,step=0,r=0,f=0,temp=0,amax=a;
    for(counter=0;counter<a && a!=0;counter++)
    {
             r=(b-a)%amax;
             f=(b-a)/amax;       
             if(c==(amax-r))
             {
                        //printf("a=%d,b=%d\n",a,b);          
                        //printf("r=%d f=%d\n",r,f);
                        step=step+4+(f*2);
                        //printf("step=%d\n",step);
                        return step;
             }
             a=amax-r;
             step=step+4+(f*2);
    }
    //printf("-1");
    return NUM;
}
                                         
int main()
{
    int a,b,c,t,i=0,temp,d[100]={0},l,step;
    scanf("%d",&t);                                     
    while(i<t)
    {        
      step=0;l=0;      
      scanf("%d%d%d",&a,&b,&c);         
      if(a>b)
      {
             temp=b;
             b=a;
             a=temp;
      }
      step=water(a,b,c);
      l=water1(a,b,c);
      //printf("step=%d ,l=%d\n",step,l);    
      if(l<step)
            d[i]=(l==NUM?-1:l);
      else
            d[i]=(step==NUM?-1:step);
      if(c==0)
            d[i]=0;
      else if(c==a||c==b)
             d[i]=1;  
      else if(c>b)
             d[i]=-1;                 
      //printf("\n%d",d[i]);       
      i++;
   }
   
   for(i=0;i<t;i++)
         printf("\n%d",d[i]);
   getchar();
   getchar();
    return 0;
}   
