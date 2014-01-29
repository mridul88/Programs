/* This is program to implement the questioin 9.6.1 of book - programming challenges*/ 
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define RED 1
#define BLUE 2

struct list
{
       int data;
       struct list *next;
}*last[20];
       
struct node
{
       int data,color,d,state;
       struct list *next;
       struct node *parent;
} arr[20];
int a[20],front=-1,rear=-1;

int enqueue(int n)
{
        int temp=rear;
        if(rear==19)
              rear=0;
        else 
               rear++;
        if(rear==front)
        {
              rear=temp;
              return;
        }                     
        if(front==-1)
               front=0;
        a[rear]=n;
        return 0;      
}

int dequeue()
{
      int temp=front;
      if(front==19)
            front=0;
      else if(front==rear)
      {
                rear=-1;
                front=-1;
      }
      else
                   front++;                                                             
      return(a[temp]);
}

void print_queue()
{
        int i;
        printf("in queue \n");
        for(i=front;i<=rear;i++)
                   printf("--%d--",a[i]);
        return;
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

int bfs(int n)
{
        int i,j,k;
        struct list *temp;        
        for(i=0;i<n;i++)
        {
                 arr[i].color=0;
                 arr[i].d=99999;
                 arr[i].parent=NULL;
                 arr[i].state=0;
        }
        arr[0].d=0;
        arr[0].color=1;
        arr[0].state=RED;
        enqueue(0);
        printf("\nThe Breadth first traversal of graph is starting from node 1 :\n");
        while(front!=-1)
        {
                  j=dequeue();
                  temp=arr[j].next;
                  printf("..%d..",j+1);
                  while(temp!=NULL)
                  {
                           k=temp->data-1;        
                           if(arr[k].state==arr[j].state)
                           {
                                       printf("Not Bicolorable");
                                       return 0;
                           }                          
                           if(arr[k].color==0)
                           {
                                       arr[k].color=1;
                                       if(arr[j].state == RED)
                                                  arr[k].state=BLUE;
                                        else
                                                  arr[k].state=RED;         
                                       arr[k].d= arr[j].d +1;
                                       arr[k].parent=&arr[j];
                                       enqueue(k);
                                       //printf("\nnow push %d\n",k);
                           }
                           //print_queue();
                           temp=temp->next;
                  }
                  arr[j].color=2;
        }
        printf("\nBicolorable");
        return 0;
}
                                                            
int main()
{
       int i,j,n,ch;
       struct node *start=NULL;
       printf("enter the number of nodes\n");
       scanf("%d",&n);
       //arr=malloc(sizeof(struct node)*n);
       
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
       bfs(n);
       getchar();
       getchar();                           
       return 0;
}
