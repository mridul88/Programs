#include<cstring>
#include<cstdio>

using namespace std;

int compare(char *a,char *b)
{
	for(int i=0;*(b+i)!='\0';i++)
	{
		if(*(a+i)!=*(b+i))
		      return 1;
	}
	return 0;
}
void copy(char *s,int i,char *r,char *p)
{
    int j,l; 
	for(j=i,l=0;*(r+l)!='\0';j++,l++)
	{
		*(s+j)=*(r+l);
	}
	int d=strlen(p)- strlen(r);
	if(d>0)
	{
		while(*(s+j)!='\0')
		{
			*(s+j)=*(s+j+d);
			j++;
		}
	}
}
int main()
{
	
	int c,l=0,i=0;
	char *s,*p,*r;
	c=getchar();
	while(c!='\n')
	{
	       s[i]=c;
	       i++;
	       c=getchar();
	}
	l=i;
	scanf("%s",p);
	scanf("%s",r);
	for(i=0;i<l;i++)
	{
		if((compare((s+i),p))==0)
		{
			copy(s,i,r,p);
		}
	}
	printf("%s",s);

	getchar();
	return 0;
}
