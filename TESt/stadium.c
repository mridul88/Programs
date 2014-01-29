//-----------codechef problem medium stadium---------------//
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
       int start,finish;
}cell;

int compare(cell *c,cell *b)
{
       if(c->finish < b->finish)
           return -1;
       else if(c->finish > b->finish)
         return 1;
       else 
           return 0;
       return 0;    
}  
         
int main()
{
      int n,i,count=1,l;
      cell *a;
      int (*comp)(cell *c,cell *b)=compare;
      scanf("%d",&n);
      a=(cell *)malloc(sizeof(cell)*n);
      for(i=0;i<n;i++)
      {
                scanf("%d%d",&a[i].start,&l);
                a[i].finish=a[i].start+l-1;
      }
     /* for(i=0;i<n;i++)
      {       
                printf("%d %d\n",a[i].start,a[i].finish);
      }*/
      qsort(a,n,sizeof(cell),comp);
      l=a[0].finish;
      for(i=1;i<n;i++)
      {
                   if(a[i].start>l+1)
                   { 
                        count++; 
                        l=a[i].finish;
                   }
      }  
      printf("%d",count);
      getchar();
      getchar();
      return 0;
}         
      
