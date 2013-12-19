/*
Permulation index is the n!-based number.
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        int a[10];
        a[1]=1;
        for (int i=2;i<=n;i++) a[i]=a[i-1]*i;
        bool unused[10];
        string ans;ans.clear();
        for (int i=1;i<=n;i++) {unused[i]=true;ans+=' ';}
        for (int i=0;i<n;i++)
        {
            int l=0;
            if (i!=n-1) while (a[n-i-1]<k) k-=a[n-i-1],l++;
            int j=1;
            while (j<10)
            {
                if (unused[j]) {if (l==0) break;l--;}
                j++;
            }
            ans[i]='0'+j;
            unused[j]=false;
        }
        return ans;
    }
};