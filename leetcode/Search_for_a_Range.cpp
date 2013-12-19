/*
Binary Search.
*/
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> Ans;Ans.clear();
        Ans.push_back(-1);
        Ans.push_back(-1);
        int l=0,r=n-1;
        while (l<r)
        {
            int mid=(l+r)/2;
            if (A[mid]<target) l=mid+1; else r=mid;
        }
        if (A[l]!=target) return Ans;
        Ans[0]=Ans[1]=l;
        r=n-1;
        while (l<r)
        {
            int mid=(l+r)/2+1;
            if (A[mid]<=target) l=mid; else r=mid-1;
        }
        while (A[l]>target) l--;
        Ans[1]=l;
        return Ans;
    }
};