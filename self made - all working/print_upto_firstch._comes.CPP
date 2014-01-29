/* Input : first chracter then a stream of characters in a para form
   Output: print the stream upto when it contain the same character as the first character.
*/

#include<stdio.h>

int ans[50];

int main()
{
	int i=0,j,ch;
	ch=getchar();
	while(ch!='\n')
	{
		ans[i]=ch;
		ch=getchar();
		if(ch==ans[0])
		{
			printf("'");
			for(j=0;j<=i;j++)
				printf("%c",ans[j]);
			printf("'");
			while ( getchar()!= '\n')
		            ;
        	getchar();
			return 0;
		}
		else
			i++;
	}
	while ( getchar()!= '\n')
		;
	getchar();
	return 0;
}
