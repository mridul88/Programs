#include<cstdio>
#include<stack>
#include<vector>

using namespace std;

class Node
{
    int val;
    Node *right;
    Node *left;
    Node()
    {
        val =0;
        right = left = NULL;
    }
    friend class Tree;
};

class Tree   //a BST
{
private:
    Node *root;
    bool is_BST(Node* root, int min, int max)
    {
        if(!root)
            return true;
        if(root->val > max || root->val < min)
            return false;
        else
            return( is_BST(root->left,min, root->val) && is_BST(root->right, root->val, max) );
        return false;
    }

public:
    Tree()
    {
        root = NULL;
    }

    void Insert(int val)
    {
        Node *temp = this->root, *prev = NULL;
        Node *node = new Node();
        node->val = val;

        if(root==NULL)
        {
            this->root = node;
            return;
        }
        while(temp != NULL)
        {
            prev = temp;
            if(temp->val < val)
                temp = temp->right;
            else if(temp->val >= val)
                temp = temp->left;
        }

        if(prev->val < val)
                prev->right = node;
        else if(prev->val >= val)
               prev->left = node;

        return;
    }

    Node* get_root()
    {
        return root;
    }

    void print(Node *root)
    {
        if(!root)
        {
            printf("Empty Tree");
            return ;
        }
        printf("%d->",root->val);
        if(root->left!=NULL)
            print(root->left);
        if(root->right!=NULL)
            print(root->right);
        return ;
    }

    bool isBST(Node * root)
    {
        return is_BST(root,-9999999, 99999999);
    }
    

    void inorderTraversal(Node *root)
    {
        stack<Node*> s;
        if(!root)
            return;
        done = false;
        while(!done)
        {
            while(root!=NULL)
            {
                s.push(root);
                root = root->left;
            }
            if(!s.empty())
            {
                root = s.top();
                printf(" %d,",root->val);
                s.pop();

                root = root->right;
            }
            else
                done = true;
        }
        return;
    }

};


int main()
{
    int i,data,num=0,a,b;
    Tree *tree = new Tree();
    printf("choose a option\n1.Insert\n2.isBST?\n3.inorderTraversal\n4.height\n5.Diameter\n6.No_of_Leaves\n7.tree2list\n8.HAs_PAth_SUM\n9.mirror\n10.isIsomorphic\n11.double tree\n12.isBST\n13.catalan_no\n14.\n15.To get LCA\n16.quit\nEnter the option");
    scanf("%d",&i);
    while (i!=16)
    {
        switch (i)
        {

            case 1: printf("Enter the number in binary search tree\n");
                    scanf("%d",&data);
                    tree->Insert(data);
                    tree->print(tree->get_root());
                    break;

            case 2: printf("the tree is BST? - %d\n",tree->isBST(tree->get_root()));
                    break;

            case 3: tree->print(tree->get_root());
                    scanf("Inorder of this this tree is:-\n");
                    tree->inorderTraversal(tree->get_root());
                    break;
            /*
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
                    break; */

           case 16: return 0;
        }
         printf("choose a option\n1.Insert\n2.print kth node\n3.sum\n4.height\n5.Diameter\n6.No_of_Leaves\n7.tree2list\n8.HAs_PAth_SUM\n9.mirror\n10.isIsomorphic\n11.double tree\n12.isBST\n13.catalan_number\n14.\n15.To get LCA\n16.quit\nEnter the option");
         scanf("%d",&i);
    }

    return 0;
}

