/* Prorgram to no. of path in the directed graph */
//not proper working
#include<stdio.h>

struct list
{
       int data,added;
       struct list *next;
}*last[20];
       
struct node
{
       int data,color,path;
       struct list *next;
       struct node *parent;
} arr[20];
int a[20],top=-1,handle=-1;

int push(int n)
{
        a[++handle]=n;
        top=handle;
        return 0;      
}

int pop()
{                                                            
      return(a[top--]);
}
int pop_delete()
{
       return(a[handle--]);
}
       
int insert(struct list **start,struct list **last,int n)
{
       struct list *temp;
       temp=malloc(sizeof(struct list));
       temp->data=n;
       temp->next=NULL;
       temp->added=0;
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
int print_st()
{
           int i;
           printf("The staack:\n");
           for(i=0;i<=top;i++)
                 printf("%d\n",a[i]);
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

int dfs(int source, int target)
{
        int k,v;      
        struct list * temp;
        
        push(source);
        arr[source].color=1;
        printf("..%d..",arr[source].data);

        while(top!=-1)
        {
                  v=pop();
                  temp=arr[v].next;
                  while(temp!=NULL)
                  {
                          k=temp->data-1;
                          if(arr[k].color!=0 )//&& temp->added==0)
                          {
                                     arr[v].path+=arr[k].path;
                                     arr[k].parent=&arr[v];
                                     temp->added=1;
                                     printf("from node %d   path = %d add node :%d\n",arr[v].data,arr[v].path,arr[k].data);
                          }
                          else if(arr[k].color==0)
                          {                
                                   arr[k].color=1;
                                   arr[k].parent=&arr[v];          //not proper working
                                   push(k);
                                   printf("..%d..",arr[k].data);
                                   break;
                          }
                          temp=temp->next;
                   }
                   if(temp==NULL)
                   { 
                              arr[v].color=2;                       
                              pop_delete();
                              printf("\n Finish node :%d\n",arr[v].data);
                   }   
        }
        printf("\n Total Number of path from node %d to %d  : %4d\n",source+1,target+1,arr[source].path);
        return 0;
}
                                                            
int main()
{
       int i,n,ch,s,t;
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
       printf("\n enter the source node and the target node\n");
       scanf("%d%d",&s,&t);
       for(i=0;i<n;i++)
       {
                arr[i].color=0;
                arr[i].parent=NULL;
                arr[i].path=0;
       }
       arr[t-1].path=1;
       arr[t-1].color=1;
       dfs(s-1,t-1);                                             
       getchar();
       getchar();                           
       return 0;
}
