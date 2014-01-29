#include<stdio.h>

/* generate all the possible permutations of fixed length "m" of these
numbers WITH repetitions (a total of n^m possibilities). For example:

given the set {1, 2} would output: 111,112,121,122,211,212,221,222 if
we fix m=3.

What I could do so far is an iterative algorithm which could be used
only if we know before runnin the program "m" and "n" which is not
often the case :)

3 is the love character
*/ 

void select(char *a,int start,int n,int l)
{
     int static count;
     int i;     
     if(start==l)
     { 
            printf("%3d.  %s\n",++count,a);
            return;
     }             
     for(i=0;i<n;i++)
     {
            a[start]=(char)(i+'0'+1);
            select(a,start+1,n,l);
     }
     return ;
}
       
int main()
{
    char a[100]={'\0'};  //must intialliaze so that %s will work for any lenght
    int n,l;
    printf("enter n & l \n");
    scanf("%d %d",&n,&l);
    select(a,0,n,l);
    printf("%c",(char)3);
    getchar();
    getchar();
    return 0;
}
