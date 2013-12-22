/*
Just scanning.
*/
class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n==0) return 0;
        int sum=A[0],minus=0,ans=A[0];
        if (sum<0) {minus=A[0];}
        for (int i=1;i<n;i++)
        {
            if (ans<0) ans=ans>A[i]?ans:A[i];
            sum+=A[i];
            if (sum<minus) {minus=sum;}
            else ans=ans>sum-minus?ans:sum-minus;
        }
        return ans;
    }
};
