#include<stdio.h>

int a[1000];

unsigned long int all_combination(int start,int max,int n)
{
    int i,k;
    static unsigned long int count;
    if(start == n)
    {
        for(i=0;i<10;i++)
            printf("%d",a[i]);
        printf("\n");
        return (count++ % 1000000007);
    }
    for(i=start;i<n;i++)
    {
        for(k=1;k<=(max+1);k++)
        {
            a[i]=k;
            if(k < max)
                all_combination(i+1,max,n);
            else
                all_combination(i+1,max+1,n);
        }
    }
    return count;

}

int main()
{
    unsigned long int ans;
    int t,n,i;

    scanf("%d",&t);
    while(t--)
    {
        ans=1;
        scanf("%d",&n);
        ans = all_combination(1,1,n);
        printf("%ld\n",ans);
    }
    return 0;

}
