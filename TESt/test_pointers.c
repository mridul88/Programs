#include<stdio.h>

int main()
{
      char *a="mridul";
      
      int i;
      for(i=0;i<3;i++)
      {
                      printf("%c",(*++a+3));
      }
      getchar();
      getchar();
      return 0;
}
