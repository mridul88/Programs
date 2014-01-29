/* Program to implement binary tree insert, delete,serach,travesal*/
#include<stdio.h>

typedef struct node
{
	int data;
	struct node * par;
	struct node * left;
	struct node * right;
}tree;

int insert(tree **root,int n)  // Cormen Algo
{
    tree *temp,*parent=NULL,*p;

    p=(tree *)malloc(sizeof(tree));
    p->data=n;
    p->left=NULL;
    p->right=NULL;

    temp=*root;
    while(temp!=NULL) // to get the parent where node has to be added
    {
           parent=temp;
           if(n < temp->data)
                  temp=temp->left;
           else
                   temp=temp->right;
    }
    p->par=parent;

    if(parent==NULL)
            (*root)=p;
    else if(n < parent->data)
           parent->left=p;
    else
            parent->right=p;

    return 0;
}

int print(tree *root) // recursive Inorder
{
        if(root!=NULL)
            printf("--%d--\n",root->data);
        else
        {
               printf("\nEmpty Tree\n");
               return 0;
        }
        if(root->left!=NULL)
                 print(root->left);
        if (root->right!=NULL)
                  print(root->right);
         return 0;
}

tree * min(tree *root)
{
    if(root==NULL)
        return NULL;
    while(root->left!=NULL)
         root=root->left;
    return(root);
}

tree * max(tree *root)
{
    if(root==NULL)
        return NULL;
    while(root->right!=NULL)
         root=root->right;
    return(root);
}

tree **search(tree **start,int n)
{
       tree *root=*start;
       if(root==NULL)
       {
                     printf("EMpty Tree");
                     return(NULL);
       }
       while(root!=NULL && root->data!=n)
       {
                        if(n<root->data)
                                 root=root->left;
                        else
                                 root=root->right;
       }
       if(root==NULL)
                printf("\nNot Present in the Tree\n");
       return (&root);
}

tree* successor(tree *node)
{
      tree *parent,*temp;
      if(node==NULL)
      {
            printf("\nEmpty Tree\n");
           return(NULL);
      }
      temp=node;
      parent=temp->par;
      if(temp->right!=NULL)
             return(min(temp->right));
       while(parent!=NULL && parent->right==temp)
       {
                  temp=parent;
                  parent=temp->par;
       }
       if(parent==NULL)
                 printf("This is the Greatest Element = %d\n",temp->data);
       return(parent);
}
int Delete(tree**root,int n)
{
    tree **node,*temp,*next,*parent;

    (node)=search(root,n);
    temp=*node;
    if(temp==NULL)
            return 0;

    if(temp->right==NULL && temp->left==NULL)
    {
              if(temp->par->right==temp)
                     temp->par->right==NULL;
              else
                     (*node)->par->left==NULL;
    }
    else
    {
              next=successor((*node));
              (*node)->data=next->data;
              while(next->right!=NULL && next->left!=NULL)
                      next=successor((*node));
              Delete(root,next->data);
    }
    return 0;
}

int main()
{
       int c=3,num;
       tree *root=NULL,*node,*temp;
       while(1)
       {
               printf("\n1.Insert\n2.Delete\n3.MAXimum\n4.minimum\n5.Successor\n6.Quit\n");
               scanf("%d",&c);
               switch(c)
               {
                        case 1:  printf("\nEnter No.\n");
                                 scanf("%d",&num);
                                 insert(&root,num);
                                 print(root);
                                 break;
                         case 2: print(root);
                                 printf("\n enter which node to be deletetd\n");
                                 scanf("%d",&num);
                                 Delete(&root,num);
                                 print(root);
                                 break;
                         case 3: print(root);
                                 node=max(root);
                                 if(node!=NULL)
                                          printf("\nmaximun element is: %d \n",node->data);
                                 break;
                         case 4: print(root);
                                 node=min(root);
                                 if(node!=NULL)
                                           printf("\nminimun element is: %d \n",node->data);
                                 break;
                         case 5: print(root);
                                 printf("\n enter node value\n");
                                 scanf("%d",&num);
                                 node=search(&root,num);
                                 if(node!=NULL)
                                 {
                                               node=successor(node);
                                               if(node!=NULL)
                                                        printf("\nsuccessor of this element is: %d \n",node->data);
                                 }
                                 print(root);
                                 break;
                         case 6: return 0;

               }
       }
       return 0;
}
