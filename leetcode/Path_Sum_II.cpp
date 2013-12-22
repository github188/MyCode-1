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
    void dfs(TreeNode *root, int sum,vector<vector<int> > *Ans,vector<int> *Path)
    {
        if (root==NULL) return;
        sum-=root->val;
        Path->push_back(root->val);
        if ((root->left==NULL)&&(root->right==NULL))
        {
            if (sum==0) Ans->push_back(*Path);
            Path->pop_back();
            return;
        }
        dfs(root->left,sum,Ans,Path);
        dfs(root->right,sum,Ans,Path);
        Path->pop_back();
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > Ans;Ans.clear();
        vector<int> Path;Path.clear();
        if (root!=NULL) dfs(root,sum,&Ans,&Path);
        return Ans;
    }
};
