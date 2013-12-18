/*
Cut the list from the middle.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    int N;
    TreeNode *buildTree(ListNode *head,int n)
    {
        if (n==0) return NULL;
        ListNode* h=head;
        for (int i=0;i<n/2;i++) h=h->next;
        TreeNode *root=new TreeNode(h->val);
        root->left = buildTree(head,n/2);
        root->right = buildTree(h->next,n-n/2-1);
        return root;
    }
    
    TreeNode *sortedListToBST(ListNode *head) {
        ListNode* h=head;N=0;
        while (h!=NULL) {N++;h=h->next;}
        if (N==0) return NULL;
        return buildTree(head,N);
    }
};