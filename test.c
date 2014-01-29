#include<stdio.h>

int no_path(int a[], int n, int start)
{
    static int count =0;
    if(start == n-1)
    {
        count++;
        return count;
    }
    if(start+1<n)
        no_path(a,n,start+1);
    if(start+2<n)
            no_path(a,n,start+2);

    return count;
}

int nCr(int n, int r, int start, int prev_val)
{
    static int count =0;
    int j;
    if(start ==r)
    {
        count++;
        return count;
    }
    for(j= prev_val;j<=(n-(r-start));j++)
    {
        nCr(n,r,start+1,j+1);
    }
    return count;
}

 int count;

int pow(int x, int n)
{
if(n==0)return(1);
else if(n%2==0)
{
count++;
return(pow(x,n/2)*pow(x,(n/2)));

}
else
{
count+=2;
return(x*pow(x,n/2)*pow(x,(n/2)));
}
}

int main()
{
    int c,nc=0;
    int **p, i=2,j=3;
    p =  malloc(sizeof(int)*i);
    for(c=0;c<=i;c++)
        p[c] = malloc(sizeof(int)*j);

    p[2][2]=4;
    printf("%d",p[2][2]);
    return 0;
}
