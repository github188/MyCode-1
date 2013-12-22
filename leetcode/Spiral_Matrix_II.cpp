class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector< vector<int> > Ans;Ans.clear();
        vector<int> row;row.clear();
        if (n==0) return Ans;
        for (int i=0;i<n;i++) row.push_back(0);
        for (int i=0;i<n;i++) Ans.push_back(row);
        int x=0,y=0,z=0;
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                if (i+j!=n+n-2)
                {
                    Ans[x][y]=i*n+j+1;
                    while ((x+dx[z]<0)||(x+dx[z]>=n)||(y+dy[z]<0)||(y+dy[z]>=n)||(Ans[x+dx[z]][y+dy[z]]!=0)) z=(z+1)%4;
                    x+=dx[z];y+=dy[z];
                }
        Ans[x][y]=n*n;
        return Ans;
    }
};
