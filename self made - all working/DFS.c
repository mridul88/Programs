#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct list
{
       int data;
       struct list *next;
}*last[20];
       
struct node
{
       int data,color,d_time,f_time;
       struct list *next;
       struct node *parent;
} arr[20];

int insert(struct list **start,struct list **last,int n)
{
       struct list *temp;
       temp=malloc(sizeof(struct list));
       temp->data=n;
       temp->next=NULL;
       if(*start==NULL)
       {       
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

int dfs(int u,int *t)
{
        int k;
        struct list *temp;        
        
        arr[u].color=1;
        arr[u].d_time = ++(*t);
        printf("..%d..",arr[u].data);
        temp=arr[u].next;
        while(temp!=NULL)
        {
                   k=temp->data-1;      
                   if(arr[k].color==0)
                   {                
                            arr[k].color=1;
                            arr[k].parent=&arr[u];
                            dfs(k,t);
                   }
                   temp=temp->next;
        }
        arr[u].color=2;
        arr[u].f_time= ++(*t);
        printf("\nnode:%4d dicovery time:%4d final time:%4d\n",u+1,arr[u].d_time,arr[u].f_time);
        return 0;
}
                                                            
int main()
{
       int i,time=0,n,ch,component=0;
       struct node *start=NULL;
       printf("enter the number of nodes\n");
       scanf("%d",&n);
       
       ch=getchar();
       for(i=1;i<=n;i++)
       {
                        arr[i-1].data=i;
                        arr[i-1].next=NULL;
                        last[i-1]=NULL;
                        printf("Enter the nodes connected to %d\n",i);
                        while((ch=getchar())!='\n')
                        {
                                       if(isdigit(ch)&&(ch-48)<=n)     
                                                 insert(&arr[i-1].next,&last[i-1],ch-48);
                        }
       }                                                           
       print(n);
       for(i=0;i<n;i++)
       {
                arr[i].color=0;
                arr[i].parent=NULL;
       }
       for(i=0;i<n;i++)
       {
                 if(arr[i].color==0)
                 {
                              printf("\nThe Depth first traversal of graph is starting from node %d:\n",i+1);     
                              dfs(i,&time);
                              component++;
                 }
       }  
       printf("\nNo. of Componenets in the Graph :%d\n",component);                         
       getchar();        
       return 0;
}
