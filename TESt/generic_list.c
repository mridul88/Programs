#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct list
{
         void *data;
         struct list *next;
}
List; 
List *list1, *list2, *list3, *list4; 

int main(void)
{ 
    char c[] = { 'a', 'b', 'c', 'd' };
    int i[] = { 1, 2, 3, 4 }; 
    char s[10]="malpani";
    char *str[] = { "hello1", "hello2", "hello3", "hello4" };
    
    void *data;
    data=malloc(sizeof(int));
    memmove(data,str[2],7);
   // *((char *)data +2)='n';
    printf("%s",(char *)data); 
    
    
    
      
    /*list1 = list2 = list3 = list4 = NULL; 
    insert(&list1, &c[0], sizeof(char)); 
    insert(&list1, &c[1], sizeof(char));
     insert(&list1, &c[2], sizeof(char));
      insert(&list1, &c[3], sizeof(char));
       insert(&list2, &i[0], sizeof(int));
        insert(&list2, &i[1], sizeof(int)); 
        insert(&list2, &i[2], sizeof(int));
         insert(&list2, &i[3], sizeof(int));
         insert(&list3, str[0], strlen(str[0])+1);
          insert(&list3, str[1], strlen(str[0])+1); 
          insert(&list3, str[2], strlen(str[0])+1); 
          insert(&list3, str[3], strlen(str[0])+1); 
          
           printf("Printing characters:"); 
           print(list1, printchar); 
           printf(" : done\n\n"); 
           printf("Printing integers:"); 
           print(list2, printint); 
           printf(" : done\n\n");
            printf("Printing strings:");
             print(list3, printstr); 
             printf(" : done\n\n"); 
             printf("Printing composite:");
              print(list4, printcomp); */
              
          getchar();
          return 0;
}
             
