#include<cstdio>  //to take the input of a paragraph
#include<cstring>

using namespace std;

int main()
{
	int j,flag,i=0,s=0,k;
	char a[200][20],c;
	c=getchar();
	while(c!='#')
	{
		if(s==1)
			c=getchar();
		s=1;
		flag=0;j=0;
		while((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
		{
			flag=1;
			 a[i][j]=c;
			j=j+1;
			c=getchar();
		}
		if(flag==1)
		{
			a[i][j]='\0';
			i=i+1;
		}
	}
  //	for(c=0;c<i;c++)
	//	printf(" %s ",a[c]);
	int*f,b=0;
	f=new int[i];
	for(c=0;c<i;c++)
		f[c]=1;
	for(s=0;s<i;s++)
	{
		for(c=s+1;c<i;c++)
		{
			j=strcmp(a[s],a[c]);
			if(j==0||j%32==0)
			{
				f[s]++;
			}
		}
	}
	k=f[0];
	for(c=0;c<i;c++)
		if(f[c]>k)
		{	k=f[c];
			b=c;
		}
	printf("%d %s",k,a[b]);
	while(getchar()!='\n');
	getchar();
    return 0;
}

