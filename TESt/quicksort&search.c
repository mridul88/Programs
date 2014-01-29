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
      int n,i,s,l,g=41,*k;
      cell *a;
      int (*comp)(cell *c,cell *b);
      comp =&compare;
      scanf("%d",&n);
      a=(cell *)malloc(sizeof(cell)*n);
      for(i=0;i<n;i++)
      {
                scanf("%d%d",&a[i].start,&l);
                a[i].finish=a[i].start+l-1;
              //  a[i]=rand()%100;
      }
      for(i=0;i<n;i++)
      {
               //printf("%d  ",a[i]);
                printf("%d %d\n",a[i].start,a[i].finish);
      }
      qsort(a,n,sizeof(cell),comp);
      //k=bsearch(&g,a,n,sizeof(int),comp);   
      for(i=0;i<n;i++)
      {
        ///       printf("%d  ",a[i]);
                printf("\n%d %d",a[i].start,a[i].finish);
      }
      //if(k!=NULL)
      //       printf("\ngtf%u %u a=%u",(k-a),k,a);
      getchar();
      getchar();
      return 0;
}         
      
