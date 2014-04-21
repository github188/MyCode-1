class Solution {
public:
    int numTrees(int n) {
        int ans=0;
        if (n==0) return 1;
        if (n<3) return n;
        for (int i=0;i<n;i++) ans+=numTrees(i)*numTrees(n-1-i);
        return ans;
    }
};