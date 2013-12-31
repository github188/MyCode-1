/*
Maintain the Nth and N+1th pointer from the end of the list.
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *nth=NULL,*np1th=NULL,*h=head;
        while (h!=NULL)
        {
            n--;
            if (n==0) nth=head;
            if (n==-1) np1th=head,nth=np1th->next;
            if (n<-1) nth=nth->next,np1th=np1th->next;
            h=h->next;
        }
        if (np1th==NULL) head=head->next;
        else np1th->next=nth->next;
        return head;
    }
};
