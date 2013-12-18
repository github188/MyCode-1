/*
Record the key point. Reverse operation can be finished in the scanning.
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
    ListNode *md1th;
    ListNode *mth;
    ListNode *np1th = NULL;
    ListNode *nth;
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode* iter=head;
        ListNode* fa=NULL;
        for (int i=1;i<=n;i++)
        {
            if ((i+1==m)||(m==1))
            {
                if (m==1) {md1th=NULL;}
                else md1th=iter;
            }
            if (i==m) mth=iter;
            if (i==n) 
            {
                nth=iter;
                np1th=iter->next;
            }
            ListNode *tmp=iter->next;
            if (i>=m)   iter->next=fa;
            fa=iter;
            iter=tmp;
        }
        if (md1th==NULL) head=nth;
        else md1th->next=nth;
        mth->next=np1th;
        return head;
    }
};