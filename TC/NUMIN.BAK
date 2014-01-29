#include<stdio.h>  //to take the input of a paragraph
#include<conio.h>
void main()
{
	int **ptr[1];
	int i=-1,j=0,s,c;
	scanf("%d",&s);
	while(s!=0)
	{
		i=i+1;
		j=0;
		*(*(*(ptr)+i)+j)=s;
		while((c=getchar())==' ')
		{
			j++;
			scanf("%d",&s);
			*(*(*(ptr)+i)+j)=s;
		}
		*(*(*(ptr+1))+i+1)=j;
	   //	printf("l[i]=%d j=%d i=%d",*(*(*(ptr+1))+i),j,i);
	   // why *(*(*(ptr+1))+0)=j; creates problem?
		scanf("%d",&s);
	}
   //	printf("i=%d,l[0]=%d,l[1]=%d,j=%d",i,*(*(*(ptr+1))+0),*(*(*(ptr+1))+1),j);
	for(int m=0;m<=i;m++)
		for(int n=0;n<=*(*(*(ptr+1))+m+1);n++)
			printf(" %d ",*(*(*(ptr)+m)+n));
		printf("\n");
	getch();
}


