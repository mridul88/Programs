#include<cstdio>

using namespace std;

int main()
{
	int n,l,i,j,k,*t;
	scanf("%d\n",&n);
	scanf("%d\n",&l);
	t=new int[l];
	for(i=0;i<l;i++)
		t[i]=n/l;
	if(l%2==0)
		k=l/2-1;
	else
		k=l/2;
	for(i=0;i<k;i++)
		t[i]=t[i]-(k-i);
	for(i=l;i>k;i--)
		t[i]=t[i]+(i-k);
	for(i=0;i<l;i++)
		printf("--%d--",t[i]);
	getchar();
  getchar();	
	return 0;
  	
}
