#include<stdio.h>

/* we will make cut only when it is compulsory, i.e. if on selecting the current item
    the other one will not get the equal number, */
    
struct count
{
       int total,jack,jill;
};

int spilt()
{
    int n,i,j,cut[1000],no_cut=0,part_no=0,a[1000];
    struct count b[501];
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
          scanf("%d",&a[i]);
          if(i<501)
            b[i].total=b[i].jack=b[i].jill =0;
    }
    
    for(i=0;i<n;i++)
    {
          b[a[i]].total++;
    }
    
    for(i=0;i<n;i++)
    {
            if(part_no % 2 ==0) //jack part is this
            {        
                     if(b[a[i]].jack < b[a[i]].total/2)
                           b[a[i]].jack++;
                     else
                     {
                           cut[no_cut++]=i;
                           part_no++;
                     }
            }
            else  // jill part 
            {
                    if( b[a[i]].jill< b[a[i]].total/2)
                        b[a[i]].jill++;
                    else
                    {
                           cut[no_cut++]=i;
                           part_no++;
                    }
            }
    }
    
    printf("%d\n",no_cut);
    for(i=0;i<no_cut;i++)
    {
          printf("%d ",cut[i]);
    }                   
                        
    return 0;
}
                                  
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
         spilt();
    }
    return 0;
}    
