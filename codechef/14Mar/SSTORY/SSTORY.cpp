#include<iostream>
#include<cstring>
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int MAX = 800050;

int sa[MAX], rank[MAX], height[MAX];
int wa[MAX], wb[MAX], wv[MAX], wd[MAX];
int min(int o,int p) {return (o<p)?o:p;}
int cmp(int *r, int a, int b, int l)
{
    return r[a] == r[b] && r[a+l] == r[b+l];
}

void da(int *r, int n, int m)            //  倍增算法0(nlgn)。
{
    int i, j, p, *x = wa, *y = wb, *t;
    for(i = 0; i < m; i ++) wd[i] = 0;
    for(i = 0; i < n; i ++) wd[x[i]=r[i]] ++;
    for(i = 1; i < m; i ++) wd[i] += wd[i-1];
    for(i = n-1; i >= 0; i --) sa[-- wd[x[i]]] = i;
    for(j = 1, p = 1; p < n; j *= 2, m = p)
    {
        for(p = 0, i = n-j; i < n; i ++) y[p ++] = i;
        for(i = 0; i < n; i ++) if(sa[i] >= j) y[p ++] = sa[i] - j;
        for(i = 0; i < n; i ++) wv[i] = x[y[i]];
        for(i = 0; i < m; i ++) wd[i] = 0;
        for(i = 0; i < n; i ++) wd[wv[i]] ++;
        for(i = 1; i < m; i ++) wd[i] += wd[i-1];
        for(i = n-1; i >= 0; i --) sa[-- wd[wv[i]]] = y[i];
        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i ++)
        {
            x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p - 1 : p ++;
        }
    }
}

void calHeight(int *r, int n)            //  求height数组。
{
    int i, j, k = 0;
    for(i = 1; i <= n; i ++) rank[sa[i]] = i;
    for(i = 0; i < n; height[rank[i ++]] = k)
    {
        for(k ? k -- : 0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k ++);
    }
}
    char str[MAX];
    int num[MAX];
int main()
{
    int i, k, l1, l2;
    scanf("%s", str);
    l1 = strlen(str);
    for(k = i = 0; i < l1; i ++)
    {
        num[k ++] = str[i] - 'a' + 2;
    }
    num[k ++] = 1;                       //  相当于论文中的'$'分隔符。
    scanf("%s", str);
    l2 = strlen(str);
    for(i = 0; i < l2; i ++)
    {
        num[k ++] = str[i] - 'a' + 2;
    }
    int n = l1 + l2;
    da(num, n + 1, 30);
    calHeight(num, n);
    int ans = 0,pos = 1e9;
    for(i = 2; i < k; i ++)
        if((sa[i] < l1 && sa[i-1] > l1) || (sa[i-1] < l1 && sa[i] > l1))
        {
            if (height[i]>ans)
            {
                ans=height[i];
            }
        }
    int tmp;bool islegal=false;
    for (i = 2; i < k; i++)
    if (height[i]<ans) {tmp=-1;islegal=false;}
    else
    {
        if ((sa[i-1]>l1)&&((sa[i-1]<tmp)||(tmp<0))) tmp=sa[i-1];
        if ((sa[i]>l1)&&((sa[i]<tmp)||(tmp<0))) tmp=sa[i];
        if((sa[i] < l1 && sa[i-1] > l1) || (sa[i-1] < l1 && sa[i] > l1)) islegal=true;
        if (islegal) pos=(pos<tmp)?pos:tmp;
    }
    if (ans>0)
    {
        for (int i=0;i<ans;i++) printf("%c",str[pos-l1-1+i]);
        printf("\n");
    }
    printf("%d\n", ans);
    return 0;
}
