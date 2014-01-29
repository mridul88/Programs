#include<stdio.h>
#include<stdlib.h>

int heapify(int a[], int i, int n)
{
	int j,item,temp;
	j=2*i;
	item=a[i];

	while(j<=n)
	{
		if(j<n && a[j]>a[j+1])
			j++;
		if(item<a[j])
			return 0;
		else
        {
			a[j/2]=a[j];
			j=2*j;
	     }
		a[j/2]=item;
	}
	return 0;
}

void build_minheap(int a[],int n)
{
     int i;
	for(i=(n+1)/2;i>0;i--)
		heapify(a,i,n);
}

int * fn(int a[],int n,int k)
{
    int i=0,*h,temp,j,*b;

    b = (int *)malloc(sizeof(int)*k);
    h = (int *)malloc(sizeof(int)*(k+1));
    for(i=0;i<k;i++)  //copy the contents to a heap
    {
       h[i+1] = a[i];
    }

    build_minheap(h,k);
    for(j=0;j<k;j++)
                printf("\n%d",h[j+1]);

    for(i=0;i<n-k+1;i++)
    {
        b[i]= h[1];
        if(a[i]== b[i]) //curr index is min
        {
             temp =h[1];
             h[1]= h[k];
             h[k]=temp;

             h[k]= a[i+k];
             heapify(h,1,k-1);
             //printf("out");
        }
        else
        {
             for(j=i+1;j<=k+i;j++)  //copy the contents to a heap
             {
                h[j-i] = a[j];
             }
             build_minheap(h,k);
             for(j=0;j<k;j++)
                printf("\n%d",h[j+1]);
        }

    }
    printf("-----------\n");
     for(i=0;i<k;i++)
		printf("\n%d",b[i]);
    return b;
}

int main()
{
	int n=5,k=3,i,*b;
	int a[5] = {8,6,4,3,2};
     fn(a,n,k);
    return 0;
}
