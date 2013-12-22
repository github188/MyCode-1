/*
Min(a[i-1][j],a[i][j-1])+a[i][j]
*/
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int n=grid.size();
        if (n==0) return 0;
        int m=grid[0].size();
        if (m==0) return 0;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
            {
                int x=std::numeric_limits<int>::max(),y=std::numeric_limits<int>::max();
                if (i>0) x=grid[i-1][j];
                if (j>0) y=grid[i][j-1];
                if (min(x,y)<std::numeric_limits<int>::max()) grid[i][j]+=min(x,y);
            }
        return grid[n-1][m-1];
    }
};
