#include<cstdio>

using namespace std;

typedef struct linked_list
{
    int data;
    struct linked_list* next;
    struct linked_list* random;
}list;

int insert(list **start, int data)
{
    list *new_node,*temp;
    new_node = new(list);
    new_node->data=data;
    new_node->next=NULL;
    new_node->random=NULL;

    if(*start==NULL)
    {
        *start=new_node;
        return 0;
    }
    temp = *start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;

    return 0;
}

int print(list *start)
{
    while(start!=NULL)
    {
        printf("___%d",start->data);
        if(start->random==NULL)
            printf("+ 0");
        else
            printf("+ %d",start->random->data);
        start=start->next;
    }
    return 0;
}

list* search(list* start,int data)
{
    while(start!=NULL)
    {
        if(start->data==data)
            break;
        else
            start=start->next;
    }
    if(start==NULL)
        printf("ERROR: NO SUCH NODE EXISTS\n");
    return start;
}

int set_random(list* start,int data1, int data2)
{
    list *node1,*node2;

    node1=search(start,data1);
    node2=search(start,data2);

    if(node1!=NULL && node2!=NULL)
    {
        node1->random=node2;
    }
    return 0;
}

int create_clone(list* original, list **clone)
{
    list * temp,*next_node,*new_node,*temp2;
    temp=original;

    while(temp!=NULL)  //insert the copy of node
    {
        next_node=temp->next;

        new_node=new(list);
        new_node->data=temp->data;
        new_node->random=NULL;
        new_node->next=next_node;

        temp->next=new_node;
        temp=next_node;
    }

    temp=original;
    while(temp!=NULL)  //set random pointer of clone
    {
        if(temp->random!=NULL)
            temp->next->random = temp->random->next;
        else
            temp->next->random=NULL;

        temp=temp->next->next;
    }

    // to separate the two lists
    temp=original;
    if(temp!=NULL)
    {
        temp2=temp->next;
        *clone=temp2;
        temp->next=temp2->next;
        temp=temp->next;
    }

    while(temp!=NULL)
    {
        temp2->next=temp->next;
        temp2=temp2->next;
        temp->next=temp2->next;
        temp=temp->next;
    }

    temp2->next=NULL;
    return 0;
}

int main()
{
    int c=0,num,node1,node2,b;
    list *head1,*head2;
    head1=head2=NULL;
    printf("\n1.Insert\n2.set_random_pointer\n3.create_clone\n4.Quit\nchoose an option");
    scanf("%d",&c);
    while(c!=4)
    {
        switch(c)
        {
                case 1: printf("\nEnter No.\n");
                        scanf("%d",&num);
                        insert(&head1,num);
                        print(head1);
                        break;
                case 2: print(head1);
                        printf("\n set the randdom pointer of :\n");
                        scanf("%d",&node1);
                        printf("to:");
                        scanf("%d",&node2);
                        set_random(head1,node1,node2);
                        print(head1);
                        break;
               case 3:  create_clone(head1,&head2);
                        printf("the original is:");
                        print(head1);
                        printf("\nthe clone is:");
                        print(head2);
                        break;
               case  4: return 0;

        }
        printf("\n1.Insert\n2.set_random_pointer\n3.create_clone\n4.Quit\nchoose an option");
        scanf("%d",&c);
    }
    return 0;
}
