/* Program implemnt a circular queue and is performs every opeation in O(1) time with full utilization of space*/
#include<cstdio>

using namespace std;
int a[10],r=-1,f=-1;

int push(int n)
{
     int temp=r;   // Important for full utilization of space
     if(r==9)
          r=0;
     else
         r++;
     if(r==f)
     {
             r=temp;
             printf("\nOverflow\n");
             return 0;
     }
     a[r]=n;
     if(f==-1)
             f=0;
     return 0;
}   
     
int pop()
{
       if(f==-1)
       {
                 printf("\nEmpty List\n");
                 return 0;
       }
       a[f]=0;
       if(f==r)
       {
                 f=-1;
                 r=-1;
       }
       else if(f==9)
            f=0;
       else
           f++;
       return 0;
}

int print_queue()
{
    int temp=r;
    for(int i=0;i<10;i++)
            printf("%d-",a[i]);
    return 0;
}                                            
int main()
{
       int c=0,num;
       while(c!=3)
       {
               printf("\n1.Insert\n2.Delete\n3.Quit\n");
               scanf("%d",&c);
               switch(c)
               {
                        case 1:  printf("\nEnter No.\n");
                                 scanf("%d",&num);
                                 push(num);
                                 print_queue();
                                 break;
                         case 2: print_queue();
                                 pop();
                                 printf("\n After Delete\n");
                                 print_queue();
                                 break;
                         case 3: return 0;
               }
       }
       return 0;
}
