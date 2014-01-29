// This Program is used to find the N! where N is very large, multiply using array
#include<stdio.h>

int a[100][300];

int multiply(int t,int m,int size)
{
     int i,temp=0,x=0;
     for(i=0;i<size;i++)
     {
             x=a[t][i]*m+temp;
             a[t][i]=x%10;
             temp=x/10;
     }
     size=i;
     for(i=size;temp>0;i++)
     {
             a[t][i]=temp%10;
             temp=temp/10;
     }
     size=i;                       
     return size;
}
  
          
int main()
{
     int i,n,size,testcase=1,j=0;
     {
            scanf("%d",&n);
            i=n;
            for(size=0;n>0;size++)
            {
                 a[j][size]=n%10;
                 n=n/10;
            }
            for(;i>1;i--)
            {
                  size=multiply(j,i-1,size);
            }
     }
            for(i=size-1;i>=0;i--)
            {
                 printf("%d",a[j][i]);
            }
     
     getchar();
     getchar();
     return 0;
}
/*  to subtract and then divide code--


int divide(int size_a,int size_b)   // find a/b result is stored in a variable
{
          int diff,,i,m,ans=0,size_temp;
          diff=size_a-size_b;
          for(i=0;i<size_b;i++)
          {
                      temp[i]=b[i];        
          }
           
          while(diff>1)
          {
                       m=pow(10,diff-1);
                       size_t=multilply(temp,m,size_t);
                       size_a=subtract(size_a,size_t);
                       ans=m+ans;
                       
                       
        */     
      
