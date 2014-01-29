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

void select(char *a,int start,int end,int r)
{
     int static count;
          
     if(r==0)
     {
            int i; 
            for(i=start;i<end;i++)
                  a[i]='0'; 
            printf("%3d.  %s\n",++count,a);
            return;
     }             
     else if(start==end || end-start < r ) // to end the tree early, to reduce time complexity by reducing the search space                                  
            return;
     
     a[start]='0';
     select(a,start+1,end,r);
     a[start]='1';
     select(a,start+1,end,--r);
     return ;
}
       
int main()
{
    char a[100]={'\0'};  //must intialliaze so that %s will work for any lenght
    int n,r;
    printf("enter n & r to find nCr combinations\n");
    scanf("%d %d",&n,&r);
    select(a,0,n,r);
    getchar();
    getchar();
    return 0;
}
