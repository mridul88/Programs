#include<stdio.h>

int f(int *a,int n)
{
    printf("%d",a[n-1]);
    return 0;
}

int main()
{
     int n,s,*a,i;
     scanf("%d",&n);
     a=(int*)malloc(sizeof(int)*n);
     for(i=0;i<n;i++)
     {
           scanf("%d",&a[i]);
     }
     f(a,n);
     getchar();
     return 0;
}
