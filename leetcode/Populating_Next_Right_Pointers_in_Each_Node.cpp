/*
Solve the problem in subtrees, then connect the rightest nodes in left subtree to the leftest nodes in the right subtree.
*/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    int depth=0;
    void lefttoright(TreeLinkNode *right,TreeLinkNode *left)
    {
        if (right==NULL) return;
        right->next=left;
        if (left!=NULL) left=left->left;
        lefttoright(right->right,left);
    }
    void connect(TreeLinkNode *root) {
        if (root==NULL) return;
        depth++;
        connect(root->left);
        connect(root->right);
        lefttoright(root->left,root->right);
        depth--;
        if (depth==0) lefttoright(root,NULL);
    }
};