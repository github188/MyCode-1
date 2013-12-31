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
    void dfs(TreeNode *root,int &Ans,int sum)
    {
        if (root==NULL) return;
        sum=sum*10+root->val;
        if ((root->left==NULL)&&(root->right==NULL))
        {
            Ans+=sum;
            return;
        }
        dfs(root->left,Ans,sum);
        dfs(root->right,Ans,sum);
    }
    int sumNumbers(TreeNode *root) {
        int Ans=0;
        if (root!=NULL) dfs(root,Ans,0);
        return Ans;
    }
};
