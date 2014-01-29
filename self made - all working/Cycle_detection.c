/* Prorgram to find cycle in the directed graph using concept of back edge*/
#include<stdio.h>

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
       top--;
       return(a[handle--]);
}
       
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

int dfs(int u)
{
        int k,v,time=1;      
        struct list * temp;
        
        push(u);
        arr[u].color=1;
        printf("..%d..",arr[u].data);
        arr[u].d_time=time++;
        
        while(top!=-1)
        {
                  v=pop();
                  temp=arr[v].next;
                  while(temp!=NULL)
                  {
                          k=temp->data-1;
                          if(arr[k].color==1)
                          {
                                    printf("\nCycle present in graph\n");
                                    return 1;
                          }              
                          if(arr[k].color==0)
                          {                
                                   arr[k].color=1;
                                   arr[k].parent=&arr[u];
                                   arr[k].d_time=time++;
                                   push(k);
                                   printf("..%d..",arr[k].data);
                                   break;
                          }
                          
                          temp=temp->next;
                   }
                   if(temp==NULL)
                   {
                              arr[v].f_time=time++;
                              arr[v].color=2; 
                              //printf("\nnode:%4d dicovery time:%4d final time:%4d\n",v+1,arr[v].d_time,arr[v].f_time);
                   }   
        }
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
                              ch=dfs(i);
                              if(ch==1)
                                 break;
                 }
       }                       
       getchar();
       getchar();                           
       return 0;
}
