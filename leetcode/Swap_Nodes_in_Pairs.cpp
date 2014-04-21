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
    ListNode *swapPairs(ListNode *head) {
        if ((head==NULL)||(head->next==NULL)) return head;
        ListNode *ans=head->next,*temp=ans->next;
        ans->next=head;head->next=temp;
        ListNode *h=head;
        while (h!=NULL)
        {
            if ((h->next==NULL)||(h->next->next==NULL)) break;
            ListNode* temp=h->next;
            h->next=h->next->next;
            temp->next=h->next->next;
            h->next->next=temp;
            h=temp;
        }
        return ans;
    }
};