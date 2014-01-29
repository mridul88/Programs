#include<cstdio>
#include<cstring>
char name[3][25];
//name[2][25]="adf";
/*char ch(int i, int j,int d)
{
	char c; static int flag=0;
	if((*(ptr[d]+(5*i+j)))=='\0')
		flag=1;
	if(flag!=1)
		c=(*(ptr[d]+(5*i+j)));
	else
	{
		static int m=0;
		c=(*(ptr[2]+m));
		m++;
	}
	return c;
}*/
int main()
{   
    	scanf("%s%s",&name[0][25],&name[1][25]);
	char name[2][25]={"bg"};//{'a','b'}//,'c','d','e','f','g','h','i','j','k','l','m','n','o','p','r','s','t','u','v','w','x','y','z','\0'};
	char l[5][5],r[5][5];
	//sprintf(ptr[0],"%s",name);
	printf("%s%s%s",name[1][25],name[0][25],name[2][25]);
   /*	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{   char c=ch(i,j,1);
			l[i][j]=c;
			printf("%c\t",l[i][j]);
		}
		printf("\n");
	}*/
	while(getchar()!='\n');
	getchar();
	return 0;

}
