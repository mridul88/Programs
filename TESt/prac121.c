#include <stdio.h>
#include <string.h>

char * fu(char *ptr)
{
     ptr+=3;
     return ptr;
}
     
int main()
{
    char *x,*y;
    
    x="hello";
    y=fu(x);
    printf("%s",y);
    getchar();
    return 0; 
  
}
