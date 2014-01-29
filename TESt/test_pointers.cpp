#include<stdio.h>

int main()
{
      char a[]="3133";
      for(int i=0;i<3;i++)
      {
                      printf("%s",*++a);
      }
      getchar();
      getchar();
      return 0;
}
