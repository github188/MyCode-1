/*
Pointer operation.
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void work(TreeNode* Node,vector<int> *preorder, int l,int r, vector<int> *inorder,int x,int y)
    {
        int pos;
        for (pos=x;pos<=y;pos++) if ((*inorder)[pos]==(*preorder)[l]) break;
        if (pos-x>0)
        {
            Node->left=new TreeNode((*preorder)[l+1]);
            work(Node->left,preorder,l+1,l+pos-x,inorder,x,pos-1);
        }
        if (y-pos>0)
        {
            Node->right=new TreeNode((*preorder)[l+1+pos-x]);
            work(Node->right,preorder,l+1+pos-x,r,inorder,pos+1,y);
        }
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size()==0) {return NULL;}
        TreeNode *tree = new TreeNode(preorder[0]);
        work(tree,&preorder,0,preorder.size()-1,&inorder,0,inorder.size()-1);
        return tree;
    }
};
