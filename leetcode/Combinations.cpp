class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;ans.clear();
        vector<int> temp;temp.clear();
        dfs(&temp,n,1,k,&ans);
        return ans;
    }
    
    void dfs(vector<int> *temp,int n,int o,int k,vector<vector<int> > *ans)
    {
        if (k==0) {ans->push_back(*temp);return;}
        if (n-o>=k) dfs(temp,n,o+1,k,ans);
        temp->push_back(o);
        dfs(temp,n,o+1,k-1,ans);
        temp->pop_back();
    }
};