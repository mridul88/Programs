#include<stdio.h>
// 1<<31 - smallest no,  ~(1<<31)  biggets
int main()
{
     unsigned int i=-1;
     int j=-(i/2);
     printf("%d  %d  mu=%d",1<<31, ~(1<<31),j);
     
     getchar();
     getchar();
     return 0;
}
