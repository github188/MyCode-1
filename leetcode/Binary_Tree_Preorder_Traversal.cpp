/*
Use the stack as the recur.
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
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> unused;
        while (unused.size()) unused.pop();
        vector<int> Ans;Ans.clear();
        if (root==NULL) return Ans;
        unused.push(root);
        while (unused.size()>0)
        {
            TreeNode *tmp=unused.top();unused.pop();
            Ans.push_back(tmp->val);
            if (tmp->right!=NULL) unused.push(tmp->right);
            if (tmp->left!=NULL) unused.push(tmp->left);
        }
        return Ans;
    }
};
