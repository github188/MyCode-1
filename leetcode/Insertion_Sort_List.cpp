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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *h=head;
        if (h==NULL) return h;
        h=h->next;
        while (h!=NULL)
        {
            ListNode *head1=head,*cur=h;h=h->next;
            if (cur->val<head1->val)
            {
                head=cur;
                cur->next=head1;
                while (head1->next!=cur) head1=head1->next;
                head1->next=h;
                continue;
            }
            while (head1->next->val<cur->val) head1=head1->next;
            if (head1->next!=cur)
            {
                cur->next=head1->next;
                head1->next=cur;head1=head1->next;
                while (head1->next!=cur) head1=head1->next;
                head1->next=h;
            }
        }
        return head;
    }
};