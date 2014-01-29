#include<stdio.h>
#include<stdlib.h>


typedef struct tree
{
    int data;
    struct tree* left;
    struct tree* right;
}tree;


int insert (tree ** root, int input_data)
{
    tree *new_node,*temp,*parent;
    new_node = (tree *)malloc(sizeof(tree));
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

int print_kdis(tree* root,int k)
    {
        if(root == NULL)
            return 0;
        if( k == 0 )
        {
            printf("__%d__",root->data);
            return 0;
        }
        else
        {
            print_kdis(root->left,k-1 );
            print_kdis(root->right,k-1);
        }
    }

int print_k(tree *root, int data,int k)
{
    tree* temp;
    int d=-1,cd=0;
    temp=root;
    while(temp!=NULL)  //search the node
    {
        d++;
        if(temp->data==data)
            break;
        else if(data < temp->data)
            temp=temp->left;
        else
            temp=temp->right;
    }
    temp=root;
    cd=0;
    while(cd+k<d && temp!=NULL)
    {
        if(data<temp->data)
            temp=temp->left;
        else
            temp=temp->right;
        cd++;
    }

    if(cd+k==d)
    {
        printf("__%d__",temp->data);
    }

    while(cd<d)
    {
        if(data<temp->data)
            print_kdis(temp->right,k-d+cd-1);
        else
            print_kdis(temp->left,k-d+cd-1);

        if(data<temp->data)
            temp=temp->left;
        else
            temp=temp->right;

        cd++;
    }

    print_kdis(temp,k);

    return 0;
}

int  main()
{
    int i,data,num=0;
    tree *root;
    printf("choose a option\n1.Insert\n2.print kth node\n3.quit\nEnter the option");
    scanf("%d",&i);
    root = NULL;
    while (i!=3)
    {
        switch (i)
        {

            case 1: printf("Enter the number in binary search tree\n");
                    scanf("%d",&data);
                    i=insert(&root,data);
                    print(root);
                    break;

            case 2: print(root);
                    printf("enter the node and the value of k");
                    scanf("%d %d",&data,&num);
                    print_k(root,data,num);
                    break;

            case 3: return 0;
        }
         printf("choose a option\n1.Insert\n2.print kth node\n3.quit\nEnter the option");
         scanf("%d",&i);
    }

    return 0;
}
