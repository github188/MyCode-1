/*
Stack. Scanning after match the parentheses
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> left;
        while (left.size()>0) left.pop();
        int n=s.size(),ans=0,cur=0,leftnum=0;
        for (int i=0;i<n;i++)
        {
            if (s[i]=='(') left.push(i);
            else
            {
                if (left.size()>0)
                {
                    s[i]='*';
                    s[left.top()]='*';
                    left.pop();
                }
            }
        }
        int i=0;
        while (i<n)
        {
            int j=i;
            while ((j<n)&&(s[j]==s[i])&&(s[j]=='*')) j++;
            ans=ans>j-i?ans:j-i;
            i=(j>i)?j:i+1;
        }
        return ans;
    }
};
