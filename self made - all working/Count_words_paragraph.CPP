/* Input: in paragraph form ( all characters & numbers)
   output: Number of words(i.e that are separted by white space) 
   press enter twice to terminate*/

#include<stdio.h>

int c[20][100];

int check(int i)
{
	int temp[50],j=0,ch,k,l=0;
	temp[l]=c[i][j];
	j++;
	while(c[i][j]!='A')
	{
	   ch=c[i][j];
	   for(k=0;k<l;k++)
	   {
		 if(temp[k]==ch)
			return 0;
	   }
	   if(ch==temp[l])
			j++;
	   else
	   {
			l++;
			temp[l]=ch;
			j
			++;
	   }
	}
	return 1;
}
int main()
{
	int n,i=0,j,l,ch,sum=0;
	while((ch=getchar())!='\n')
	{
		j=0;
		c[i][j]=ch;
		ch=getchar();
		while(ch!=' '&& ch!='\n')
		{
		   j++;
		   c[i][j]=ch;
		   ch=getchar();
		}
		c[i][++j]='A';
		i++;
	}
	n=i;
	for(i=0;i<n;i++)
	{
		l=check(i);
		sum=sum+l;
	}
	printf("%d",sum);
	getchar();
	return 0;
}

