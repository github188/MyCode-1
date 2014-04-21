class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ans;ans.clear();
        sort(num.begin(),num.end());
        dfs(num,0,num.size(),&ans);
        return ans;
    }
private:
    void dfs(vector<int> num,int o,int n,vector<vector<int> > *ans)
    {
        if (o==n) {ans->push_back(num);return;}
        for (int k=o;k<n;k++)
        {
            int l=num[o];num[o]=num[k];num[k]=l;
            dfs(num,o+1,n,ans);
            l=num[o];num[o]=num[k];num[k]=l;
        }
    }
};