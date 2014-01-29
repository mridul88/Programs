/* program to implement a stachk using singly linked list and PUSH & POP take O(1) time to run*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
       int num;
       struct node *link;
}*start=NULL;
struct node *last=NULL;

int push(int n)
{
       struct node *temp;
       temp=malloc(sizeof(struct node));
       temp->num=n;
       if(start==NULL)
       {         
               temp->link=NULL;
               start=temp;
               last=start;                   // here start=temp works , because no node is alrady presnt ; so no linling
        }
       else
       {      
               temp->link=last;
               last=temp;                 // here link is from new node to old noddes, that's the trick of push(1). 
       }
       return 0;
}      

int print_stack()
{
     struct node *temp;
     temp=last;
     while(temp!=NULL)                   // print the list from last to first in reverse order
     {
            printf("\n   %d",temp->num);
            temp=temp->link;
     }
     return 0;
}
            
int pop()
{
       struct node *temp=last;   
       if(last==NULL)            
                return 0;
       if(last==start)               // not the start =temp->link ; it will give run -time error
             last=NULL;              
       else                              // not temp=temp->link; it will not delete the last node;
             last=last->link;               
       return 0;
}
                 
int main()
{
       int c=0,num;
       while(c!=3)
       {
               printf("\n1.Insert\n2.Delete\n3.Quit\n");
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
                                 printf("\n After Delete\n");
                                 print_stack();
                                 break;
                         case 3: return 0;
               }
       }
       return 0;
}
                                      
              

