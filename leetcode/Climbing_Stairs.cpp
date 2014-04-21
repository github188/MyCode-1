class Solution {
public:
    void pow_mat(int n,int a[][2],int b[][2])
    {
        if (n==1)
        {
            b[0][0]=a[0][0];
            b[0][1]=a[0][1];
            b[1][0]=a[1][0];
            b[1][1]=a[1][1];
            return;
        }
        pow_mat(n/2,a,b);
        int c[2][2];
        for (int i=0;i<2;i++) for (int j=0;j<2;j++) c[i][j]=0;
        for (int i=0;i<2;i++)
            for (int j=0;j<2;j++)
                for (int k=0;k<2;k++) c[i][j]+=b[i][k]*b[k][j];
        for (int i=0;i<2;i++) for (int j=0;j<2;j++) b[i][j]=c[i][j];
        if (n&1)
        {
            for (int i=0;i<2;i++) for (int j=0;j<2;j++) c[i][j]=0;
            for (int i=0;i<2;i++)
                for (int j=0;j<2;j++)
                    for (int k=0;k<2;k++) c[i][j]+=a[i][k]*b[k][j];
            for (int i=0;i<2;i++) for (int j=0;j<2;j++) b[i][j]=c[i][j];
        }
    }
    int climbStairs(int n) {
        if (n<2) return 1;
        int a[2][2];
        a[0][0]=0;a[0][1]=1;
        a[1][0]=1;a[1][1]=1;
        int b[2][2];
        pow_mat(n-1,a,b);
        return b[0][1]+b[1][1];
    }
};