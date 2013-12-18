/*
Two binary searches.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int l,r;
        l=0;r=n-1;
        while (l<r)
        {
            int mid=(l+r)/2+1;
            if (matrix[mid][0]==target) return true;
            if (matrix[mid][0]>target) r=mid-1; else l=mid;
        }
        int index=l;
        l=0;r=m-1;
        while (l<r)
        {
            int mid=(l+r)/2+1;
            if (matrix[index][mid]==target) return true;
            if (matrix[index][mid]>target) r=mid-1; else l=mid;
        }
        if (matrix[index][l]==target) return true;return false;
    }
};