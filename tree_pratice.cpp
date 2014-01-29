#include<cstdio>

static int a[20];
using namespace std;

typedef struct tree_node
{
    int data;
    struct tree_node *right;
    struct tree_node *left;
}tree;

void insert(tree **root, int data)
{
    tree *temp, *new_node;
    new_node = new(tree);
    new_node->data=data;
    new_node->left=new_node->right= NULL;

    temp = *root;

    if(!temp)
    {
        *root = new_node;
        return;
    }

    while (temp!=NULL && (temp->left!=NULL || temp->right!=NULL))
    {
        if(data <= temp->data)
        {
            if(temp->left!=NULL)
                temp = temp->left;
            else
                break;
        }

        if(data > temp->data)
        {
            if(temp->right!=NULL)
                temp = temp->right;
            else
                break;
        }

    }

    if(data > temp->data)
    {
        temp->right = new_node;
    }
    else
    {
        temp->left= new_node;
    }
    return ;
}

void print(tree *root)
{
    if(!root)
    {
        printf("Empty Tree");
        return ;
    }
    printf("%d->",root->data);
    if(root->left!=NULL)
        print(root->left);
    if(root->right!=NULL)
        print(root->right);
    return ;
}

void printlist(tree *start)
{
    tree *temp;
    temp = start;
    while(temp!=NULL)
    {
        printf("--%d--",temp->data);
        temp =temp->right;
        if(temp == start)
            break;
    }
    return;
}

int vertical_sum(tree *root, int curr, int target)
{
    int l,r;
    if(!root)
    {
        return 0;
    }

    l = vertical_sum(root->left, curr-1,target);
    r = vertical_sum(root->right, curr+1,target);
    if(curr == target)
    {
        return(root->data+l+r);
    }
    else
        return (l+r);

}

int height(tree *root)
{
    //static int h =0;
    int lh,rh;

    if(!root)
    {
        return 0;
    }
    lh = height(root->left);
    rh = height(root->right);
    if(rh > lh)
        return (rh+1);
    else
        return (lh+1);
}

int diameterf (tree *root, int *height)
{
    static int diameter =0;
    int lh=0,rh=0,rd,ld;

    if(!root)
    {
        *height=0;
        return 0;
    }

    ld = diameterf(root->left,&lh);
    rd = diameterf(root->right,&rh);

    if(rh > lh)
        *height = rh+1;
    else
        *height = lh+1;

    if(rd < ld)
        diameter = ld;
    if(diameter < rh+lh+1)
        diameter = rh+lh+1;
    //printf("\nD= %d",diameter);
    return diameter;
}

char isLeaf(tree *root)
{
    if(root!=NULL && root->left==NULL && root->right==NULL)
    {
        return 1;
    }
    return 0;
}

int no_leaves(tree *root)
{
   // static int count =0;
    int lc, rc;

    if(!root)
    {
        return 0;
    }
    lc = no_leaves(root->left);
    rc = no_leaves(root->right);


    return (lc + rc + (isLeaf(root)? 0 : 1));

}

int no_nodes(tree *root)
{
    int lc, rc;

    if(!root)
    {
        return 0;
    }
    lc = no_nodes(root->left);
    rc = no_nodes(root->right);
    printf("\n%d%d\n",lc,rc);

    return (lc+rc+1);
}

tree * append(tree *start, tree* next) //jointwo circular linked list start, next as start->next
{
    tree *alast, *blast;
    if(!start)
        return next;
    if(!next)
        return start;

    alast = start->left; //as it is a circular doubly linked list, so start->left points to last;
    blast = next->left;

    alast->right = next;
    blast->left = alast;

    blast->right = start;
    start->left = blast;

    return start;
}

tree *tree2list(tree *root)
{
    tree *start, *previous,*forward;
    if(!root)
    {
        return 0;
    }

    previous = tree2list(root->right);
    forward = tree2list(root->left);

    root->left = root;
    root->right = root;

    previous = append(previous,root);
    previous = append(previous,forward);

    return previous;
}

tree * nth_max(tree*root, int n)
{
    static int count =0;
    static tree *temp;
    if(!root)
        return 0;
    if( root->right!=NULL)
        nth_max(root->right,n);

     count++;
     if(count == n)
      {
          temp = root;
          count =0;
      }
    if(root->left!=NULL)
        nth_max(root->left,n);
    return temp;
}

bool hasPathSum(tree *root, int sum)
{
    bool flag;
    if(!root)
        return false;
    else if(isLeaf(root) && sum == root->data)
    {
        printf("%d + ",root->data);
        return true;
    }
    else
    {
        flag  = (hasPathSum(root->left,sum -(root->data)) || hasPathSum(root->right,sum -(root->data)) );
        if(flag)
            printf("%d+",root->data);
        return flag;
    }
}

int printpath(tree *root)
{
    static int count;
    int i;
    if(!root)
    {
        return 0;
    }
    if(root->left == NULL && root->right==NULL)
    {
        a[count++]= root->data;
        for(i=0;i<count;i++)
            printf("__%d__",a[i]);
        printf("\n");
        return 0;
    }
    a[count++]= root->data;
    if(root->left!=NULL)
    {
        printpath(root->left);
        count--;
    }
    if(root->right!=NULL)
    {
        printpath(root->right);
        count--;
    }
    return 0;
}

bool isIsomorphic(tree *root1, tree* root2)
{
    static bool ans = true;
    if(ans==false)
        return false;
    if(root1==NULL && root2==NULL)
        return true;
    else if( (root1==NULL && root2!=NULL) || (root1!=NULL && root2==NULL) )
        return false;
    else
        return (isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right));
}

void mirror(tree* root)
{
    tree *temp;
    if(!root)
        return;

    mirror(root->left);
    mirror(root->right);

    temp = root->left;
    root->left= root->right;
    root->right=temp;

    return;
}

void double_tree(tree *root)
{
    tree *new_node , *temp;
    if(!root)
         return;

    double_tree(root->left);

    new_node = new(tree);
    new_node->data = root->data;
    new_node->right = NULL;

    temp = root->left;
    root ->left = new_node;
    new_node->left = temp;

    double_tree(root->right);
    return ;
}

bool isBST(tree *root,int min,int max)
{
    if(!root)
        return true;

    if(root->data >= max || root->data < min)
        return false;

    return ( isBST(root->left,min,root->data) && isBST(root->right,root->data,max));
}

int catalan_no(int num)
{
    int i,left,right,root=0;
    if(num ==0 || num == 1)
        return 1;

    for(i=1;i<=num;i++)
    {
        left = catalan_no(num - i);
        right = catalan_no(i-1);
        root += left*right;
    }
    return root;
}

void getinorder(tree *root)
{
    static tree *prev_visited = NULL;
    if(!root)
        return;
    getinorder(root->right);
    if(prev_visited!=NULL)
        root->data += prev_visited->data;
    prev_visited = root;
    getinorder(root->left);
    return;
}

tree * lca(tree* root,int p,int q)
{
   tree *l, *r, *tmp;

   if(root == NULL)
   {
      return(NULL);
   }

   if(root->left->data==p || root->right->data==p || root->left->data==q || root->right->data==q)
   {
     return(root);
   }
   else
   {
      l = lca(root->left, p, q);
      r = lca(root->right, p, q);

      if(l!=NULL && r!=NULL)
      {
        return(root);
      }
      else
      {
         tmp = (l!=NULL) ? l : r;
         return(tmp);
      }
   }
}

int main()
{
    int i,data,num=0,a,b;
    tree *root;
    printf("choose a option\n1.Insert\n2.print kth node\n3.vertical_sum\n4.height\n5.Diameter\n6.No_of_Leaves\n7.tree2list\n8.HAs_PAth_SUM\n9.mirror\n10.isIsomorphic\n11.double tree\n12.isBST\n13.catalan_no\n14.\n15.To get LCA\n16.quit\nEnter the option");
    scanf("%d",&i);
    root = NULL;
    while (i!=16)
    {
        switch (i)
        {

            case 1: printf("Enter the number in binary search tree\n");
                    scanf("%d",&data);
                    insert(&root,data);
                    print(root);
                    break;

            case 2: print(root);
                    printf("enter the node and the value of k");
                    scanf("%d %d",&data,&num);
                    //print_k(root,data,num);
                    break;

            case 3: print(root);
                    printf("\n");
                    scanf("%d",&a);
                    printf("%d\n", vertical_sum(root,0,0));
                    print(root);
                    break;

            case 4: print(root);
                    printf("\nheight of the tree = %d\n",height(root));
                    break;

            case 5: print(root);
                    i=0;
                    printf("\nDiameter of the tree = %d\n",diameterf(root,&i));
                    break;

            case 6: print(root);
                    printf("\n No of nodes in the tree = %d\n", no_nodes(root));
                    break;

            case 7: print(root);
                    printf("\n list is:  ");
                    printlist(tree2list(root));
                    break;

            case 8: print(root);
                    printf("Enter the SUM\n");
                    scanf("%d",&data);
                    printf("Is there any Path : %d\n",hasPathSum(root,data));
                    break;

            case 9: print(root);
                    printf("\n");
                    mirror(root);
                    print(root);

           case 10: print(root);
                   // printf("Are two trees isomorphic : %d\n",isIsomorphic(root,root));
                    printpath(root);
                    break;

           case 11: print(root);
                    printf("\n");
                    double_tree(root);
                    print(root);
                    break;

           case 12: print(root);
                    printf("Is the tree is BST : %d\n",isBST(root,-1000,1000));
                    break;

           case 13: print(root);
                    printf("Enter the no. of nodes\n");
                    scanf("%d",&data);
                    printf("Possible no. of unique trees with %d nodes(catalan no.)= %d\n",data,catalan_no(data));
                    break;

          case 14: print(root);
                   printf("Enter the ith max\n");
                    scanf("%d",&data);
                    printf("The ith max element is = %d\n",(nth_max(root,data)->data));
                    break;
           case 15: print(root);
                    printf("Enter the value of nodes for which to find LCA\n");
                    scanf("%d %d",&a, &b);
                    printf("LCA of %d and %d is= %d\n",a,b,lca(root,a,b)->data);
                    break;

           case 16: return 0;
        }
         printf("choose a option\n1.Insert\n2.print kth node\n3.sum\n4.height\n5.Diameter\n6.No_of_Leaves\n7.tree2list\n8.HAs_PAth_SUM\n9.mirror\n10.isIsomorphic\n11.double tree\n12.isBST\n13.catalan_number\n14.\n15.To get LCA\n16.quit\nEnter the option");
         scanf("%d",&i);
    }

    return 0;
}
