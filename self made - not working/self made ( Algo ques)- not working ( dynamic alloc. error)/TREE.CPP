#include<cstdio>
#include<cstdlib>

struct tree
{
	int m;
	 struct tree *left;
	 struct tree *right;
};
typedef struct tree node;
int create(node *p)
{  int flag=0;
	scanf("%d",&p->m);
	if(p->m<0)
	{
		p->left=NULL;
		p->right=NULL;
		flag=1;
		return 0;
	}
  //	if(p->left->left!=NULL)
	{
		p->left=new(node);
		create(p->left);
	}
  //	if(p->right->right!=NULL)
  if(flag==1)
	{  printf("not from starting");
	return 0;
	  //	p->right=new(node);
	  //	create(p->right);
	}
	return 0;
}
int print(node *p)
{
	if(p->left!=NULL||p->right!=NULL)
		printf("\n%d\n\t",p->m);
	else
		return 0;
	if(p->left!=NULL)
		print(p->left);
	if(p->right!=NULL)
		print(p->right);
	return 0;
}
int main()
{
	node *start;
	create(start);
	print(start);
	while(getchar()!='\n');
	getchar();
	return 0;
}












