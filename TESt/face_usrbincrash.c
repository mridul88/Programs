/* It is the solution of facebook puzzle usrbincrash. It take O(nW) */

#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000

struct cell
{
	char type[100];
	int w,cost;
};

struct cell item[MAX];	


int min_cost(int n,int weight)
{
	int i,j,min_1,min_2,temp,*cost;
	cost=(int *)malloc(sizeof(int)*(weight+1));
	cost[0]=0;
	for(i=1;i<=weight;i++)
	{
		min_1=-1;
		min_2=-1;
		for(j=0;j<n;j++)
		{
			if(item[j].w<=i) //for all items whose weight is less than required weight
			{
				temp=cost[i-item[j].w] + item[j].cost;
				if(temp<min_1 || min_1<0)
					min_1=temp;
			}
			else //if only 1 item is sufficient (its weight is greater than the required weight) 
			{
				if(item[j].cost<min_2 || min_2<0)
					min_2=item[j].cost;
			}
		}
		if(min_2==-1 || (min_1<min_2 && min_1>=0))
			cost[i]=min_1;
		else 
			cost[i]=min_2;
		//printf("%d.) answer: %d\n",i,cost[i]);
	}

	return cost[weight];
}
				
int main(int argc,char *argv[])
{
	char s[100],c;
	int i,n,weight;
	
	//scanf("%s",s);
	FILE *fp;
	fp=fopen(argv[argc-1],"r");
	fscanf(fp,"%d",&weight);
	c=fgetc(fp);
	for(i=0;c!= EOF;i++)
	{
		fscanf(fp,"%s",item[i].type);
		fscanf(fp,"%d",&item[i].w);
		fscanf(fp,"%d",&item[i].cost);
		//printf("\n %d %s %d %d",c,item[i].type,item[i].w,item[i].cost);
		c=fgetc(fp);
	}
	fclose(fp);
	n=i-1;
	if(n<=0 || weight<0)
		printf("wrong input\n");
	else
		printf("%d\n",min_cost(n,weight));
	
 /*	printf("%d",weight);
	for(i=0;i<n;i++)
		printf("\n%s %d %d",item[i].type,item[i].w,item[i].cost);*/
	return 0;
}		
	
	
	
