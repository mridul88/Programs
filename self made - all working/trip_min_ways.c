#include<stdio.h>
#define N 1000000

int main()
{
    int s[N],w[N],d[N];
    int n,m,i,j,t,k;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",d+i);
    s[n-1]=0;
    w[n-1]=1;
    d[n]=d[n-1]+m+1;

    for(i=n-2;i>=0;i--)
    {
        t=d[i]+m;
        j=i+2;
        while(d[j]<=t)
            j++;
        j--;
        t=s[j];
        s[i]=t+1;
    
        for(k=j;s[k]==t;k--)
            w[i]+=w[k];
     }
    printf("%d %d\n",s[0]-1,w[0]);
    while(getchar()=='\n');
    return 0;
}
