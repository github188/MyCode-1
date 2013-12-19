/*
The number of ones in each digits is 3k or 3k+1, and the 3k+1 ones can build the only one number.
*/
class Solution {
public:
    int singleNumber(int A[], int n) {
        int ans=0;
        for (int i=0;i<32;i++)
        {
            int sum=0;
            for (int j=0;j<n;j++) if (A[j]&(1<<i)) sum++;
            ans|=(sum%3)<<i;
        }
        return ans;
    }
};