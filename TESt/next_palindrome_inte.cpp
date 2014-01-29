#include<cstdio>

using namespace std;

int replace (int i,int l,int *a)
{
     int j,k;
     for(j=1,k=l;j<=i;j++,k--)
     {
              a[j]=a[k];
     } 
     return 0;
}               

int next_palindrome(int n)
{
    int np,i,l,arr[10],temp;
    temp=replace(l/2,l,arr);
    if(temp>n)  // gives u the direct answer
    {
                  //printf("%d",temp);
                  return temp;
         }
         else     //increase the number smmallest signficant digit after mid point by 1, take mod 10
         {
               for(i=l/2+1;i<=l;i++)
               {
                      if(arr[i]==9)
                      {
                           arr[i]=0;
                      }
                      else
                      {
                           arr[i]++;
                           temp=replace(l/2,l,arr);  
                          // printf("%d",temp);
                           return temp;
                      }
               }
         }    
   // printf("np=%d\n",np);             
    return np;
}

int main()
{
    int t,l=0,j,i;
    char c,a[1000000];
    scanf("%d",&t);
    printf("%d",t);
    for(i=0;i<t;i++)
    {
         l=0; 
         j=1;       
         a[0]=-1;   
         while((c=getchar())!='\n')
         {
                 a[j]=c;
                 j++;
         }                  
          for(int k=1;k<j;k++)
          {     
              printf("%c",a[k]);
          }          
          next_palindrome(a,j);
    }
    printf("fasfsfsdf");
    getchar();
    getchar();
    return 0;
}                    
