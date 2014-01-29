#include<stdio.h>
#include<string.h>

int beads(void)
{
          char b[10000],a[20000];
          int i,j=1,min,len,flag=0,temp1,temp2;
          scanf("%s",a);
          
          strcpy(b,a);
          strcat(a,b);
          a[strlen(a)-1]='\0';
          len=strlen(a);
          printf("%s  %d\n",a,len);
          
          min=0;
          for(j=1;j<len && min<=(len/2);j++)   
          {
                   printf("min=%d  j=%d  temp1=%d   temp=%d",min,j,temp1,temp2);   
                   if(flag==1)
                   {       
                          flag=0;  
                          if(a[min]>a[j])
                           {
                                  if(a[temp2]<=a[j])
                                          min=temp2;
                                  else
                                           min=j;
                           }
                           else if(a[min]<a[j])
                           {
                                  if(a[temp1]<=a[j])
                                          min=temp1;
                                  else
                                           min=j;
                           }
                           else
                           {
                                  min++;
                                  flag=1;
                           }
                   }
                   else 
                   {        
                           if(a[min]>a[j])       
                                  min=j;
                           else if(a[min]==a[j])
                           {
                                   temp1=min;
                                   temp2=j;
                                   min++;
                                   flag=1;
                           }
                   } 
                   printf("min=%d  j=%d  temp1=%d   temp=%d\n",min,j,temp1,temp2);            
                   system("pause");
          }
          if(flag==1)
              min=temp1;
          printf("%d\n",min+1);
          return (min+1);
}                         
         
          
int main()
{
          int n,ans;
          scanf("%d",&n);
          while(n-->0)
          {
                 ans=beads();
                 printf("%d\n",ans);
          }      
          system("pause");
          return 0;
}
