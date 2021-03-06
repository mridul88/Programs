/* program to implement the prim's algo for an undirected graph
   input:  No. of nodes & then all edges    output:  min wt spanning tree*/

#include<stdio.h>

struct list
{
       int data,weight;
       struct list *next;
}*last[20];
       
struct node
{
       int data,color;
       struct list *next;
       struct node *parent;
} arr[20];

struct edge
{
        int source,destination,weight;
}
                                                                                                      
int insert(struct list **start,struct list **last,int n)
{
       struct list *temp;
       temp=malloc(sizeof(struct list));
       temp->data=n;
       temp->next=NULL;
       if(*start==NULL)
       {       
               //printf(" first\n");
               *start=temp;
               *last=temp;
       }     
       else
       {
                (*last)->next=temp;
                *last=temp;
       }      
       return 0;
}

int print(int n)
{
       int i,j;
       struct list *temp;
       printf("\nThe Adjancency list representation of graph is:\n");
       for(i=0;i<n;i++)
       {
               printf("%d---->",i+1);        
               temp=arr[i].next;
               while(temp!=NULL)
               {
                        printf("%d-->",temp->data);
                        temp=temp->next;
               }
               printf("\n"); 
       }
       return 0;
}       
                                                                            
int main()
{
       int i,j,n,ch;
       struct node *start=NULL;
       printf("enter the number of nodes\n");
       scanf("%d",&n);
       arr=malloc(sizeof(struct node)*n);
