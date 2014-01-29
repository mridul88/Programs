#include <iostream>
using namespace std;
int** graph;
int** flow;
int parent[1000];
int pathlength;
int marked[1000];
int n,h,p,f;
int dfs(int startnode, int endnode)
{
  if(startnode==endnode)
    return 1;
  int i;
  for(i=0;i<h+p+f+2;i++)
    {
      if((graph[startnode][i]-flow[startnode][i])>0 && !marked[i])
	{
	  marked[startnode]=1;
	  parent[i]=startnode;
	  if(dfs(i,endnode)==1)
	    return 1;
	}
    }
      return 0;
}
void maxflow()
{
  int i;
  while(1)
    {
       for(i=0;i<1000;i++)
	 marked[i]=0;
       parent[0]=-1;
       if(dfs(0,h+p+f+1)==0) return;
       int node=h+p+f+1;
       int cfmin=999999;
       while(node!=0)
	 {
	   int p=parent[node]; 
	  cfmin=cfmin < (graph[p][node]-flow[p][node]) ? cfmin : (graph[p][node]-flow[p][node]);
	  node=p;
	}
       node=h+p+f+1;
      while(node!=0)
	{
	  int p=parent[node];
	  flow[p][node]=flow[p][node]+cfmin;
	  flow[node][p]=-flow[p][node];
	  node=p;
	}
    }
}

int main()
{
  int i,j,val;
cin >> n >> h >> p >> f;
graph= new int*[h+p+f+2];
flow= new int*[h+p+f+2];
 for(i=0;i<h+p+f+2;i++)
   {
	graph[i]=new int[h+p+f+2];
	flow[i]=new int[h+p+f+2];
   }

 for(i=0;i<h+p+f+2;i++)
   for(j=0;j<h+p+f+2;j++)
     {
     graph[i][j]=0;
     flow[i][j]=0;
     }
for(i=1;i<h+1;i++)
{
  cin >> val;
  graph[0][i]=val;

}
for(i=1+h+f;i<1+h+f+p;i++)
{
  cin >> val;
  graph[i][1+h+p+f]=val;
}
for(i=0;i<f;i++)
{
  cin  >> val;
  graph[1+h+i][1+h+f+val]=1;

  for(;;)
    {
      cin >> val;
      if(val==1) break;
      graph[1+val][1+h+i]=1;
      }
}
maxflow();
for(i=1;i<1+h;i++)
{
  if(flow[0][i]!=graph[0][i])
    {
      cout << -1;
      return 0;
    } 
}
for(i=1;i<h+1;i++)
{
  
  for(j=1+h;j<1+h+f;j++)
    if(flow[i][j]>0)
    cout << j-(1+h) << " " << i-1 << endl;
    cin.clear();
	while (cin.get() != '\n')
		;
	cin.get();
}
 cin.clear();
	while (cin.get() != '\n')
		;
	cin.get();
 return 0;
}











































