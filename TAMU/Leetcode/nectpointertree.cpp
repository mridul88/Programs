/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode  *parent, *curr, *first, *prev;
        first = root;
        while(first!= NULL)
        {
            parent = first;
            prev = first = NULL;
            while(parent!= NULL)
            {
                if(parent->left!=NULL)
                {
                    curr = parent->left;
                    curr->next = NULL;
                    if(prev!=NULL)
                        prev->next = curr;
                    else
                        first = prev = curr;
                    prev = curr;
                }
                
                if(parent->right!=NULL)
                {
                    curr = parent->right;
                    curr->next = NULL;
                    if(prev!=NULL)
                        prev->next = curr;
                    else
                        first = prev = curr;
                    prev = curr;
                }
                parent = parent->next;
            }
        }
        return;
    }
};
