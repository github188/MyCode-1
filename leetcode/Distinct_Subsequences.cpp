/*
DP.
*/
class Solution {
public:
    int numDistinct(string S, string T) {
        int n=S.size(),m=T.size();
        vector<vector<int> > f;f.clear();
        vector<int> row;row.clear();
        for (int i=0;i<=m;i++) row.push_back(0);
        for (int i=0;i<=n;i++) f.push_back(row);
        if (n<m) return 0;
        for (int i=1;i<=n;i++)
        {
            f[i][1]=f[i-1][1];
            if (S[i-1]==T[0]) f[i][1]++;
        }
        for (int i=2;i<=n;i++)
            for (int j=2;j<=m;j++)
            {
                f[i][j]=f[i-1][j];
                if (S[i-1]==T[j-1]) f[i][j]+=f[i-1][j-1];
            }
        return f[n][m];
    }
};
