#include "linked_list.h"
#include <cstdio>

int main()
{
    int user_choice =1, number, k;
    doubly_list *list = NULL;
    printf("This is an assembled program to experiment with the linked lists\n");
    
    while(user_choice !=5)
    {
        printf("\nSelect :- \n1.) Insert\n2.) Swap Alternate elements\n3.) Reverse \n4.)Reverse k\n5.) Quit\n");
        scanf("%d", &user_choice);
        switch(user_choice)
        {
            case 1: print(list);
                    printf("Enter a Number\n");
                    scanf("%d", &number);
                    insert(&list, number);
                    print(list);
                    break;

            case 2: swap2(&list);
                    print(list);
                    break;
            
            case 3: list = reverse(&list);
                    print(list);
                    break;
           
            case 4: printf("Enter the value of k\n");
                    scanf("%d", &k);
                    list = reverse_k(&list, k);
                    print(list);
                    break;

            case 5: break;
        }
    }
    return 0;
}
