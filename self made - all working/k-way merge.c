/* implement the k-way merge sort with a running time of nlgk*/
#include<stdio.h>
#include<stdlib.h>

int merge(int a[],int p,int q,int r)  // simply merge two sorted array
{
	  int i,j,l,temp[500];
	  i=p;
	  j=q;
	  l=0;
	  while(i<q && j<=r)
	  {
		            if(a[i]<a[j])
		            {
			                       l++;
			                       temp[l]=a[i];
			                       i++;
                }
		            else
		            {
			                       l++;
                             temp[l]=a[j];
			                       j++;
                }
	}
	
	if(i==q)
	        for(;j<=r;j++)
	        {
		                    temp[++l]=a[j];
         }
	else
	    while(i<q)
	    {
		            l++;
		            temp[l]=a[i];
		            i++;
     }
	/*for(i=1;i<=5;i++)
		printf("%d,",temp[i]);*/     
	for(i=1;i<=l;i++)
		a[p+i-1]=temp[i];
  /*	for(i=1;i<=5;i++)
		printf("%d,",a[i]);  */
    return 0; 
}

int mergesort(int a[],int p,int r,int k)
{
       int q,size;
       size=r-p+1;
       if(size/k<=1) 
		               return 0;
       q=p+k-1;    //It divides the array into sub-sorted k arrays and thus reduce time to lgk
	     mergesort(a,p,q,k);
	     mergesort(a,q+1,r,k);
	     merge(a,p,q+1,r);
	     return 0;
}

int main()
{  
        int *a,p=0,n,k;
        printf("enter the no. of sorted list");
	      scanf("%d",&k);
	      printf("Enter the no. of elements in a array");
	      scanf("%d",&n);
	      printf("Enter the elements of all the array");
	      a=malloc(sizeof(int)*(n*k));
	      a[0]=0;
	      for(p=1;p<=n*k;p++)
	      {
                         	scanf("%d",&a[p]);  // element are within  1-1000
		                   //   printf(",%d,",a[p]);
       }
	      mergesort(a,1,n*k,n);
	      for(p=1;p<=n*k;p++)
		                    printf("\n%d",a[p]);
        while(getchar()!='\n');
        getchar();
        return 0;
}
