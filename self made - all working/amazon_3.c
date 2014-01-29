#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *a1,*a2,i,j,count=0,k,n;
    scanf("%d%d",&n,&k);
    a1 = (int*)malloc(sizeof(int)*n);
    a2 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        a1[i] = 10+i*10;
    for(i=0;i<n;i++)
        printf("%d ",a1[i]);
    //printf("%d\n",sizeof(a1));
    for(i=0;i<k;i++)
    {
        for(j=0;j<n/k;j++)
        {
            a2[count] = a1[i+j*k];
            count++;
        }
        //printf("hello");
    }
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d",a2[i]);
    return 0;
}
