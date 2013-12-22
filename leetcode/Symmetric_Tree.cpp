/*
The left subtrees right node must equl the right subtrees left node.
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
    bool Check(TreeNode *left,TreeNode *right)
    {
        if (left==NULL)
        {
            if (right==NULL) return true;
            return false;
        }
        if (right==NULL) return false;
        if (left->val!=right->val) return false;
        return (Check(left->left,right->right)&Check(left->right,right->left));
    }

    bool isSymmetric(TreeNode *root) {
        return Check(root,root);
    }
};