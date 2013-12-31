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
    void dfs(TreeNode *root,vector<vector<int> > *Ans,int depth)
    {
        if (root==NULL) return;
        if (Ans->size()<=depth)
        {
            vector<int> tmp;tmp.clear();
            Ans->push_back(tmp);
        }
        (*Ans)[depth].push_back(root->val);
        dfs(root->left,Ans,depth+1);
        dfs(root->right,Ans,depth+1);
    }
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > Ans;Ans.clear();
        dfs(root,&Ans,0);
        reverse(Ans.begin(),Ans.end());
        return Ans;
    }
};
