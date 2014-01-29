#include<cstdio>
#include<vector>

using namespace std;

int main()
{
    unsigned int t,i;
    scanf("%d",&t);
    while(t--)
    {
        unsigned int n,l;
        scanf("%d %d",&n,&l);
        vector<int> arr(n,0);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        while(l--)
        {
            unsigned int max,a,p,q;
            max =0;
            scanf("%d %d %d",&a,&p,&q);
            for(i=p-1;i<q;i++)
            {
                unsigned int temp = a^arr[i];
                if(max < temp)
                    max = temp;
            }
            printf("d\n",max);
        }
    }
    return 0;
}

