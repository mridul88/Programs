#include<stdio.h>

int main()
{
    unsigned long int n;
    unsigned int t;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%ld",&n);
        if(n%2==0)
        {
            printf("%ld\n",n);
        }
        else
        {
            printf("%ld\n",n-1);
        }
    }
    return 0;

}
