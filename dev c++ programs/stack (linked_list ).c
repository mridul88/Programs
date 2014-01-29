#include<stdio.h>
#include<stdlib.h>

struct node
{
       int num;
       struct node *link;
}*start=NULL;

int push(int n)
{
       struct node *temp,*r;
       temp=start;
       if(start==NULL)
       {
               temp=(struct node *)malloc(sizeof(struct node));
               temp->num=n;
               temp->link=NULL;
               start=temp;
        }
       else
       {          
               while(temp->link!=NULL)
               {
                       temp=temp->link;
               }
               r=(struct node *)malloc(sizeof(struct node));
               r->num=n;
               r->link=NULL; 
               temp->link=r; 
       }
       return 0;
}      

int print_stack()
{
     struct node *temp;
     temp=start;
     while(temp->link!=NULL)
     {
            printf("\n%d",temp->num);
            temp=temp->link;
     }
     printf("%d",temp->num);
     return 0;
}
            
int pop()
{
       struct node * temp,*p=NULL;
       if(start==NULL)
               return 0;
       temp=start;
       while(temp->link!=NULL)  // to search the node with num=n
       {     
               p=temp;  
               temp=temp->link;
       }
       if(temp==start)               // delete the node
             start=NULL;                   
       else
               p->link=temp->link;
               
       return 0;
}
                 
int main()
{
       int c=0,num;
       while(c!=3)
       {
               printf("\n1.Insert\n2.Delete\n3.Quit");
               scanf("%d",&c);
               switch(c)
               {
                        case 1:  printf("\nEnter No.\n");
                                 scanf("%d",&num);
                                 push(num);
                                 print_stack();
                                 break;
                         case 2: print_stack();
                                 pop();
                                 print_stack();
                                 break;
                         case 3: return 0;
               }
       }
       return 0;
}
                                      
              

