#include<stdio.h>

int get_diff(int a[],int i,int j)
{
                 if((a[j]-a[i])<0)
                                  return(a[i]-a[j]);
                  return (a[j]-a[i]);
}
   
int main()
{
        int n, *a,*diff,i;
        scanf("%d",&n);
        a= malloc(sizeof(int)*n);
        diff=malloc(sizeof(int)*(n));
        for(i=0;i<n;i++)
        {
                        scanf("%d",&a[i]);
                        diff[i]=0;
        }
        for(i=1;i<=n-1;i++)
                        diff[get_diff(a,i-1,i)]=1;
        for(i=1;i<=n-1;i++)
        {
                          //printf("%d",diff[i]);
                          if(diff[i]==0)
                          {
                                 printf("NOT JOlly Jumper");
                                 while(getchar()!='\n');
                                 getchar();
                                 return 0;
                          }
        }
        printf("Jolly Jumper");
        while(getchar()!='\n');
        getchar();
        return 0;
}                                              
