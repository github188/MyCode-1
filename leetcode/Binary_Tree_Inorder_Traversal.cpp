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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> left,right,ans;ans.clear();
        if (root==NULL) return ans;
        if (root->left!=NULL)
        {
            left=inorderTraversal(root->left);
            for (int i=0;i<left.size();i++) ans.push_back(left[i]);
        }
        ans.push_back(root->val);
        if (root->right!=NULL)
        {
            right=inorderTraversal(root->right);
            for (int i=0;i<right.size();i++) ans.push_back(right[i]);
        }
        return ans;
    }
};