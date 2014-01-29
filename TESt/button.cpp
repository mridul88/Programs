#include<cstdio>
#include<queue>

struct node
{
       char a[1000][1000];
       int d,color;
} typedef cell;

queue<cell> q;

int bfs(cell s,int n)
{
      int i,j;
      s.d=0;
      s.color=1;
      q.push(s);
      while(!q.empty())
      {
                       
int main()
{
      char ch;
      int i,n,j;
      cell source;
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {
            for(j=0;j<n;j++)
            {
                    scanf("%c",&source.a[i][j]);
            }
      }
      bfs(source,n);                  
      getchar();
      getchar();
      return 0;
}
