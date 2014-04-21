class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans;ans.clear();
        if (numRows<=0) return ans;
        vector<int> row;row.clear();
        ans.push_back(row);ans[0].push_back(1);
        for (int i=2;i<=numRows;i++)
        {
            ans.push_back(row);
            for (int j=0;j<i;j++)
            {
                int x=0;
                if (j>0) x+=ans[i-2][j-1];
                if (j<i-1) x+=ans[i-2][j];
                ans[i-1].push_back(x);
            }
        }
        return ans;
    }
};