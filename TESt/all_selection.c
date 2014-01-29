#include<stdio.h>

/* Let there are n items, you have to print all the combinations to select any 
    number of item from it. Let you have 2 iteems then:
           00
           01
           10
           11
    represent all the possible combinations. 
    So, you have to print all the number between 0 to 2^n.
    if 2^n > max_integer then this backtrack method will work.
    
    It is tree, left then 0, right then 1
    thus all the leaf nodes are the required binary numbers */ 

void select(char *a,int start,int end)
{
     int static i;
     if(start==end)
     {       
            printf("%3d.  %s\n",++i,a);
            return;
     }
     a[start]='0';
     select(a,start+1,end);
     a[start]='1';
     select(a,start+1,end);
     return ;
}
       
int main()
{
    char a[100]={'\0'};  //must intialliaze so that %s will work for any lenght
    int n;
    scanf("%d",&n);
    select(a,0,n);
    getchar();
    getchar();
    return 0;
}
