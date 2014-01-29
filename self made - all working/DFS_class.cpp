#include<cstdlib>

using namespace std;

class stack
{
      static int a[20],top=-1;
      
      int push(int n)
      {
            a[++top]=n;
      }
      
      int pop()
      {
          return(a[top--]);
      }
};       
class list
{
       int data;
       class list *next;
}*last[20];
       
class node
{
       int data,color,d;
       class list *next;
       class node *parent;
} arr[20];
                                                                                                         

int insert(class list **start,class list **last,int n)
{
       class list *temp;
       temp= new list;
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
        }
        arr[0].d=0;
        arr[0].color=1;
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
                           //printf("asdfghjkl\n");        
                           if(arr[k].color==0)
                           {
                                       arr[k].color=1;
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
