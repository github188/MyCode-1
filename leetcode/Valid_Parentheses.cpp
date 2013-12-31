/*
Scanning.
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> c;
        int n=s.length();
        for (int i=0;i<n;i++)
        {
            if (s[i]=='(') c.push(s[i]);
            if (s[i]=='[') c.push(s[i]);
            if (s[i]=='{') c.push(s[i]);
            if (s[i]==')')
            {
                if ((c.size()==0)||(c.top()!='(')) return false;
                c.pop();
            }
            if (s[i]=='}')
            {
                if ((c.size()==0)||(c.top()!='{')) return false;
                c.pop();
            }
            if (s[i]==']')
            {
                if ((c.size()==0)||(c.top()!='[')) return false;
                c.pop();
            }
        }
        if (c.size()>0) return false;
        return true;
    }
};