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
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> temp;
        while (temp.size()) temp.pop();
        temp.push(root);
        vector<int> ans;ans.clear();
        if (root==NULL) return ans;
        while (temp.size())
        {
            TreeNode *X=temp.top();temp.pop();
            if (X->left!=NULL)
            {
                TreeNode *l=X->left;
                X->left=NULL;
                temp.push(X);
                temp.push(l);
            } else
            if (X->right!=NULL)
            {
                TreeNode *r=X->right;
                X->right=NULL;
                temp.push(X);
                temp.push(r);
            } else
            {
                ans.push_back(X->val);
            }
        }
        return ans;
    }
};