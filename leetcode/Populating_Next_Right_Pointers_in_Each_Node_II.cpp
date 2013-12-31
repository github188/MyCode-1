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
    void dfs(TreeLinkNode *root,vector<TreeLinkNode *> *right_node,int depth)
    {
        if (root==NULL) return;
        if (right_node->size()<=depth)
        {
            right_node->push_back(root);
        } else
        {
            (*right_node)[depth]->next=root;
            (*right_node)[depth]=root;
        }
        dfs(root->left,right_node,depth+1);
        dfs(root->right,right_node,depth+1);
    }
    void connect(TreeLinkNode *root) {
       vector<TreeLinkNode *> right_node;
       right_node.clear();
       dfs(root,&right_node,0);
    }
};