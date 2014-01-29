#include<stdio.h>

#define MAX 20

int main()
{
    int c,i,count;
    char word[100];
    FILE *fin,*fout;
    
    fin=fopen("input.txt","r");
    fout=fopen("output.txt","w");
    
    while( (c=getc(fin))!=EOF)
    {
            count++;
            if(c=='\n' || c== '\t'  || c== ' ')
            {
                       if(count>MAX)
                       
