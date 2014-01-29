#include<cstdio>

using namespace std;

typedef struct tree
{
    int data;
    tree* left;
    tree* right;
}tree;

int insert (tree ** root, int input_data)
{
    tree *new_node,*temp,*parent;
    new_node = new(tree);
    new_node->data=input_data;
    new_node->right=NULL;
    new_node->left=NULL;

    temp = *root;
	parent = NULL;


    while(temp!=NULL)	  /* serch the apprpiate location, where to add the new_node*/
    {
        parent=temp;
        if(input_data < temp->data)
            temp=temp->left;
        else
            temp=temp->right;
    }

    if(parent==NULL)
        (*root)=new_node;
    else if(input_data < parent->data)
        parent->left=new_node;
    else
        parent->right=new_node;

    return 1;
}

int modify_inorder(tree *root, int n)
{
	static int num=0;
	if(root==NULL)
	{
		//printf("Empty Tree");
		return 0;
	}

	if(root->right!=NULL)
		modify_inorder(root->right,n);
    num++;
    if(num==n)
	{
	    printf("%d",root->data);
	}
	if(root->left!=NULL)
		modify_inorder(root->left,n);
	return 0;
}

int print(tree *root)
{	if(root==NULL)
	{
		printf("Empty Tree");
		return 0;
	}
	if(root->left!=NULL)
		print(root->left);
    printf("--%d--",root->data);
	if(root->right!=NULL)
		print(root->right);
	return 0;
}

int  main()
{
    int i,data,num=0,n;
    tree *root;
    printf("choose a option\n1.Insert\n2.print\n3.nth max\n4.quit\nEnter the option");
    scanf("%d",&i);
    root = NULL;
    while (i!=4)
    {
        switch (i)
        {

            case 1: printf("Enter the number in binary search tree\n");
                    scanf("%d",&data);
                    i=insert(&root,data);
                    if(i==0)
                        printf("error in creating new node");
                    break;

            case 2:
                    print(root);
                    break;

            case 3: printf("enter n");
                    scanf("%d",&n);
                    modify_inorder(root,n);
					print(root);
                    break;
        }
         printf("choose a option\n1.Insert\n2.print\n3.nth max\n4.quit\nEnter the option");
         scanf("%d",&i);
    }

    return 0;
}
