#include<cstdio>
#include<queue>
#include<stack>
#include<cstdlib>
#include<vector>
//#include<algorithm>

using namespace std;

int main()
{
    stack<float> a;
    a.push(89);
    a.push(35);
    a.push(12);
    while(a.size()>1)
    {
           printf("%f\n",a.top());
           a.pop();
    }
    printf("%d",a.size());
    
    queue<int> q[2]; 
    q[0].push(1);
    q[0].push(2);
    q[0].push(3);
    printf("front=%d back=%d",q[0].front(),q[0].back());
     while(q[0].size()>1)
    {
           printf("%d\n",q[0].front());
           q[0].pop();
    }
    
    int n;
    scanf("%d",&n);
    vector<int> v(n,28);
    vector<int>::iterator p=v.begin();
    v.push_back(12);
    v.insert(p,290);
    for(p=v.begin();p!=v.end();p++)
    {
                    printf("%d  ",*p);
}
    
    
    getchar();
    getchar();
    
    return 0;
}
