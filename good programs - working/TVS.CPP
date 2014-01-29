#include<iostream>
#include<cstdio>

using namespace std;

void tvl(int*, int*, int*, int, int, int);
int max(int, int);
int main()
{
	int n,i, tol;
	int *a, *w, *d;
	cout<<"\nEnter the size of array"<<endl;
	cin>>n;
	a=(int*)malloc(sizeof (int)*(n+1));
	d=(int*)malloc(sizeof (int)*(n+1));
	w=(int*)malloc(sizeof (int)*(n+1));

	cout<<"Enter the positions of the n nodes"<<endl;

	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}

	cout<<"Enter the weights of the n nodes"<<endl;
	for(i=1;i<=n;i++)
	{
		cin>>w[i];
		d[i]=0;
	}

	cout<<endl;
	cout<<"Enter the tolerance value"<<endl;
	cin>>tol;
	tvl(a,w,d, 1, tol, n);
	while(getchar()!='\n');
	getchar();
	return 0;
}



void tvl(int *a, int* w, int* d, int i, int tol, int n)
{
	if(a[i]!=0)
	{
		if((2*i)>n)
		{
			d[i]=0;//leaf
		}

		else
		{
			tvl(a, w, d, 2*i, tol, n);
			d[i]=max(d[i],d[2*i]+w[2*i]);

			if(((2*i)+1)<=n)
			{
				tvl(a,w,d,((2*i)+1),tol,n);
				d[i]=max(d[i],d[(2*i)+1]+w[(2*i)+1]);
			}
		}
	}
	if (d[i]==0)
		return;
	else if((a[i]!=1)&&((d[i]+w[i])>tol))
	{
		printf("The node to be split is %d\n ",a[i]);
		d[i]=0;
	}
}

int max(int a, int b)
{
	if (a>b)

	return(a);

	else
	return (b);
}


