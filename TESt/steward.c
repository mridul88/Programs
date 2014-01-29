#include<stdio.h>

int main()
{
    int count=0,n,k,t;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
    {
            scanf("%d",&t);
            if(t%k==0)
                 count++;
    }
    printf("%d",count);
    return 0;
}        
