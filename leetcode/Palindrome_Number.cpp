/*
Just check it.Attention to the negative.
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        if (x==0) return true;
        vector<char> num;num.clear();
        while (x>0)
        {
            num.push_back(x%10);x/=10;
        }
        int n=num.size();
        for (int i=0;i<n/2;i++) if (num[i]!=num[n-1-i]) return false;
        return true;
    }
};