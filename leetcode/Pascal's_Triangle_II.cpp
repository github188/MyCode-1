class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;ans.clear();ans.push_back(1);
        for (int i=1;i<=rowIndex;i++)
        {
            long long x=(long long)ans[i-1]*(long long)(rowIndex-i+1)/(long long)i;
            ans.push_back(x);
        }
        return ans;
    }
};