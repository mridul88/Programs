#include<stdio.h>
#include<string.h>

void print(char *a,int start,int end)
{
     int i;
     for(i=start;i<=end;i++)
             printf("%c",a[i]);
     printf("_");
     return;
}
               
int permutation(char *a,int index)
{
    int i,j,len;
    char temp;
    
    len=strlen(a)-index;
    if(len==1)
    {
              print(a,index,index);
              printf("\n");
              return 0;
    }
    for(i=len-2;i>=0;i--)
    {
           for(j=i+index;j<=strlen(a)-2;j++)
           {
                 // printf("i=%d j=%d len=%d\n",i,j,strlen(a));                    
                  print(a,index,i+index);
                  
                  if(j!= strlen(a)-2)  /*means more thana 2 elements ar there*/
                 { 
                  /* swap a[i+1] element with a[j+2]*/
                  temp=a[i+index+1];
                  a[i+index+1]=a[j+2];
                  a[j+2]=temp;
                  }
                  permutation(a,i+1+index);                 
           }
    }
    return 0;
}                     
                               

int main()
{
    char a[]="abcd";
    permutation(a,0);
    getchar();
    return 0;
}
