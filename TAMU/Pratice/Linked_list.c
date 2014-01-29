#include <stdio.h>

typedef struct node
{
    struct node * next;
    int value;
}singly_list;

int insert(singly_list ** start, int value)
{
    singly_list *temp, *new_node;

    new_node = (singly_list *)malloc(sizeof(singly_list));
    if(new_node == NULL)
        return -1;

    new_node->next = NULL;
    new_node->value = value;

    if(*start == NULL)
    {
        *start = new_node;
        return 0;
    }

    temp = *start;
    while(temp->next!= NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;  // Adding node at the last of the list
    return 0;

}

int print_list(singly_list *start)
{
    while(start != NULL)
    {
        printf("%d->", start->value);
        start = start->next;
    }
    printf("\n");
    return 0;
}

int delete_node(singly_list ** start, int value)
{
    singly_list *prev, *curr;
    prev = *start;
    if(prev == NULL)
    {
        printf("Nothing to delete - Empty list\n");
        return -1;
    }

    if(prev->value == value)
    {
        *start = prev->next;
        free(prev);
        return 0;
    }

    while(prev->next != NULL && prev->next->value != value)
    {
        prev = prev->next;
    }
    if(prev->next == NULL)
    {
        printf("Value Not found\n");
        return -1;
    }
    else
    {
        curr = prev->next;
        prev->next = curr->next;
        free(curr);
    }
    return 0;

}

int reverse(singly_list **start)
{
    singly_list *prev, *next, *curr;
    prev = NULL;
    curr = *start;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;

        curr = curr->next;
    }
    *start = prev;
    return 0;
}

int rec_reverse(singly_list **start)
{

}

int swapkthnode(singly_list **start, int k)
{
    singly_list *prev_left_k, *prev_right_k, *curr_right_k, *curr_left_k, *temp_last, *temp;
    int i=0,l=0;

    prev_right_k = temp_last = curr_right_k = prev_left_k = curr_left_k = *start;

    if(start == NULL)
    {
        printf("Empty list\n");
        return -1;
    }
    for(i=0;temp_last->next!=NULL && i<k-1;i++) //set prev_left_k to the previous node of the kth node from start
    {
        prev_left_k = temp_last;
        temp_last = temp_last->next;
        curr_left_k = temp_last;
    }
    if(i!=k-1)
    {
        printf("K is greter than the number of the nodes in the list\n");
        return -1;
    }

    while(temp_last->next!=NULL) // count the rest part of the list
    {
        temp_last = temp_last->next;
        l++;
    }

    printf("First - pl= %d, cl = %d, pr = %d, cr = %d", prev_left_k->value, curr_left_k->value, prev_right_k->value, curr_right_k->value);


    if(k>l) /* what if k > half of the length of the list, then prev_left_k is actually
                the previous pointer to the kth node on the rigt part of the list,
                so, now we will set the prev_right_k to the previous pointer of the kth node
                in the left part of the list*/
    {
        prev_right_k = prev_left_k;  /*reversing the names*/
        curr_left_k = curr_right_k;
        temp_last = prev_left_k = *start;

        for(i=0;temp_last->next!=NULL && i<l-1;i++)
        {
            prev_right_k = temp_last;
            temp_last = temp_last->next;
            curr_right_k = temp_last;
        }
    }
    else //normal case
    {
        temp_last = prev_left_k->next;
        while(temp_last->next!=NULL) // set the pointer to the previous of the last k node
        {
            prev_right_k = curr_right_k;
            curr_right_k = curr_right_k ->next;
            temp_last = temp_last->next;
        }
    }

    printf("pl= %d, cl = %d, pr = %d, cr = %d", prev_left_k->value, curr_left_k->value, prev_right_k->value, curr_right_k->value);
    /* Now, we have the set the pointers to the previous of both the nodes, just swap now*/

    if(curr_left_k != *start) //do not change the start pointer
    {
        temp = curr_left_k;

        prev_left_k->next = prev_right_k->next;
        curr_left_k->next = curr_right_k->next;
        curr_right_k->next = temp->next;
        prev_right_k->next = curr_left_k;
    }
    else
    {
        temp = *start;

        *start = prev_right_k->next;
        curr_left_k->next = curr_right_k->next;
        curr_right_k->next = temp->next;
        prev_right_k->next = curr_left_k;
    }




    return 0;
}

int main()
{
    singly_list *start = NULL;
    int num, option;
    printf("I will pratice daily\n");
    printf("1.Insert\n2.Delete\n3.Swap elements at kth distance\n4.Quit");
    scanf("%d", &option);
    while(option != 4)
    {

        switch(option)
        {
            case 1: printf("Enter the number\n");
                    scanf("%d",&num);
                    if( 0 == insert(&start, num))
                        print_list(start);
                    else
                        printf("Error while allocating memory\n");
                    break;

            case 2: printf("Enter the no. to be deleted\n");
                    scanf("%d",&num);
                    delete_node(&start, num);
                    print_list(start);
                    break;

            case 3: printf("Enter the no. k\n");
                    scanf("%d",&num);
                    swapkthnode(&start, num);
                    print_list(start);
                    break;

            case 4: break;
        }

        printf("1.Insert\n2.Delete\n3.Swap elements at kth distance\n4.Quit");
        scanf("%d", &option);
    }

    return 0;
}
