#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int dp[201][201][202];
int a[205];
int n, T;

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while (T--)
    {
        int m = 0,_n = 0;
        scanf("%d", &n);
        for (int k = 1; k <= n; k++)
            scanf("%d", a + k);
        for (int k = 1; k <= n; k++)
            a[k] -= 50, m = max(m, a[k]);
        for (int i=0;i<=n;i++) for (int j=0;j<=n;j++) for (int k=0;k<=m;k++) dp[i][j][k]=0;
        for (int l = n + 1; l >= 1; l--)
            for (int r = l - 1;  r <= n; r++)
                for (int h = m; h >= 0; h--)
                {
                    if (l == r + 1) { dp[l][r][h] = 0; continue;};
                    if (l == r)
                    {
                        if (h <= a[l]) dp[l][r][h] = 1;
                        else dp[l][r][h] = 0;
                        continue;
                    }
                    dp[l][r][h] = max(dp[l][r][h], dp[l][r][h + 1]);
                    dp[l][r][h] = max(dp[l][r][h], dp[l + 1][r][h]);
                    dp[l][r][h] = max(dp[l][r][h], dp[l][r - 1][h]);
                    if (a[l] >= h && a[l] == a[r])
                        dp[l][r][h] = max(dp[l][r][h], dp[l + 1][r - 1][h + 1] + 2);
                    if (a[l]==a[r]) dp[l][r][h]=max(2,dp[l][r][h]);
                }
       printf("%d\n", dp[1][n][0]);
    }
    return 0;
}
