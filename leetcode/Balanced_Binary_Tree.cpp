/*
Just check it.
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
    stack<int> Mid;
    Solution() {while (Mid.size()>0) Mid.pop();}
    bool isBalanced(TreeNode *root) {
        if (root==NULL) {Mid.push(0);return true;}
        if (isBalanced(root->left)&isBalanced(root->right))
        {
            int r=Mid.top();Mid.pop();
            int l=Mid.top();Mid.pop();
            if (l>r) {int tmp=l;l=r;r=tmp;}
            if (r-l>1) return false;
            Mid.push(r+1);
            return true;
        }
        return false;
    }
};