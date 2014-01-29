#include<stdio.h>
#include<math.h>

struct ptr
{
       double a;
       char b;
       int *p;
       union xy
       { 
              int as;
              char bx;
       }sa;
} abc; 

int main()
{
    int x[10]={7,8};
    
    abc.p= &x;
    printf("%d %d %d %d %d\n",x[0],x[1],x[7],x[8],x[9]);
   
//    f();
   // x=(2>0)?printf("zero"):printf("four");
   // printf("%d",x);
    getchar();
    return 0;
}
