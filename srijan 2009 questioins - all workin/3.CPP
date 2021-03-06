#include <iostream>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int i,j,k;
int SIZE=600; 
const int MAXSIZE=600;
const int MAX_INT=33767;
int gmatrix[MAXSIZE][MAXSIZE];
int parent[MAXSIZE];
void prims()
{
	vector<double> heap(SIZE);
	vector<bool> extracted(SIZE);
	int i;
	for(i=0;i<SIZE;i++)
	{
		heap[i]=MAX_INT;
		parent[i]=-1;
		extracted[i]=false;
	}
	heap[0]=0;
	parent[0]=0;
	int ex=0;
	while(ex<SIZE)
	{
		vector<double>::const_iterator min=min_element(heap.begin(),heap.end());
		int v=min-heap.begin();
		extracted[v]=true;
		heap[v]=MAX_INT;
		ex++;
		int i;
		for(i=0;i<SIZE;i++)
		{
			int w=i;
			if(extracted[w]==false && heap[w]>gmatrix[v][w])
			{
				heap[w]=gmatrix[v][w];
				parent[w]=v;
			}
		}
	}
}

int main()
{
	cin >> SIZE;
    int a,b,c;
    for(i=0;i<SIZE;i++)
        for(j=0;j<SIZE;j++)
            gmatrix[i][j]=MAX_INT;
    while(1)
	{
		cin >> a >> b >> c;
        if(a==1&&b==1 && c==1) break;
        gmatrix[b][a]=gmatrix[a][b]=c;
	}
	prims();
    int maxdist=0,dist;
	for(i=0;i<SIZE;i++)
	{
		j=parent[i];
		if(i==j) continue;
        dist = gmatrix[i][j];
        if (dist>maxdist) maxdist=dist;
	}
    cout << maxdist;
	cin.clear();
	while (cin.get() != '\n')
		;
	cin.get();
    return 0;
}
