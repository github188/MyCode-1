/*
DFS.
*/
class Solution {
public:
    void dfs(vector<vector<int> > *Ans,vector<int> *candidates,int n,int target,int pos,vector<int> *tmp)
    {
        if (target==0)
        {
            Ans->push_back(*tmp);
            return;
        }
        if ((*candidates)[pos]>target) return;
        for (int i=pos;i<n;i++)
        {
            tmp->push_back((*candidates)[i]);
            dfs(Ans,candidates,n,target-(*candidates)[i],i,tmp);
            tmp->pop_back();
        }
    }
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > Ans;Ans.clear();
        vector<int> tmp;tmp.clear();
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        dfs(&Ans,&candidates,n,target,0,&tmp);
        return Ans;
    }
};