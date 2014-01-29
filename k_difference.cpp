#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(int i, int j)
{
    return(i<j);
}

int main()
{
    int n,k,i,count=0;
    scanf("%d %d",&n,&k);
    vector<int> a(n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    sort(a.begin(),a.end());

    for(i=0; a[i]<= a[n-1]-k; i++)
    {
        if(binary_search(a.begin(),a.end(),a[i]+k,compare))
        {
            count++;
        }
    }

    printf("%d",count);
    return 0;
}
