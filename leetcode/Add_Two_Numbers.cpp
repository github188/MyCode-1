/*
List add list.
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *Ans;Ans=NULL;ListNode *a;
        int plus=0;
        while ((l1!=NULL)||(l2!=NULL))
        {
            if (Ans==NULL)
            {
                Ans=new ListNode(0);
                a=Ans;
            } else
            {
                a->next=new ListNode(0);
                a=a->next;
            }
            int x=0,y=0;
            if (l1!=NULL)
            {
                x=l1->val;
                l1=l1->next;
            }
            if (l2!=NULL)
            {
                y=l2->val;
                l2=l2->next;
            }
            x+=y+plus;
            if (x>9) {plus=1;x-=10;} else plus=0;
            a->val=x;
        }
        if (plus) a->next=new ListNode(1);
        return Ans;
    }
};
