#include<stdio.h>
#include<ctype.h>

int main()
{ 
  int c,age,i=0,IN_WORD=0;
  float ht;
  char name[100];
  FILE *fp;
  fp=fopen("name.txt","r");
  while( (c=fgetc(fp))!=EOF)
  {
              if(isalpha(c)|| IN_WORD==1 && !isdigit(c))
              {
                     IN_WORD=1;
                     name[i++]=(char)c;
              }                              
              if(isdigit(c) && IN_WORD==0)
              {
                            
  }
  getchar();
  return 0;
} 
