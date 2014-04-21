class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ans;ans.clear();
        memset(y,0,sizeof(y));
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        dfs(n,0,&ans);
        return ans;
    }
private:
    bool y[100],l[100],r[100];
    int y_ans[100];
    void dfs(int n,int o,vector<vector<string> > *ans)
    {
        if (o==n) 
        {
            vector<string> rows;rows.clear();
            string s="";
            for (int i=0;i<n;i++) s+=".";
            for (int i=0;i<n;i++) 
            {
                rows.push_back(s);
                rows[i][y_ans[i]]='Q';
            }
            ans->push_back(rows);
            return;
        }
        for (int i=0;i<n;i++)
        if ((!y[i])&&(!l[i+o])&&(!r[i-o+n-1]))
        {
            y[i]=l[i+o]=r[i-o+n-1]=true;
            y_ans[o]=i;
            dfs(n,o+1,ans);
            y[i]=l[i+o]=r[i-o+n-1]=false;
        }
    }
};