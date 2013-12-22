/*
C(m+n-2,n-1).
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        m--;n--;
        if ((n<=0)||(m<=0)) return 1;
        int d[200];for (int i=1;i<200;i++) d[i]=0;
        int x=m+n,y=n;
        for (int i=0;i<n;i++)
        {
            int k=x;
            while ((k>1)&&((k%2)==0)) {k/=2;d[2]++;}
            while ((k>1)&&((k%3)==0)) {k/=3;d[3]++;}
            while ((k>1)&&((k%5)==0)) {k/=5;d[5]++;}
            while ((k>1)&&((k%7)==0)) {k/=7;d[7]++;}
            while ((k>1)&&((k%11)==0)) {k/=11;d[11]++;}
            while ((k>1)&&((k%13)==0)) {k/=13;d[13]++;}
            if (k>1) d[k]++;
            k=y;
            while ((k>1)&&((k%2)==0)) {k/=2;d[2]--;}
            while ((k>1)&&((k%3)==0)) {k/=3;d[3]--;}
            while ((k>1)&&((k%5)==0)) {k/=5;d[5]--;}
            while ((k>1)&&((k%7)==0)) {k/=7;d[7]--;}
            while ((k>1)&&((k%11)==0)) {k/=11;d[11]--;}
            while ((k>1)&&((k%13)==0)) {k/=13;d[13]--;}
            if (k>1) d[k]--;
            x--;y--;
        }
        int ans=1;
        for (int i=1;i<200;i++)
        {
            while (d[i]) ans*=i,d[i]--;
        }
        return ans;
    }
};
