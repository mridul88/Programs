#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int main()
{
	int i=0,c,j=0;
	char *ptr[5]={"megha","mridul","sangita","malpani","suresh",},*temp;
   //	printf("%u %s %s %s	",ptr,*(ptr+1),2+(*ptr),ptr[1]);
	for(j=0;j<4;j++)  // bubble sort
	{
	for(c=0;c<4;c++)
	{
		i=strcmp(*(ptr+c),*(ptr+c+1)); // strcmpare will compare 2 string, only need to pass strating pointers and r
  	 //	printf("%d\n",i);                  return the differce in th ascii value between str1-st2 char.
		if(i>0)
			{
				temp=*(ptr+c);
				*(ptr+c)=*(ptr+c+1);
				*(ptr+c+1)=temp;
			}

	}
	}
	for(i=0;i<5;i++)
		printf("%8s\n",*(ptr+i));
    while(getchar()!='\n');
	 getchar();
}
