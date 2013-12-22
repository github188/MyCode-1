/*
Calculate the rotation position.
*/
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n=matrix.size();
        if (n<2) return;
        int x=n/2+(n&1),y=n/2;
        for (int i=0;i<x;i++)
            for (int j=0;j<y;j++)
            {
                int dx[4],dy[4];
                dx[0]=i;dy[0]=j;
                dx[1]=j;dy[1]=n-1-i;
                dx[2]=n-1-i;dy[2]=n-1-j;
                dx[3]=n-1-j;dy[3]=i;
                int tmp=matrix[dx[3]][dy[3]];
                matrix[dx[3]][dy[3]]=matrix[dx[2]][dy[2]];
                matrix[dx[2]][dy[2]]=matrix[dx[1]][dy[1]];
                matrix[dx[1]][dy[1]]=matrix[dx[0]][dy[0]];
                matrix[dx[0]][dy[0]]=tmp;
            }
    }
};
