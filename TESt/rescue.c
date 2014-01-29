//-----------codecef easy problem rescue.c----------------//
#include<stdio.h>

int get(int c, int i)
{
    
      int x;
      x= c - (c-1)/i;
      while( (x+ (x-1)/i +1)<=c)
            x++;
      return(x-1);
}      

int main()
{
     int t,i,adult,diff,children,women,men,no_women=0,no_children=0,no_men=0,capacity,pw,pc;
     scanf("%d",&t);
     while(t--)
     {
               no_women=0;no_children=0;no_men=0;     
               scanf("%d%d%d%d",&capacity,&men,&women,&children);   
               
               pw=2*men;
               if(pw>women)
                   pw=women;
               pc= 4*(men+pw);
               if(pc>children)
                   pc=children;
                        
               diff=(pc + (pc-1)/4 +1)- capacity;
               if(diff<=0)
               {
                         no_children=pc;
               }
               else
                       no_children=get(capacity,4);
               
               adult=capacity-no_children;
               //printf("nc=%d pc=%d adult=%d\n",no_children,pc,adult);
               diff=(pw + (pw-1)/2 +1)- adult;
               if(diff<=0)
                        no_women=pw;
               else
                        no_women=get(adult,2);
               
               diff= adult-no_women;
               if(diff>men)
                         no_men=men;
               else
                         no_men=diff;
           printf("%d %d %d\n",no_men,no_women,no_children);
     }
     getchar();
     getchar();
     return 0;
}             
