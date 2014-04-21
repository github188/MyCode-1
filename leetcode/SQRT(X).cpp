class Solution {
public:
    int sqrt(int x) {
        long long x1=x,l=0,r=x;
        while (l<r)
        {
            long long mid=(l+r)/2+1;
            if (mid*mid<=x1) l=mid; else r=mid-1;
        }
        return (int)l;
    }
};