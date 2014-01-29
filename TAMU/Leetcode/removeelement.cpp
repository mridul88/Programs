#include<cstdio>

using namespace std;

void swap(int* a, int* b)
{
    int c =*a;
    *a = *b;
    *b=c;
    return;
}

int removeElement(int a[], int n, int key) {
    int last=n, i;
    for(i=0;i<last; i++)
    {
        if(a[i] == key)
        {
            while(last > i && a[--last]==key);
            swap(&a[i],&a[last]);
        }
    }
    return last;
}

int main()
{
    const int size = 2;
    int a[size],n,i,last;
    for(i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("key");
    scanf("%d",&n);
    last = removeElement(a,size,n);
    for(i=0;i<last;i++)
        printf("%d,",a[i]);
    return 0;
}
