/* program for a sorted doubly linked list */
#include<stdio.h>
#include<stdlib.h>

struct node
{
       int num;
       struct node *next;
       struct node *prev;
};

struct node * search(struct node **start,int n)
{
    struct node *temp=NULL;
    temp=*start;
    if((*start)==NULL || n < temp->num)          
             return (*start); 
    while(temp->next!=NULL)
    {                 
             if(temp->num<=n && temp->next->num>=n) // to check that is the number lies between two
                    return(temp);
              else
                   temp=temp->next;      
    }
    return temp;
}

int insert(struct node **start,int n)
{
       struct node *temp,*r;
       temp=search(start,n); // give the pointer pointing to the just previous where i have to insert yhe node; 
       if(temp==NULL || (temp==(*start) && temp->num> n))     // because temp will return start in this case: only one elemnt in 2, then add 3,
                                             // then search will return start pointer
       {
               r=(struct node *)malloc(sizeof(struct node));
               r->num=n;
               if((*start)!=NULL)       // to add a element in the starting and the list is not empty
                    (*start)->prev=r;
               r->next=(*start);
               r->prev=NULL;
               (*start)=r;
       }   
       else
       {
               r=(struct node *)malloc(sizeof(struct node));
               r->num=n;
               if(temp->next!=NULL)                // to add link, the element inserted in between
                        temp->next->prev=r;
               r->next=temp->next; 
               r->prev=temp;
               temp->next=r;
       }
       return 0;
}      

int print(struct node *start)
{
     struct node *temp;
     temp=start;
     if(start==NULL)               // importtant because for empyty list temp->next is not defined
     {
             printf("\nEMPTY LIST\n");
             return 0;
     }
     while(temp->next!=NULL)
     {
            printf("%d-->",temp->num);
            temp=temp->next;
     }
     printf("%d",temp->num);
     return 0;
}
            
int Delete(struct node **start,int n)
{
       struct node *temp,*r;
       int i=0;
       if(*start==NULL)
               return 0;
       temp=*start;       
       while(temp->next!=NULL)  // to search the node with num=n and then delete it.
       {     
               if(temp->num==n)
               {        
                      r=temp->next;
                      if(temp==(*start))         // to delete 2 from list of type 2->4->7->8....
                               *start=r;
                      else                            // to delete 5 from list of type 2->4->5->8->9........
                      {         
                              r->prev=temp->prev; 
                              temp->prev->next=r; // temp=r is not working
                      }
                      return 0;
               }
               if(temp->num >n)                 // just to improve time taken    
               {
                    printf("\nNot in the List\n");
                    return 0;  
               }                       
               temp=temp->next;
       }
       if(temp==(*start) && temp->num==n) // to delete the only element present in the list , eg. 2
               (*start)=NULL;
       else if(temp->num==n)           // to delete the last element of list; temp=NULL is not working.
               temp->prev->next=NULL;
       else                              // not in the list i.e n>max number of list
               printf("\nNot in the List\n");                
       return 0;
}
                
struct node* merge(struct node *first,struct node *second)  // alternative: use sorted insert fn, made above; just traverse 
{                                                         // list and call insert fn each time, gives merge list.
     struct node *p,*q,*start,*r;
     
     if(second==NULL)            
            return(first);          
     if(first==NULL)
            return(second);
            
     if(first->num > second->num)   //p will point to the path of the meging pointers and r points to the value by which the p
     {                               // is compared and then move ahead., finally p points to the answer
              p=second;
              r=first;
     }
     else
     {
               p=first;
               r=second;
     }  
     start=p;        
     while(p->next!=NULL && r->next!=NULL)
     {        
                                                                    
             if(p->num <= r->num && r->num < p->next->num)
             {
                       q=p->next;
                       p->next=r;
                       r->prev=p;
                       r=q;
             }
             p=p->next;
     }
     if(p->next==NULL || (p->next==NULL && r->next==NULL) )
     {
                  
              p->next=r;
              r->prev=p;
              //printf("\np_NULL p= %d,  r=%d\n",p->num,r->next->num);
              return (start);
     }
     else
              insert(&start,r->num);

     return start;
}                           
 
int main()
{
       struct node *start[2];  // important:  Since in the function inser etc. we chang the value of the pointer itself , so we need 
                             // a pointer to keep track of its change, so need **; wheresas in case of swap fn we need a int * 
       start[0]=start[1]=NULL;           // because we need to keep track of integer, so we need *.
       int c=0,num,n;
       while(c!=4)
       {
               printf("\n1.Insert\n2.Delete\n3.Merge\n4.Quit\n");
               scanf("%d",&c);
               switch(c)
               {
                        case 1:  printf("\nEnter No.and also List No.-(0/1)\n");
                                 scanf("%d %d",&num,&n);
                                 insert(&start[n],num);
                                 print(start[n]);
                                 break;
                         case 2: printf("\nenter list no.\n");
                                 scanf("%d",&n);
                                 print(start[n]);
                                 printf("\n enter which node to be deletetd\n");
                                 scanf("%d",&num);
                                 Delete(&start[n],num);
                                 print(start[n]);
                                 break;
                         case 3: print(start[0]);
                                 printf("\n");
                                 print(start[1]);
                                 printf("\n After Merging, list:-\n"); 
                                 print(merge(start[0],start[1]));
                                 break;
                         case 4: return 0;
               }
       }
       return 0;
}
                                      
              
