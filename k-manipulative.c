#include<stdio.h>

int Min_heapify(int a[], int i, int n)
{
	int j,item,temp;
	j=2*i;
	item=a[i];
	while(j<=n)
	{
		if(j<n && a[j]>a[j+1])
            j++;
		if(item < a[j])
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

int main()
{
    int i,j,count = 1,n,*a,*b,temp,k;
    scanf("%d",&n);
    a = (int *) malloc(sizeof(int)*n);
    b = (int *) malloc(sizeof(int)*(n+1));
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=-1;
    }
    b[n]=-1;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            temp = a[i]^a[j];
            for(k=0;k<=n;k++)
            {
               // printf("%d %d",b[i],count);
            }
            if(b[count]== -1)
            {
                b[count] = temp;
                //printf("%d",b[count]);
                Min_heapify(b,count,n);
            }
            else if(temp > b[1])
            {
                 b[1]= temp;
                 Min_heapify(b,1,n);
            }
            count = (count+1)%(n+1);
        }
    }

    for(count =-1;b[1];count++)
    {
       b[1] = b[1]>>1;
    }
    printf("%d",count);
    return 0;
}



