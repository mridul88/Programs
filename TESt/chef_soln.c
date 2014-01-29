#include<stdio.h>
#include<string.h>
#include<cassert>
using namespace std;
const int MAXN = 1002;
int n,a[MAXN],b[MAXN],need[2][MAXN];
int sol[MAXN];
 
int main()
{
  int runs;
  scanf("%d",&runs);
  assert(1 <= runs && runs <= 30);
  while(runs--)
  {
    scanf("%d",&n);
    assert(2 <= n && n <= 1000 && n % 2 == 0);
    for(int i = 0;i < n;i++)
    {
      scanf("%d",&a[i]);
      assert(1 <= a[i] && a[i] <= 500);
    }
    memset(b,0,sizeof b);
    for(int i = 0;i < n;i++) b[a[i]]++;
    for(int i = 1;i <= 500;i++) need[0][i] = need[1][i] = b[i] / 2;
    int p = 0,sz = 0;
    for(int i = 0;i < n;i++)
    {
      if(need[p][a[i]] > 0) need[p][a[i]]--;
      else
      {
        sol[sz++] = i;
        p = 1 - p;
        i--;
      }
    }
    printf("%d\n",sz);
    for(int i = 0;i < sz;i++)
    {
      if(i > 0) printf(" ");
      printf("%d",sol[i]);
    }
    printf("\n");
  }
  return 0;
}
 

