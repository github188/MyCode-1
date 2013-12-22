#include<stdlib.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(){};
     ListNode(int x) : val(x), next(NULL) {}
 };
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
        head->next=work(head->next,l++,r--);
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
} a1;
int main()
{
    ListNode a,b,c;
    a.val=1;a.next=&b;
    b.val=2;b.next=&c;
    c.val=3;c.next=NULL;
    a1.reorderList(&a);
    return 0;
}
