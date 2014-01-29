#include<stdio.h>
#include<string.h>

int reverse(char s[], char r[], int start, int end)
{
    char c;
    static int i;
            
    if(start==end)
    {
              r[i]=s[start];
    }
    else
    {
            c=s[start];
            reverse(s,r,start+1,end);
            r[++i]=c; 
           // printf("\n i=%d start=%d end=%d c=%c  r=%s",i,start,end,c,r); 
    }
    
    if(i==strlen(s)-1)
             r[++i]='\0';  
    return;
   
}           

int main()
{
    char s[100]="boobs and katrina",r[100];
    reverse(s,r,0,strlen(s)-1);
    //r[strlen(s)]='\0';
   // strcat(r,"\0");
    printf("\n%s",r);
    getchar();
    return 0;
}
