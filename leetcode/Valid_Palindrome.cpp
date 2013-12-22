/*
Just check it.
*/
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length()==0) return true;
        string t="";int n=s.length();
        for (int i=0;i<n;i++)
        {
            if ((s[i]>='A')&&(s[i]<='Z')) t+=(char)s[i]-'A'+'a';
            if ((s[i]>='a')&&(s[i]<='z')) t+=(char)s[i];
            if ((s[i]>='0')&&(s[i]<='9')) t+=(char)s[i];
        }
        n=t.length();
        for (int i=0;i<n/2;i++) if (t[i]!=t[n-i-1]) return false;
        return true;
    }
};
