class Solution {
public:
    int totalNQueens(int n) {
        int ans=0;
        memset(y,0,sizeof(y));
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        dfs(n,0,ans);
        return ans;
    }
private:
    bool y[100],l[100],r[100];
    void dfs(int n,int o,int &ans)
    {
        if (o==n) {ans++;return;}
        for (int i=0;i<n;i++)
        if ((!y[i])&&(!l[i+o])&&(!r[i-o+n-1]))
        {
            y[i]=l[i+o]=r[i-o+n-1]=true;
            dfs(n,o+1,ans);
            y[i]=l[i+o]=r[i-o+n-1]=false;
        }
    }
};