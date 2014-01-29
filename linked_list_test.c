#include<stdio.h>
#include<malloc.h>

typedef struct node{
       int num;
       struct node *next;
}list;

void insert (list ** start, int n)
{
    list * temp, *new_node;
    temp = *start;

    new_node = (list *) malloc(sizeof(list));
    new_node->next= NULL;
    new_node->num=n;

    if(!temp)
    {
        *start = new_node;
        return;
    }
    for(;temp->next!=NULL;temp = temp->next)
                ;
    temp->next = new_node;

    return;
}

void print(list *start)
{
        for(;start!=NULL;start = start->next)
        {
            printf("%d-> ",start->num);
        }
        return;
}

void Delete(list ** start,int num)
{
    list *temp;
    temp=*start;

    if(!temp)
        return;

    if(temp->num==num)
    {
        *start = temp->next;
        free(temp);
        return;
    }

    for(;temp->next!= NULL && temp->next->num !=num ;temp = temp->next)
                ;
    if(temp->next == NULL)
        return;
    else //(temp->next-> num == num)
    {
        temp->next = temp->next->next;
        free(temp->next);
    }
    return;
}

void reverse(list ** start)
{
    list *prev = NULL, *current, *next; //can replace current with *start
    current = *start;

    if(!current)
        return;
    while(current->next != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    current->next = prev;
    *start = current;
}

list* reverse_re(list ** start, list* current)
{
    list * temp;

    if(*start == NULL)
        return;
    if( current->next==NULL)
    {
        *start = current;
        return current;
    }
    temp = reverse_re(start,current->next);
    temp->next=current;
    current->next = NULL;
    return current;
}

void splitm(list *start, list **start1, list **start2)
{
    list *slow, *fast;
    *start1 = slow = start;

    if(start == NULL && start->next == NULL)
    {
        *start2 = NULL;
        return;
    }
    fast = slow->next;
    while(fast!=NULL)
    {
             fast = fast->next;
             if(fast!=NULL)
             {
                 slow = slow ->next;
                 fast = fast->next;
             }
    }
    *start2 = slow->next;
    printf("IN_spilt first: %d, second: %d",(*start1)->num,(*start2)->num);
    slow->next = NULL;
    return;
}

void merge(list **start, list *first, list * second)
{
      list *temp;

      if(!first)
      {
          *start = second;
          return;
      }
      else if(!second)
      {
          *start = first;
          return;
      }
      if(first->num <= second->num)
      {
            *start = temp=first;
            first= first->next;
      }
      else
      {
            *start = temp= second;
            second= second->next;
      }

      while(first!=NULL && second!=NULL)
      {
          if(first->num <= second->num)
          {
                temp->next=first;
                first=first->next;
          }
          else
          {
                temp->next=second;
                second=second->next;
          }
          temp = temp->next;
      }

      if(first == NULL)
      {
          temp->next = second;
      }
      else
      {
          temp->next=first;
      }

      return;
}

void mergesort(list ** start)
{
    list *start1=NULL, *start2=NULL;

    if((*start) == NULL || (*start)->next==NULL)
        return;

    splitm(*start,&start1,&start2);
    mergesort(&start1);
    mergesort(&start2);
    merge(start,start1,start2);

}

void reverse_2(list **start)
{
    list *next, *prev_g,*prev,*current;
    current = *start;

    while(current!=NULL && current->next!=NULL)
    {
          prev= current;
          current = current->next;
          next= current->next;

          current->next= prev;
          if(prev == *start)
          {
              *start = current;
          }
          else
          {
              prev_g->next = current;
          }
          prev_g=prev;
          current= next;
    }
    prev_g->next= current;
    return;
}

int main()
{
       int c=0,num,b;
       list * start = NULL;
       while(c!=11)
       {
               printf("\n1.Insert\n2.Delete\n3.Reverse\n4.F_12\n5.n_node\n6.swap\n7.ODD First\n8.MergeSort\n9.reverse_k\n10.delete_alternative\n11.Quit\n");
               scanf("%d",&c);
               switch(c)
               {
                        case 1:  printf("\nEnter No.\n");
                                 scanf("%d",&num);
                                 insert(&start,num);
                                 print(start);
                                 break;
                         case 2: print(start);
                                 printf("\n enter which node to be deletetd\n");
                                 scanf("%d",&num);
                                 Delete(&start,num);
                                 print(start);
                                 break;
                         case 3: print(start);
                                 //reverse(&start);
                                 reverse_re(&start,start);
                                 printf("\n");
                                 print(start);
                                 break;
                         case 4: print(start);
                                 //f_12(&start);
                                 printf("\n");
                                 print(start);
                                 break;
                         case 5: print(start);
                                 printf("\nEnter No.\n");
                                 scanf("%d",&num);
                                 //n_node(start,num);
                                 printf("\n");
                                 print(start);
                                 break;
                         case 6: print(start);
                                 printf("\nEnter first and second positionNo.\n");
                                 scanf("%d %d",&num,&b);
                                 //swap(&start,num,b);
                                 printf("\n");
                                 print(start);
                                 break;
                         case 7: print(start);
                                 //f_last(start);
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
                                 reverse_2(&start);
                                 printf("\n");
                                 print(start);
                                 break;
                        case 10: print(start);
                                 //delete_alt(start);
                                 printf("\n");
                                 print(start);
                                 break;
                        case 11: return 0;

               }
       }
       return 0;
}
