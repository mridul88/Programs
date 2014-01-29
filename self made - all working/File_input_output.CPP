#include<cstdio>

using namespace std;

int main()
{
	int i,j;
	FILE *fp;
	char test[10][1000];
	char c;
	fp=fopen("test.in","w");
	fprintf(fp,"start writing\nmridul\nmalpani\nis\na\ngood\nboy.");
	fclose(fp);
	fp=fopen("test.in","r");
	while((c=getc(fp))!=EOF)
	{
            printf("%c",c);
	}
	while(getchar()!='\n');
	getchar();
	return 0;
}
