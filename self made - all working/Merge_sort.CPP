/* use to solve the codechef problem steford houses*/

#include<cstdio>
#include<cstdlib>
#define MAX 100001

using namespace std;

int merge(int a[],int p,int q,int r)
{
	  int i,j,l,temp[MAX],count=0;
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
                                   count=count + (q-i);
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
		printf("%d,",temp[i]);     */
	for(i=1;i<=l;i++)
		a[p+i-1]=temp[i];
  /*	for(i=1;i<=5;i++)
		printf("%d,",a[i]);  */
    return count; 
}

int mergesort(int a[],int p,int r)
{
       int q,size,count=0;
       size=r-p+1;
       if(size<=1)
		               return 0;
         q=p+(size/2)-1;
	     count=count+mergesort(a,p,q);
	     count=count+mergesort(a,q+1,r);
	     count=count+merge(a,p,q+1,r);
	     return count;
}

int main()
{  
          int *a,p=0,n,count=0;
	      scanf("%d",&n);
	      a=(int *)malloc((n+1)*sizeof(int));
	      a[0]=0;
	      for(p=1;p<=n;p++)
	      {
                         scanf("%d",&a[p]);
          }
	      count=mergesort(a,1,n);
	      for(p=1;p<=n;p++)
		                    printf("\n%d",a[p]);
		                    
        printf("count=%d",count); // count the number of inversions       
       // system("pause");
       // getchar();
        return 0;
}
