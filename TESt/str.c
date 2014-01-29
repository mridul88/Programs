#include<stdio.h>
#include<ctype.h>

int strlen(char *s)
{
    int lenght =0;
    while(*s++!='\0')
         lenght++;
    return lenght;
}
     
int strcmp(char *s,char *t)
{
     for(;*s==*t;s++,t++)
         if(*s=='\0')
            return 0; 
     return *s - *t;     
}

void strcatt(char *s,const char *q) 
{
     while(*s++)   //while(*s)
         ;      //    s++;
     s--;          // not required;
     while(*s++ = *q++)
     {
          // *s++ = *q++;
        //   printf("%c",*s);
     }
 //    *s='\0';
     return;
}
      
int atoii(char *s)
{
    int n=0,sign=1;
    while(*s == ' ' || *s== '\t')
           s++; 
    sign=(*s=='-'?-1:1);
    for(;isdigit(*s);s++)
            n= 10*n + (*s -'0');
    return( n*sign);
}                         
                                      
int main()
{
     char s[100]="mridul malpani ",*q,*p="   -5623";
     const char a="fada";
     const char * b="asas";
     int d;     
     a=b;
     q="wants to fuck heena";
     strcatt(s,q);
     printf("--%s",s); 
     printf("\n%s %d %d %d",q,strlen(q),strcmp(s,q),atoi(p));
     getchar();
     return 0;
}
