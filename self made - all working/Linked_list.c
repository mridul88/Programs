#include<stdio.h>

struct node
{
       int num;
       struct node *link;
}*start=NULL;

int insert(int n)
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

int print(struct node *start)
{
     struct node *temp;
     temp=start;
     if(start==NULL)               // importtant because for empyty list temp->link is not defined
     {
             printf("\nEMPTY LIST\n");
             return 0;
     }
     while(temp->link!=NULL)
     {
            printf("%d-->",temp->num);
            temp=temp->link;
     }
     printf("%d",temp->num);
     return 0;
}
            
int Delete(struct node **start,int n)
{
       struct node * temp,*p;
       int i=0;
       if(*start==NULL)
               return 0;
       temp=*start;
       while(temp->num!=n)  // to search the node with num=n
       {     
               p=temp;  
               temp=temp->link;
       }
       if(temp==*start)                 // delete the first node and start list from second node;
               *start=temp->link;
       else                           // delete any other node    
               p->link=temp->link;
               
       return 0;
}
                 
void reverse(struct node **start)
{
     struct node *r=*start,*prev=NULL;
     
     if(*start==NULL)
            return;
     while((*start)->link!=NULL)
     {
               r=(*start)->link;
               (*start)->link=prev;
               prev=(*start);
               (*start)=r;
     }
     (*start)->link=prev;                      
      return ;
}

struct node * reverse_re(struct node *current,struct node **start)
{
        struct node * temp;
        if( (current)->link==NULL)
        {
               *start=current;
               return current;
        }
        temp=reverse_re((current)->link,start);           
        temp->link=current;
        current->link=NULL; // IMportant, otherwise list be circular 
        return (current);
}

int f_12(struct node **start)
{
       struct node *first,*fourth,*temp;
       int i=0;
       first=*start;
       fourth=*start;

       while(fourth!=NULL)
       {
                 for(i=0;i<3 &&(fourth)!=NULL;i++)
                 {
                      temp=fourth;       
                      fourth=(fourth)->link;
                 }
                 if(i!=3)
                 {
                         printf("Error\n");
                         return 0;
                 }
                 temp->link =(fourth)->link;
                 if(*start==first)
                 {
                       (fourth)->link=*start;
                       *start=fourth;
                 }
                 else
                 {
                      (fourth)->link=first->link;
                       first->link=fourth;
                 }
                 first=temp;
                 fourth=temp->link;
       }
       return 0;
}                                    

int n_node(struct node *start,int n)
{
     struct node *fast,*slow;
     int num=0;
     fast=slow=start;
     while(num<n && fast!=NULL )
     {
          fast=fast->link;
          num++;
     }
     if(num!=n || n==0)
     {
               printf("no. of elements is less than n\n");
               return 0;
     }
     while(fast!=NULL)
     {
             slow=slow->link;
             fast=fast->link;
     }    
     printf("Ans: %d\n",slow->num);                        
     return 0;
}

int swap(struct node **start,int f,int s)
{
     struct node *first,*second,*temp,*temp2;
     int i;
     first=second=*start;
     if(f<0 || s<0)
     {
            printf("Error\n");
            return 0;
     }
     if(f==s)
            return 0;
     if(f>s)
     {
            int temp=s;
            s=f;
            f=temp;
     }
     for(i=0;i<f-1 && first!=NULL;i++)
     {
            first=first->link;
     }
     if(i!=f-1 && f!=0)
     {
               printf("no. of elements is less than n\n");
               return 0;
     }
     for(i=0;i<s-1 && second!=NULL;i++)
     {
            second=second->link;
     }
     if(i!=s-1)
     {
               printf("no. of elements is less than n\n");
               return 0;
     }
     if(f!=0)
     {
             temp=first->link;
             first->link=second->link;
     }
     else // to swap the first element, we have to change the start pointer
     {
             temp=*start;
             *start=second->link;
     }
     if(temp!=second) // nodes are not adjacent
     {
            temp2=temp->link;
            temp->link=second->link->link;
            second->link->link=temp2;
            second->link=temp;
     }
     else  // for adjacent nodes
     {
            temp->link=second->link->link;
            if(f!=0)
                    first->link->link=temp;
            else   // first element 
                    (*start)->link=temp;
     }      
     return 0;
}

int f_last(struct node *start)
{
    struct node *second,*temp,*start2;
    int i=0;
    if(start==NULL)
          return 0;
    if(!(second=start->link))
         return 0;
    temp=start2=second;
    for(i=0;temp!=NULL;i++)
    {
          temp=temp->link;
          if(i%2==0 && temp!=NULL)
          {
                start->link=temp;
                start=temp;
          }
          else
          {
                start2->link=temp;
                start2=temp;
          }
    }
    start->link=second;
    return 0;
}         

int mergesort(struct node **start)
{
       struct node *start1,*start2;
       if(*start==NULL || (*start)->link==NULL)
             return 0;
                    
       spilt(*start,&start1,&start2);
      // printf("dadad  1: %d, 2: %d",start1->num,start2->num);
       mergesort(&start1);
       mergesort(&start2);
       merge(start,start1,start2);
       return 0;
}      

int merge(struct node **start,struct node *start1,struct node *start2)
{
      struct node *n_start;
      if(start1==NULL)
      {
              *start=start2;
              return 0;
      }
      if(start2==NULL)
      {
              *start=start1;
              return 0;
      }          
      if(start1->num <= start2->num)
      {
               *start=n_start=start1;
               start1=start1->link;
      }
      else
      {
               *start=n_start=start2;
               start2=start2->link;
      }
      while(start2!=NULL && start1!=NULL)
      {
             if(start1->num <= start2->num)
             {
               n_start->link=start1;
               n_start=n_start->link;
               start1=start1->link;
             }
             else
             {
               n_start->link=start2;
               n_start=n_start->link;
               start2=start2->link;
             }
      }   
      if(start1==NULL)
      {
              n_start->link=start2;
      }
      else
      {
              n_start->link=start1;
      } 
     // print(*start);
      return 0;
}        
                                             
int spilt(struct node *start, struct node **start1, struct node **start2)
{      
       struct node *slow,*fast;
       
       *start1=start;
       if(start==NULL || start->link==NULL)
       {
           *start2=NULL;           
           return 0;
       }
       slow=start;
       fast=start->link;   
       while(fast!=NULL)
       {
             fast=fast->link;
             if(fast!=NULL)
             {          
                        slow=slow->link;
                        fast=fast->link;
             }
       }    
       *start2=slow->link;
     //  printf("IN_spilt first: %d, second: %d",(*start1)->num,(*start2)->num);
       slow->link=NULL;
       return 0;
}   

int reverse_k(struct node **start,int k)
{
       struct node *next,*prev,*last,*prev_g,*temp;
       int i;
       next=*start;
       prev_g=NULL;
       
       while(next!=NULL)
       {
                  prev=NULL;
                  for(i=0;next!=NULL && i<k-1;i++)
                  {
                           temp=next->link;
                           next->link=prev;
                           prev=next;
                           if(i==0)
                                 last=prev;
                           next=temp;
                  }
                  
                  if(last==*start)
                       *start=next;
                   
                  if(next!=NULL)
                  {
                        temp=next->link;
                        next->link=prev;
                        prev=next;
                        next=temp;
                  }
                  
                  if(prev_g!=NULL)
                          prev_g->link=prev;
                          
                  prev_g=last;
       } 
       return 0;
}
                                                                                                       
int  delete_alt(struct node *start)
{
     struct node *temp;
     while(start)
     {
            temp=start->link;
            if(temp)
            {
                   start->link=temp->link;
                   free(temp);
            }
            start=start->link;
     }
     return 0;
}

                                               
int main()
{
       int c=0,num,b;
       while(c!=11)
       {
               printf("\n1.Insert\n2.Delete\n3.Reverse\n4.F_12\n5.n_node\n6.swap\n7.ODD First\n8.MergeSort\n9.reverse_k\n10.delete_alternative\n11.Quit\n");
               scanf("%d",&c);
               switch(c)
               {
                        case 1:  printf("\nEnter No.\n");
                                 scanf("%d",&num);
                                 insert(num);
                                 print(start);
                                 break;
                         case 2: print(start);
                                 printf("\n enter which node to be deletetd\n");
                                 scanf("%d",&num);
                                 Delete(&start,num);
                                 print(start);
                                 break;
                         case 3: print(start);
                                 reverse_re(start,&start);
                                 printf("\n");
                                 print(start);
                                 break; 
                         case 4: print(start);
                                 f_12(&start);
                                 printf("\n");
                                 print(start);
                                 break; 
                         case 5: print(start);
                                 printf("\nEnter No.\n");
                                 scanf("%d",&num);
                                 n_node(start,num);
                                 printf("\n");
                                 print(start);
                                 break; 
                         case 6: print(start);
                                 printf("\nEnter first and second positionNo.\n");
                                 scanf("%d %d",&num,&b);
                                 swap(&start,num,b);
                                 printf("\n");
                                 print(start);
                                 break; 
                         case 7: print(start);
                                 f_last(start);
                                 printf("\n");
                                 print(start);
                                 break; 
                         case 8: print(start);
                                 mergesort(&start);
                                 printf("\n");
                                 print(start);
                                 break; 
                         case 9: print(start);
                                 printf("\nEnter No.\n");
                                 scanf("%d",&num);
                                 reverse_k(&start,num);
                                 printf("\n");
                                 print(start);
                                 break;
                        case 10: print(start);
                                 delete_alt(start);
                                 printf("\n");
                                 print(start);
                                 break; 
                        case 11: return 0;
                         
               }
       }
       return 0;
}
                                      
              
