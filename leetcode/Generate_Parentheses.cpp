class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;ans.clear();
        dfs("",n,0,&ans);
        return ans;
    }
private:
    void dfs(string s,int n,int o,vector<string> *ans)
    {
        if ((n==0)&&(o==0)) {ans->push_back(s);return;}
        if (n>0) dfs(s+'(',n-1,o+1,ans);
        if (o>0) dfs(s+')',n,o-1,ans);
    }
};