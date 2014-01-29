#include "linked_list.h"
#include <cstdio>

using namespace std;

/* Insert at Last*/
int insert(doubly_list ** list, int number)
{
    doubly_list *new_node = NULL, *temp;
    new_node = new doubly_list;
    new_node->value = number;
    new_node->prev = NULL;
    new_node->next = NULL;

    temp = *list;
    if(temp == NULL)
    {
        *list = new_node;
        return 0;
    }
    
    while(temp->next!=NULL)
    {
         temp = temp->next;
    }

    temp->next = new_node;
    new_node->prev = temp;
    return 0;
}

int print(doubly_list *list)
{
    if(list == NULL)
    {
        printf(" EMPTY LIST\n");
        return -1;
    }
    while(list!=NULL)
    {
        printf("%d->", list->value);
        list = list->next;
    }
    return 0;
}

vector<int> list_to_vector(doubly_list *list)
{
    vetcor<int>vec = vector.;
    if(list == NULL)
    {
        return vec;
    }


int swap2(doubly_list **list)
{
    doubly_list *prev, *next, *temp, *prev_g;
    temp = *list;
    prev_g = *list;
    while(temp != NULL && temp->next != NULL)
    {
        next = temp->next->next;
        prev = temp;
        temp = temp->next;
        prev_g->next = temp;

        if(prev == *list)
        {
            *list = (*list)->next;
        }

        temp->prev = prev->prev;
        temp->next = prev;
        prev->next= next;
        prev->prev = temp;
        prev_g = prev;
        temp = next;
    }
    return 0;
}

doubly_list* reverse(doubly_list ** list)
{
    doubly_list *next, *prev, *temp;
    temp = *list;
    prev = NULL;

    while(temp!=NULL)
    {
        next = temp->next;

        temp->prev = next;
        temp->next = prev;

        prev = temp;
        temp = next;
    }
    *list = prev;

    return (*list);
}

doubly_list* reverse_k(doubly_list **list, int k)
{
    int i;
    bool run_once = true;
    doubly_list *first, *prev, *next, *temp, *prev_g, *next_g;
    first = prev_g = temp = *list;
    while(temp!=NULL)
    {
        first = temp;
        /* To check whether there are k nodes or not*/
        for(i=0; temp!=NULL && i< k; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        /* If not - then leave it as it is, but connect it to the previous nodes*/
        if(i < k)
        {
            if(prev_g!= *list)
            {
                prev_g->next = first;
                first->prev = prev_g;
            }
            return *list;
        }
        /* Found the k next nodes, delink them and reverse these k nodes normally, use reverse function*/
        next_g = temp;
        prev->next = NULL;
        first->prev = NULL;

        for(temp = first, prev = NULL; temp!=NULL;)
        {
            next = temp->next;
            temp->prev = next;
            temp->next = prev;

            prev = temp;
            temp = next;
        }
        /* Connect the reversed string with original list*/
        if(run_once)  /*Take Care - when k ==1 case*/
        {
            *list = prev;
            prev->prev = NULL;
            run_once = false;
        }
        else
        {
            prev_g->next = prev;
            prev->prev = prev_g;
        }
        prev_g = first;
        temp = next_g;
    }

    return *list;
}

doubly_list* reverse_k_skip(doubly_list **list, int k)
{
    int i;
    bool run_once = true;
    doubly_list *first, *prev, *next, *temp, *prev_g, *next_g;
    first = prev_g = temp = *list;
    while(temp!=NULL)
    {
        first = temp;
        /* To check whether there are k nodes or not*/
        for(i=0; temp!=NULL && i< k; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        /* If not - then leave it as it is, but connect it to the previous nodes*/
        if(i < k)
        {
            if(prev_g!= *list)
            {
                prev_g->next = first;
                first->prev = prev_g;
            }
            return *list;
        }
        /* Found the k next nodes, delink them and reverse these k nodes normally, use reverse function*/
        next_g = temp;
        prev->next = NULL;
        first->prev = NULL;

        for(temp = first, prev = NULL; temp!=NULL;)
        {
            next = temp->next;
            temp->prev = next;
            temp->next = prev;

            prev = temp;
            temp = next;
        }
        /* Connect the reversed string with original list*/
        if(run_once)  /*Take Care - when k ==1 case*/
        {
            *list = prev;
            prev->prev = NULL;
            run_once = false;
        }
        else
        {
            prev_g->next = prev;
            prev->prev = prev_g;
        }
        prev_g = first;
        temp = next_g;
    }

    return *list;
}
