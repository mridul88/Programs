#include<cstdio>

using namespace std;

typedef struct tree
{
    int data,successor_data;
    tree* left;
    tree* right;
}tree;

int a[50],count;

int insert (tree ** root, int input_data)
{
    tree *new_node,*temp,*parent;
    new_node = new(tree);
    new_node->data=input_data;
	new_node->successor_data=0;
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

int modify_inorder(tree *root)
{
	if(root==NULL)
	{
		printf("Empty Tree");
		return 0;
	}
	if(root->left!=NULL)
		modify_inorder(root->left);
	count++;
	root->successor_data=a[count];
	if(root->right!=NULL)
		modify_inorder(root->right);
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
    printf("--%d + %d--",root->data, root->successor_data);
	a[count++]=root->data;
	if(root->right!=NULL)
		print(root->right);
	return 0;
}

int print_array()
{
    for(int i=0;i<10;i++)
        printf("_%d_",a[i]);
    return 0;
}

int  main()
{
    int i,data,num=0;
    tree *root;
    printf("choose a option\n1.Insert\n2. print_inorder\n3.combining the inorder successor\n4.quit\nEnter the option");
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

            case 2: count=0;
                    print(root);
                    print_array();
                    break;

            case 3: count=0;
                    modify_inorder(root);
					print(root);
                    break;
        }
         printf("choose a option\n1.Insert\n2.Inorder sucessor 3.combning the inorder successor\n4.quit\nEnter the option");
         scanf("%d",&i);
    }

    return 0;
}
