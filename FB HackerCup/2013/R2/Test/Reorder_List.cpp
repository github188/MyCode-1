/*
Recurition.
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
    ListNode* work(ListNode* head,int l,int r)
    {
        if (l==r)
        {
            ListNode* Ans=head->next;
            head->next=NULL;
            return Ans;
        }
        if (l+1==r) {ListNode* Ans=head->next->next;head->next->next=NULL;return Ans;}
        ListNode* tmp=head->next;
        head->next=work(head->next,l+1,r-1);
        ListNode* ans=head->next->next;
        head->next->next=tmp;
        return ans;
    }
    void reorderList(ListNode *head) {
        if (head==NULL) return;
        int n=0;
        ListNode* h=head;
        while (h!=NULL) {n++;h=h->next;}
        work(head,1,n);
    }
};
