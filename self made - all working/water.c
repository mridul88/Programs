#include<stdio.h>

int water(int a,int b,int c)
{
    int i,j,step=0;
     for(i=0;i<a;i++)
      for(j=0;j<a;j++)
       if(c==(i*a-j*b))
        {
                       step=2+(i+j-2)*2;
                       printf("\n%d",step);
                       return 0;
       }
     printf("\n-1\n");  
    return 0;
}
int main()
{
    int a,b,c,t;
    scanf("%d",&t);
    while(t-->0)
    {
      scanf("%d%d%d",&a,&b,&c);
      water(a,b,c);
    }    
    getchar();
    getchar();
    return 0;
}   
    
