class Solution {
public:
    int reverse(int x) {
        long long sign=1;if (x<0) {sign=-1;x=-x;}
        long long ans=0;
        while (x) ans=ans*(long long)10+(long long)(x%10),x/=10;
        return sign*ans;
    }
};