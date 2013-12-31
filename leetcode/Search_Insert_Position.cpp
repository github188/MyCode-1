/*
Binary Search.
*/
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (n==0) return 0;
        if (target<=A[0]) return 0;
        if (target>A[n-1]) return n;
        if (target==A[n-1]) return n-1;
        int l=0,r=n-1;
        while (l<r)
        {
            int mid=(l+r)/2+1;
            if (A[mid]<=target) l=mid; else r=mid-1;
        }
        if (A[l]==target) return l;return l+1;
    }
};