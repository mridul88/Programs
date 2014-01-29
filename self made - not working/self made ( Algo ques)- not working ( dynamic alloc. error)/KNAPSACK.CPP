#include<stdio.h>
#include<conio.h>
void sort(float**a,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(a[2][j]<a[2][j+1])
			{
				for(int k=0;k<3;k++)
				{
					int t=a[k][j];
					a[k][j]=a[k][j+1];
					a[k][j+1]=t;
				}
			}
		}
	}
}

void main()
{
	clrscr();
	float **a,current,profit=0;/*0=w;1=p;ratio=2;ans=3*/
	int i=0,size;
	printf("enter the size of knapsack\n");
	scanf("%f",&current);
	printf("enter the weight and price \n press 0 0to exit");
	printf("\nweight\tprofit\n");
	scanf("%f %f",&a[0][0],&a[1][0]);
	while(a[1][i]!=0||a[0][i]!=0)
	{
		a[2][i]=0;
		a[3][i]=0;
		i++;
		scanf("%f %f",&a[0][i],&a[1][i]);
	}
	size=i;
	for(i=0;i<size;i++)
		a[2][i]=a[1][i]/a[0][i];
	sort(a,size);
	for(i=0;i<size;i++)
	{
		if(a[0][i]<=current)
		{
			a[3][i]=1;
			current=current-a[0][i];
			profit=profit+a[1][i];
		}
		else
		{
			a[3][i]=current/a[0][i];
			profit=profit+a[3][i]*a[1][i];
		}
	}
	printf("\nweight\tprofit\tfraction\n");
	for(i=0;i<size;i++)
		printf("%.2f \t %.2f \t %.2f\n",a[0][i],a[1][i],a[3][i]);
	printf("\nmax profit=%f",profit);
	getch();

}