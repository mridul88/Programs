/* program to implement the prim's algo for an undirected graph
   input:  No. of nodes & then all edges    output:  min wt spanning tree*/

#include<stdio.h>

class node
{
      
class list
{
      

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
       int i,j,no_nodes,s,d,w;
       printf("enter the number of nodes\n");
       scanf("%d",&no_nodes);
       printf("Enter the edges of the graph as\nTo terminate enter 0\n\nFirst Node   Second Node  Weight of the Edge\n");
       scanf("%d",&s);
       while(s!=0)
       {
                  scanf("%d%d",&d,&w);
                  insert(s,d,w);
