#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

typedef struct node
{
    int value;
    struct node *prev;
    struct node *next;
} doubly_list;

/* Insert at Last*/
int insert(doubly_list ** list, int number);
int print(doubly_list *list);
int swap2(doubly_list **list);
doubly_list* reverse(doubly_list ** list);
doubly_list* reverse_k(doubly_list **list, int k);
doubly_list* reverse_k_skip(doubly_list **list, int k);
#endif
