#include<conio.h>
#include<stdio.h>
struct linkedlist
{
	char s;
	struct stack *p;
};
typedef struct linkedlist node;
void print(void)
{
	printf(" 1. insert \n 2. delete9 \n 3. quit \n ");
}
int insert(char c)
{
	=(char *)malloc(sizeof(char));


	return 0;
}
int pop(void)
{
	if(top==0)
	{	printf("underflow");
		return 0 ;}
	a[top]=' ';
	top-=1;
	return 0;
}
int manu(void)
{
	char c; int i;
	print();
	scanf("%d",&i);
	switch(i)
	{
	case 1:  clrscr();printf("enter the no.\n");
				push(getch()); printf(" stack :%s\n",a); getch();manu();
				break;
	case 2 : clrscr();printf(" 2. pop\n ");
				pop(); printf("array : %s",a);getch();manu();
				break;
	case 3 : printf(" 3. quit");
				break;
	default :printf("enter correct no.");
				manu();
	}
	return 0;
}
int main()
{
	manu( vbv);
	getch();
	return 0;
}