#include<stdio.h>
int main()
{
 char maze[13][13];
 int i,k,j,f,r,s,*q,tresure[13]={-1},mask[13][13]={0};
 printf("enter the test cases  \n");    
 scanf("%d %d",&k);
 while(k--)
 {
  printf("enter the size of maze \n");
  scanf("%d",&n);
  q=(int *)malloc(sizeof(int)*n*n);
  
  printf("enter the maze\n");
  for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
   {
    scanf("%c",maze[i][j]);
    //tresure[i*n+j]=-1;
   }
  }  
  for(i=0;i<13;i++)
  {tresure[i]=-1;}        
   q[0]=0;f=0;r=0;
   count=0;
   while( q[f]!=(n-1)*(n-1) )
   {
     s=q[f];
     f++;
     i=s/4;
     j=s%4;
     mak[i][j]=1;
     if(maze[i][j]=='*')
     {
      tresure[++count]=s;
     }
     if( j+1<n && maze[i][j+1]!='#' && mask[i][j]!=1)
     {
      q[++r]=i*4+j+1;
     }               
     if( i+1<n && maze[i+1][j]!='#' && mask[i][j]!=1)
     {
      q[++r]=i*4+j+1;
     }  
   }//end while
                  
 }
}
