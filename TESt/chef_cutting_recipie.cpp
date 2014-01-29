#include<stdio.h>

/* program is to find the gcd of more than 2 numbers, which are stored in array a*/

int gcd(int a,int b)
{
    if(b==0)
       return a;
    if(a<b)
           gcd(b,a);
    else
        return (gcd(b,a%b));   
}

int main()
{
     int i,j,end,t,n,a[50],b[50],temp;
     scanf("%d",&t);
     while(t--)
     {
             scanf("%d",&n);
             for(i=0;i<n;i++)
             {
                       scanf("%d",&a[i]);
                       b[i]=a[i];
             }
             for(end=n;end>1;)
             {
                   for(j=0,i=0;j<end;j+=2,i++)
                   {
                        if(j+1<end)              
                               temp=gcd(b[j],b[j+1]);
                        else
                               temp=b[j];
                        b[i]=temp;
                   } 
                   end=i;
             }
             for(i=0;i<n;i++)
             {
                       printf("%d ",a[i]/b[0]);
             }
     }
     getchar();
     getchar();
     return 0;
}
