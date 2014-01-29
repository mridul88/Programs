#include<cstdio>

using namespace std;

int negate(unsigned int n)
{
    int original_n = n;
    int mask = ~0,i=0;
    for(;n%2==0;i++,n = n>>1);
    //if(i==0)
    //    i=1;
    printf("%d",i);
    mask = mask<<(i);
    printf("%d\n", (~original_n)&mask);
}

int main()
{
    int n,m,n_mask,max;
    scanf("%d %d",&n,&m);
    negate(n);
    negate(m);
    max = ~0;
    n_mask = ~( (max<<2)^(max<<5));
    printf("%d %d", ((m<<2)|(n&n_mask)), max );
    return 0;

}

