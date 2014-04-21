class Solution {
public:
    bool canJump(int A[], int n) {
        int len=0;
        for (int i=0;i<n;i++)
        {
            if (len<i) return false;
            if (i+A[i]>len) len=i+A[i];
        }
        return true;
    }
};