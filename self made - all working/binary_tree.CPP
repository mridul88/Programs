#include<cstdio>

using namespace std;
typedef struct tree
{
	int x;
	struct tree * left;
	struct tree * right;
}tree;
void insert(tree *root)
{
	int n;
	printf("enter the number");
	scanf("%d",&n);
	tree *extra,*ptr,*par;
	extra=new (tree);
	extra->x=n;
	extra->left=NULL;
	extra->right=NULL;
  /*	if(root==NULL)
	{
		root=extra;
		root!= NULL ;
		return;
	}   */
	par=root;
	if(n<=root->x)
		ptr=root->left;
	else
		ptr=root->right;
	while(ptr!=NULL)
	{	if(n<=ptr->x)
		{	par=ptr;
			ptr=ptr->left; }
		else
		 { par=ptr;
			ptr=ptr->right; }
	}
	if(n<=par->x)
		par->left=extra;
	else
		par->right=extra;
}
void print(tree *root )
{
	if(root==NULL)
		return;
	if(root->left!=NULL)
		print(root->left);
	if(root->right!=NULL)
		print(root->right);
	printf("\n%d",root->x);
	return;
}
void search(tree *root,tree **loc,tree **suc ,int f)
{
	if(root==NULL)
	 {	*loc=NULL;
		*suc=NULL;
		return ;
	  }
	if(f==root->x)
	{
		*loc=root;
		*suc=NULL;
		return;
	}
	tree *ptr,*par;
	par=root;
	if(f<=root->x)
		ptr=root->left;
	else
		ptr=root->right;
	while(ptr!=NULL)
	{
		if(f==ptr->x)
		{
		   *loc=ptr;
			*suc=par;
			return;
		}
		par=ptr;
		if(f<=ptr->x)
			ptr=ptr->left;
		else
			ptr=ptr->right;
	}
	*loc=NULL;
	*suc=par;
	return;
}

void casea(tree*loc, tree*par,tree*root)
{
	tree *child;
	if(loc->left==NULL && loc->right==NULL)
		child=NULL;
	else if(loc->left==NULL)
		child=loc->right;
	else
		child=loc->left;
	if(par==NULL)
		root=child;
	else if(loc->x<=par->x)
		par->left=child;
	else
		par->right=child;
}
void caseb(tree *loc, tree*par, tree*root)
{
	tree*save,*ptr;
	ptr=loc->right;
	save=loc;
	while(ptr->left!=NULL)
	{
		save=ptr;
		ptr=ptr=ptr->left;
	}
	casea(ptr,save,root);
	if(par==NULL)
		root=ptr;
	else if(loc==par->left)
		par->left=ptr;
	else
		par->right=ptr;
	ptr->left=loc->left;
	ptr->right=loc->right;
}
int deletion(tree* root)
{
	int n;
	printf("enter the number to be deleted");
	scanf("%d",&n);
	tree *loc,*suc;
	search(root,&loc,&suc,n);
	if(loc==NULL)
	{
		printf("this element is not in tree");
		return 0;
	}
	if((loc->left!=NULL) && (loc->right!=NULL))
		caseb(loc,suc,root);
	else
		casea(loc,suc,root);
	delete(loc);
	return 0;
}
int main()
{
	int i=0,n;
	tree *root,*loc,*suc;
	printf("enter the number");
	scanf("%d",&n);
	root=new(tree);
	root->x=n;
	root->left=NULL;
	root->right=NULL;
	while(i!=4)
	{
		printf("\n1. insert\n2. delete\n3. search\n4.exit\n enter your choice");
		scanf("%d",&i);
		switch(i)
		{
		case 1: insert(root);
					break;
		case 2: deletion(root);
					break;
		case 3:	printf("enter the number you wnt to search");
					scanf("%d",&n);
					search(root,&loc,&suc,n);
					printf(" it is there in the tree and it's parent is %d ",suc->x);
			   getchar();
					break;
		default: printf("please enter the valid number");
		}
		//printf("%d",root->left);
		print(root);
	}
	while(getchar()!='\n');
	getchar();
	return 0;
}

