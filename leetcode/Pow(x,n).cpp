class Solution {
public:
    double pow_pos(double x, int n) {
        if (n==0) return 1;
        if (n==1) return x;
        double ans=pow_pos(x,n/2);
        ans*=ans;
        if  (n&1) ans*=x;
        return ans;
    }
    double pow(double x, int n) {
        double ans=0;
        int m=1;if (n<0) {m=-1,n=-n;}
        ans=pow_pos(x,n);
        if (m<0) ans=1/ans;
        return ans;
    }
};