/*
Record the first one.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head==NULL) return head;
        ListNode* h=head;
        while (h!=NULL)
        {
            ListNode* f=h;
            while ((h->next!=NULL)&&(h->next->val==h->val)) h=h->next;
            f->next=h->next;
            h=f->next;
        }
        return head;
    }
};
