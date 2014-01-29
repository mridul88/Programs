#include<stdio.h>

/* this program gives us the maximum memory i can use to run this program
   it is 241.92 MB only :-( */
int main()
{
    int *b;
    long int c=0;
    while(1)
    {
            b=(int *)malloc(c*sizeof(int));
            if(b==NULL)
               break;
            printf("%d\r",c);
            c++;
    }
    printf("END");
    getchar();
    return 0;
}
                    
