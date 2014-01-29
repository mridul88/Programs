#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
	int i=0,c,j=0;
	char *ptr[5]={"roji","manu","mridul","malpani","megha",},*temp;
	printf("%s %s %s %s	",*ptr,*(ptr+1),2+(*ptr),ptr[1]);
	for(j=0;j<4;j++)
	{
	for(c=0;c<4;c++)
	{
		i=strcmp(*(ptr+c),*(ptr+c+1));
		//printf("%d\n",i);
		if(i>0)
			{
				temp=*(ptr+c);
				*(ptr+c)=*(ptr+c+1);
				*(ptr+c+1)=temp;
			}

	}
	}
	for(i=0;i<5;i++)
		printf("%s\n",*(ptr+i));
   while(getchar()!='\n');
	 getchar();
	 return 0;
}
