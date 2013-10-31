#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

struct pl
{
    int a,d;
} a[300];
vector<int> time1;
int f[1000][1000],s[1000][1000],w[1000][1000];
int n;

int main()
{
    int tt;scanf("%d",&tt);
    while (tt--)
    {
        memset(f,0,sizeof(f));
        memset(w,0,sizeof(w));
        scanf("%d",&n);
        time1.clear();
        for (int i=0;i<n;i++)
        {
            scanf("%d%d",&a[i].a,&a[i].d);
            time1.push_back(a[i].a);
            time1.push_back(a[i].d);
        }
        sort(time1.begin(),time1.end());
        time1.erase(unique(time1.begin(),time1.end()),time1.end());
        int sm=time1.size();
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<sm;j++)
            {
                if (time1[j]==a[i].a) a[i].a=j;
                if (time1[j]==a[i].d) a[i].d=j;
            }
            w[a[i].a][a[i].d]++;
        }
        for (int i=0;i<sm;i++) s[i][i]=i;
        for (int i=2;i<=sm;i++)
         for (int j=0;j<=sm-i;j++)
         {
             int x=j,y=j+i-1;
             for (int k=x;k<=y;k++)
             if (f[x][k]+f[k][y]>=f[x][y])
             {
                 f[x][y]=f[x][k]+f[k][y];
             }
             f[x][y]+=w[x][y];
         }
        printf("%d\n",f[0][sm-1]);
    }
    return 0;
}
