/*
Maintain the longest substring without repeating characters from the current position.
*/
class Solution {
public:
    int num[1000];
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if (n==0) return 0;
        for (int i=0;i<256;i++) num[i]=0;
        int ans=1,head=0;
        num[s[0]]=1;
        for (int i=1;i<n;i++)
        {
            num[s[i]]++;
            while (num[s[i]]>1) num[s[head++]]--;
            ans=(ans>i-head+1?ans:i-head+1);
        }
        return ans;
    }
};