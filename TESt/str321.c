#include<stdio.h>

struct node
{
     unsigned int a:1;
     unsigned int n:4;
}ag;  

int f2(int n)
{
    if(!n)
        return 0;
    f2(n/10);    
    putchar(n%10+'0');
    return 0;
}

int f1(int *p)
{
    *p=200;
    return 0;
}
int main()
{
          char a[]="hello",b[]="malli",ch='A';
          char * const p=b;
          char s[100],c='A';
          //p=b;  
          p[0]='b';
          scanf("%s ",&s);
          c=getchar();
          printf("%d %s",c,s);
        //  printf("%s  %s   %d %d %d %d\n",a,p,sizeof(ag),sizeof(c),sizeof("A"),sizeof('A'));
        //  f2(101131);
          getchar();
          getchar();
          system("PAUSE");
          return 0;
}
