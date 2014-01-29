#include<stdio.h>

/* we can get nCr in O(nCr) time and O(r) space.
   assume there is an array of n items call it b filled with b[j]=j;
   so, question is to select r objects from it;
   
   start is teh current pointer in the r size array, this is the 
   position where you enter the value from its just previous_value +1 to
   n-rth value;
   size is the size of array, use to stop;
   k is used to  keep track of the previous value filled;i.e the value filled in  
   a[start-1];
   n is the total item; 
   r is the number of items we are still left to select; it is = size-start;
   
   Idea is to replace the value the start location with the values from the 
   previous filled location a[start-1]+1  to n-r;
   */

// int b[10]={1,2,3,4,5,6,7,8,9,10}; only for understanding 

int select(int *a,int start,int size,int n,int k)
{
    int j;
    static int count=1;
    if((size-start)>n || (size-start)<0 || n<0)
    {
           printf("error\n");
           return 0;
    }
    else if(size==0 || n==0)
    {
               printf("1. Select none\n");
               return 0;
    }
    else if(start==size)
    {
           int i;         
           printf("%3d.  ",count++);         
           for(i=0;i<size;i++)
               printf("%3d",a[i]);
           printf("\n");
           return 0;
    }
    for(j=k;j<=(n-(size-start));j++)
    {
             a[start]= j+1;  //same  as b[j];
             select(a,start+1,size,n,j+1);
    }
    return 0;
}

int main()
{
    int *a,n,r;
    scanf("%d%d",&n,&r);
    a=(int *)malloc(sizeof(int)*r);
    select(a,0,r,n,0);
    getchar();
    getchar();
    return 0;
}                          
