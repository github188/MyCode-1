/*
DP can get the palindrom_substring. The DFS it.
*/
class Solution {
public:
    void dfs(vector<vector<string>> *Ans,vector<vector<string>> *palset,int pos,int n,vector<string> *row)
    {
        if (pos>=n)
        {
            Ans->push_back(*row);
            return;
        }
        int m=(*palset)[pos].size();
        for (int i=0;i<m;i++)
        {
            row->push_back((*palset)[pos][i]);
            dfs(Ans,palset,pos+(*palset)[pos][i].length(),n,row);
            row->pop_back();
        }
    }

    vector<vector<string> > partition(string s) {
        int n=s.length();
        vector<vector<string> >Ans;Ans.clear();
        if (n==0) return Ans;
        if (n==1)
        {
            vector<string> tmp;tmp.clear();tmp.push_back(s);
            Ans.push_back(tmp);
            return Ans;
        }
        vector<vector<bool> >f;f.clear();
        vector<bool> g;g.clear();
        for (int i=0;i<n;i++) g.push_back(false);
        for (int i=0;i<n;i++) f.push_back(g);
        for (int i=0;i<n;i++) f[i][i]=true;
        for (int i=1;i<n;i++) if (s[i]==s[i-1]) f[i-1][i]=true;
        for (int i=3;i<=n;i++)
            for (int j=0;j<n-i+1;j++)
            if ((f[j+1][j+i-2])&&(s[j]==s[j+i-1])) f[j][j+i-1]=true;
        vector<vector<string> > palset;palset.clear();
        vector<string> row;row.clear();
        for (int i=0;i<n;i++) palset.push_back(row);
        for (int i=0;i<n;i++)
        {
            string t="";
            for (int j=i;j<n;j++)
            {
                t+=s[j];
                if (f[i][j]) palset[i].push_back(t);
            }
        }
        dfs(&Ans,&palset,0,n,&row);
        return Ans;
    }
};
