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
    void dfs(vector<vector<int> > *Ans,TreeNode *root,int depth)
    {
        if (root==NULL) return;
        if (Ans->size()<=depth)
        {
            vector<int> tmp;tmp.clear();
            Ans->push_back(tmp);
        }
        (*Ans)[depth].push_back(root->val);
        dfs(Ans,root->left,depth+1);
        dfs(Ans,root->right,depth+1);
    }
    
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > Ans;Ans.clear();
        dfs(&Ans,root,0);
        return Ans;
    }
};