class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ans;ans.clear();
        vector<int> temp;temp.clear();
        sort(S.begin(),S.end());
        dfs(S,S.size(),0,&ans,&temp);
        return ans;
    }
private:
    void dfs(vector<int> s,int n,int o,vector<vector<int> > *ans,vector<int> *temp)
    {
        if (n==o) {ans->push_back(*temp);return;}
        dfs(s,n,o+1,ans,temp);
        temp->push_back(s[o]);
        dfs(s,n,o+1,ans,temp);
        temp->pop_back();
    }
};