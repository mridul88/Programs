/* program to implement finding the largest set such that weight is increasing and iq is decreasing
    11.6.1  - dynamic programmin*/

#include<stdio.h>

struct pair
{
       int weight,iq;
}arr[1000]={0};

int swap(int i,int j)
{
      int w_temp,iq_temp;
      
      w_temp=arr[i].weight;
      iq_temp=arr[i].iq;
      
      arr[i].iq=arr[j].iq;
      arr[i].weight=arr[j].weight;
      
      arr[j].iq=iq_temp;
      arr[j].weight=w_temp;
      
      return 0;
}
int sort(int n)
{
       int i,j;
       for(i=0;i<n;i++)
       {
                 for(j=i+1;j<n;j++)
                 {
                           if(arr[i].weight>arr[j].weight  || (arr[i].weight==arr[j].weight && arr[i].iq>arr[j].iq) )
                                      swap(i,j);
                 }
       }
       return 0;
}
          
int largest_set(int size)
{
         int temp,i,max=0,col=0,last,col_size=0,a[size][size],len[size],var;
         for(i=0;i<size;i++)
                len[i]=0;
         len[0]=0;                
         a[col][len[col]]=0;
         for(last=1;last<size;last++)
         {          
                temp=max; 
                printf("\n--------temp :%d\n",temp);   
                for(col=0;col<=col_size;col++)
                {                                 
                         if(arr[a[col][len[col]]].iq > arr[last].iq && len[col]==temp)
                         {
                                 len[col]++;
                                 a[col][len[col]]=last;
                                 max=len[col];
                                 printf("max=%d\n",max);
                         }                        
                }
                var=col_size;
                printf("var: %d\n",var);
                for(col=0;col<=var && temp==max;col++)
                {
                          if(len[col]==max && ( (len[col]>0  && arr[a[col][len[col]-1]].iq > arr[last].iq ) || len[col]==0) )
                          {
                                    col_size++;
                                    for(i=0;i<len[col];i++)
                                          a[col_size][i]=a[col][i];
                                    a[col_size][len[col]]=last;
                                    len[col_size]=len[col];  
                                    printf(":asdfghj\n");                  
                          }  
                           
                }             
         }               
         printf("\n|||||||||\n");
         for(col=0;col<=col_size;col++)
         {
                 if(len[col]==max)
                 {
                          for(i=0;i<=max;i++)
                                 printf("%d  %d\n",arr[a[col][i]].weight,arr[a[col][i]].iq);
                 }
                 printf("\n");
         }                                                                           
         return 0;
}       
                                                                                                                
int main()
{
       int w,iq,n=0,i;
       printf("Enter the\nweight   iq\n");
       scanf("%d%d",&w,&iq);
       while(w!=0)
       {
                   arr[n].weight=w;
                   arr[n].iq=iq;
                   n++;
                   scanf("%d%d",&w,&iq);
       }
       sort(n);   
       for(i=0;i<n;i++)
                        printf("%d   %d\n",arr[i].weight,arr[i].iq);
       largest_set(n);
       getchar();
       getchar();
       return 0;
}                    
