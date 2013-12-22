/*
The last char maybe space.
*/
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int n=strlen(s),cur=0,ans=0;
        for (int i=0;i<n;i++)
        {
            if (s[i]==' ') cur=0; else ans=++cur;

        }
        return ans;
    }
};
