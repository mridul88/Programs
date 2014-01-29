/* This is program to implement the questioin 9.6.2 of book - programming challenges
   name of problem: play with wheels */ 
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
       
struct node
{
       int number,color,d;
} arr[10000];

int front=-1,rear=-1,a[10000];

int enqueue(int n)
{
        int temp=rear;
        if(rear==9999)
              rear=0;
        else 
               rear++;
        if(rear==front)
        {
              rear=temp;
              return;
        }                     
        if(front==-1)
               front=0;
        a[rear]=n;
        return 0;      
}

int dequeue()
{
      int temp=front;
      if(front==9999)
            front=0;
      else if(front==rear)
      {
                rear=-1;
                front=-1;
      }
      else
                   front++;                                                             
      return(a[temp]);
}

void print_queue()
{
        int i;
        printf("in queue \n");
        for(i=front;i<=rear;i++)
                   printf("%d ",a[i]);
        return;
}                                                                                                         
int get_next(int n,int a[])
{
       int i,j,original[4],ans[8][4];
       for(i=3;i>=0;i--)         //convert the number to array
       {
               original[i]=n%10;
               n=n/10;        
       }                
               
       for(j=0;j<8;j++) // copy originl array to all 8 next member & a[i]=0'
       {
                a[j]=0;                
                for(i=0;i<4;i++)
                          ans[j][i]=original[i];
       }
       for(i=0;i<4;i++)                  // decrese all the four bits one at a time            
                if(ans[i][i]==0)
                        ans[i][i]=9;
                else
                        ans[i][i]--;
        for(i=0;i<4;i++)                 // increase   ''  '' ''             
                if(ans[i+4][i]==9)
                        ans[i+4][i]=0;
                else
                        ans[i+4][i]++;                    
       for(i=0;i<8;i++)     
       {       
                a[i]=0;                                //convert array to number and store in array a
                for(j=0;j<4;j++)
                           a[i]= a[i]*10 + ans[i][j];
                //printf("%d\n",a[i]);     
       }
            
       return 0;
}

int not_list(int size,int *forbidden,int n)
{
        int i,j;
        for(i=0;i<size;i++)
        {
              if(n==forbidden[i])
                    return 0;
        }
        return 1;
}
                                                          
int bfs(int source,int target,int size,int *forbidden)
{
        int i,j,k,next[8]; 
        for(i=0;i<=9999;i++)
        {
                 arr[i].color=0;
                 arr[i].d=999999;
        }        
        arr[source].d=0;
        arr[source].color=1;
        enqueue(source);
        while(front!=-1)
        {
                  j=dequeue();
                  get_next(j,next);
                  //printf("NExt values are:\n");
                  for(i=0;i<8;i++)
                  { 
                           //printf("%d--\n",next[i]);                       
                           if(arr[next[i]].color==0 && not_list(size,forbidden,next[i]) )
                           {
                                      if(next[i]==target)
                                      {
                                              printf("%d",arr[j].d+1); 
                                              return 0 ;
                                      }           
                                       arr[next[i]].color=1;         
                                       arr[next[i]].d= arr[j].d +1;
                                       enqueue(next[i]);
                           }
                  }
                 
        }
        printf("-1");  
        return 0;
}
                                  
int get_in(void)
{
       int c,n=0,i;
       for(i=0;i<4;i++)
       {
               scanf("%d",&c);
                     n=c+n*10;
       }
       return n;
}
                                                                                                           
int main()
{
       int i,n,source,target,*forbidden;
       source=get_in();
       target=get_in();
       //printf("%d",source);
       scanf("%d",&n);
       forbidden=(int *)malloc(sizeof(int)*n);
       for(i=0;i<n;i++)
               forbidden[i]=get_in();        
       bfs(source,target,n,forbidden);
       getchar();                          
       getchar();
       return 0;
}
