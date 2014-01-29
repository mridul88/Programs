#include<stdio.h>
#include<conio.h>
char c[20][100];
int main()
{
    int n,i=0,j,l;
    char ch;
    ch=getchar();
    while(ch!='\n')
	{
		j=0;
		c[i][j]=ch;
		ch=getchar();
		while(ch!=' '||ch!='\t')
		{
		   j++;
		   c[i][j]=ch;
		   ch=getchar();
		}
		c[i][++j]='A';
		i++;
		ch=getchar();
	}
	n=i;
	for(i=0;i<n;i++)
	{
		for(j=0;c[i][j]!='A';j++)
			printf("%c",&c[i][j]);
	}
    getch();
}              
                   
