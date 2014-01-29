class  node
{
    int data;
    int succ;
    node left;
    node right;
}
public class kdistance
{
    static void printKDistant(node root , int k)
    {
        if(root == null)
            return;
        if( k == 0 )
        {
            System.out.println(  root.data );
            return ;
        }
        else
        {
            printKDistant( root.left, k-1 ) ;
            printKDistant( root.right, k-1 ) ;
        }
    }
    static node  newNode(int data)
    {
        node  node = new node();
        node.data = data;
        node.left = null;
        node.right = null;
        return(node);
    }


    public static void main(String[] args)
    {
        node  root = newNode(1);
        root.left        = newNode(2);
        root.right       = newNode(3);
        root.left.left  = newNode(4);
        root.left.right = newNode(5);
        root.right.left = newNode(8);
        printKDistant(root.left, 1);
        inorder(root);
    }
    static int inorder(node root)
    {
        if(root==null)
            return 100;
        if(root.left!=null)
            root.succ=inorder(root.left);
        System.out.println(  root.data+"    " +root.succ );
        if(root.right!=null)
            inorder(root.right);
        return root.data;


    }
}
