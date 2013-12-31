/*
Be careful the detail.
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool f[10];
        for (int i=0;i<9;i++)
        {
            for (int j=1;j<10;j++) f[j]=false;
            for (int j=0;j<9;j++)
            {
                if (board[i][j]!='.')
                if (f[board[i][j]-'0']) return false;
                else f[board[i][j]-'0']=true;
            }
        }
        for (int i=0;i<9;i++)
        {
            for (int j=1;j<10;j++) f[j]=false;
            for (int j=0;j<9;j++)
            {
                if (board[j][i]!='.')
                if (f[board[j][i]-'0']) return false;
                else f[board[j][i]-'0']=true;
            }
        }
        for (int i=0;i<9;i++)
        {
            int x=i/3*3,y=i%3*3;
            for (int j=1;j<10;j++) f[j]=false;
            for (int j=0;j<9;j++)
            {
                int u=j/3,v=j%3;
                if (board[x+u][y+v]!='.')
                if (f[board[x+u][y+v]-'0']) return false;
                else f[board[x+u][y+v]-'0']=true;
            }
        }
        return true;
    }
};