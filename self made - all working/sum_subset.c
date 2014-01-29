/* This program finds the subset of the numbers having the sum =x, it starts with a particular index and move upwards
    because if it move downwards , then termination condition i can't find. 
    I am not sure that it includes all subsets or not*/
    
#include<stdio.h>

struct answer
{
       int data;
       int index;
};

int search(int a[],struct answer ans[],int x,int p,int q,int n,int sum)
{
         
    static int i=0;     
    if(a[p]<=x && p<n)    // Here the element is added in yh ans array 
    {
               //printf("added\n");
               ans[q].data=a[p];
               ans[q].index= p;
               x=x-a[p];
               q++;
               p++;
               //printf("--AdDED--index=%d q=%d p=%d x=%d\n",ans[q].index,q,p,x);
               search(a,ans,x,p,q,n,sum);
    }
    else if( p<n && a[p]>x)     // if number>required, then it skips it
    {
               //printf("skip\n");  
               p++;
               search(a,ans,x,p,q,n,sum);
    }
    else if(p==n && x!=0) // it removes the last inserted number, so that we can get the answer 
    {                      // eg. 5 10 15 20     sum = 20,   ans = 5 15,  so need to pop 10.
               //temp=ans[q].index;
                //printf("delete\n x= %d,q= %d\n",x,q);  
                x=x+a[ans[q-1].index];
                p=ans[q-1].index+1;
                q=q-1;
                if(q==0)
                        return q;
                //printf("delete\n x= %d,q= %d\n",x,q); 
                search(a,ans,x,p,q,n,sum);
    }
    else if(x==0)
    {
         if(p==n)
          {     
                int k;
                printf("------------\n");
                for(k=0;k<q;k++)
                          printf(" %d\n",ans[k]);
                printf("--------------");  
                i++;
                //printf("i====   %d,x=%d, sum=%d\n",i,x,sum);
                p=i;
                q=0;
                search(a,ans,sum,p,q,n,sum);
          }     
         else          
                   return q;
    }
    return q;
              
}

int main()
{
       int *a,n,sum,i;
       struct answer *ans;
       printf("Enter the no. of elements\n");
       scanf("%d",&n);
       a=malloc(sizeof(int)*n);
       ans=malloc( n*sizeof(struct answer));
       for(i=0;i<n;i++)
                 scanf("%d",&a[i]);
       printf("\nEnter the value of sum");
       scanf("%d",&sum);
      // for(i=0;i<n;i++)
             search(a,ans,sum,0,0,n,sum);
       while(getchar()!='\n');
       getchar();          
       return 0;
}          
       
