/*
DFS.
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
    int Ans=1e9;
    void dfs(TreeNode *root,int depth)
    {
        if (root==NULL) return;
        if ((root->left==NULL)&&(root->right==NULL)) Ans=Ans<depth?Ans:depth;
        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
    }
    int minDepth(TreeNode *root) {
        if (root==NULL) return 0;
        dfs(root,1);
        return Ans;
    }
};