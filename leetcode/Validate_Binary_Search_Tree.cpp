/*
Just check it.
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
    bool dfs(TreeNode *root,int min,int max)
    {
        if (root==NULL) return true;
        if ((root->val<=min)||(root->val>=max)) return false;
        bool Ans=true;
        if (root->left!=NULL) 
        {
            if (root->val <= root->left->val) Ans = false;
            Ans&=dfs(root->left,min,root->val);
        }
        if (root->right!=NULL) 
        {
            if (root->val >= root->right->val) Ans = false;
            Ans&=dfs(root->right,root->val,max);
        }
        return Ans;
    }
    bool isValidBST(TreeNode *root) {
        return dfs(root,numeric_limits<int>::min(),numeric_limits<int>::max());
    }
};