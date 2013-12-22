/*
DFS. Record the tail node.
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
    TreeNode *CurNode=NULL;
    void flatten(TreeNode *root) {
        if (root==NULL) return;
        CurNode=root;
        TreeNode *left=root->left;
        TreeNode *right=root->right;
        if ((left==NULL)&&(right==NULL)) return;
        root->left=NULL;
        root->right=left;
        if (left!=NULL) flatten(left);
        CurNode->right=right;
        if (right!=NULL) flatten(right);
    }
};