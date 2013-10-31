#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXN 100010
#define MAXM 35
using namespace std;
long long a[MAXN];
int N, mat[MAXM][MAXN], code[MAXM][MAXN], ans[MAXM], ans2[MAXM];
long long ans1;
inline void decode(int i)
{
    int j;
    long long x = a[i];
    for(j = 31; j >= 0; j --)
        code[j][i] = x & 1, x >>= 1;
}
void init()
{
    int i;
    for(i = 0; i < N; i ++)
    {
        scanf("%lld", &a[i]);
        decode(i);
    }
}
inline int gauss(int n)
{
    int i, j, k, x, y;
    for(i = j = 0; i <= n && j < N; i ++, j ++)
    {
        if(mat[i][j] == 0)
        {
            for(x = i + 1; x <= n; x ++)
                if(mat[x][j])
                {
                    for(y = j; y <= N; y ++)
                        swap(mat[i][y], mat[x][y]);
                    break;
                }
            if(x > n)
            {
                -- i;
                continue ;
            }
        }
        for(x = i + 1; x <= n; x ++)
            if(mat[x][j])
            {
                for(y = j; y <= N; y ++)
                    mat[x][y] ^= mat[i][y];
            }
    }
    for(k = i; k <= n; k ++)
        if(mat[k][N])
            return 0;
    return 1;
}
inline void solve()
{
    int i, j, k;
    long long res = 0;
    for(i = 0; i < 32; i ++)
    {
        ans[i] = 1;
        for(j = 0; j <= i; j ++)
        {
            for(k = 0; k < N; k ++)
                mat[j][k] = code[j][k];
            mat[j][N] = ans[j];
        }
        if(!gauss(i))
            ans[i] = 0;
    }
    for(i = 0; i < 32; i ++)
        res = (res << 1) | ans[i];
    ans1=res;
    printf("%lld ", res);
}
long long a2;
inline bool solve2(int o)
{
    int i, j, k;
    long long res = 0;
    for(i = 0; i < 32; i ++)
    if (i!=o)
    {
        ans2[i] = 1;
        for(j = 0; j <= i; j ++)
        {
            for(k = 0; k < N; k ++)
                mat[j][k] = code[j][k];
            mat[j][N] = ans2[j];
        }
        if(!gauss(i))
            ans2[i] = 0;
    } else
    {
        ans2[i] = 0;
        for(j = 0; j <= i; j ++)
        {
            for(k = 0; k < N; k ++)
                mat[j][k] = code[j][k];
            mat[j][N] = ans2[j];
        }
        if(!gauss(i)) return false;
    }
    for(i = 0; i < 32; i ++)
        res = (res << 1) | ans2[i];
    a2=res;
    return true;
    //printf("%lld ", res);
}

int main()
{
    scanf("%d", &N);
    init();
    solve();
    for (int i=31;i>=0;i--) if ((ans[i]>0)&&(solve2(i))) break;
    printf("%lld\n", a2);
    return 0;
}
