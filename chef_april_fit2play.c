#include<stdio.h>
#include<malloc.h>


int main()
{
    int n,t;
    long int i,*a,max_diff,*min_arr;
    scanf("%d",&t);
    while(t--)
    {
        max_diff=0;
        scanf("%d",&n);
        a = (long int*)malloc(n*sizeof(long int));
        min_arr = (long int*)malloc(n*sizeof(long int));

        if(n>0)
        {
            scanf("%ld",&a[0]);
            min_arr[0]=a[0];
        }

        for(i=1;i<n;i++)
        {
            scanf("%ld",&a[i]);
            if(a[i]<=min_arr[i-1])
                min_arr[i]=a[i];
            else
                min_arr[i]=min_arr[i-1];
        }

        for(i=n-1;i>=0;i--)
        {
            if(max_diff < (a[i]-min_arr[i]))
                max_diff = a[i]-min_arr[i];
        }

        if(n<=1 || max_diff<=0)
            printf("UNFIT\n");
        else
            printf("%ld\n",max_diff);

        free(a);
        free(min_arr);
    }
    return 0;
}
