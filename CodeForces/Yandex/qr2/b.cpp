#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
bool f[500],g[500];
int a[50000][201],b[300][300],ans[300][300];
int n,m;
int h[500];

int main()
{
    scanf("%d",&n);int nn=n*(n-1);nn/=2;
    for (int i=1;i<=200;i++) {b[i][0]=0;f[i]=g[i]=false;}
    for (int i=1;i<=nn;i++)
    {
        scanf("%d",&a[i][0]);
        for (int j=1;j<=a[i][0];j++)
        {
            scanf("%d",&a[i][j]);
            g[a[i][j]]=true;
            b[a[i][j]][0]++;
            b[a[i][j]][b[a[i][j]][0]]=i;
        }
    }
    m=0;if (n==2) {m=1;ans[1][0]=a[1][0];for (int i=1;i<=a[1][0];i++) {ans[1][i]=a[1][i];}} else {
    for (int i=1;i<=200;i++)
        if ((g[i])&&(!f[i]))
        {
           m++;
           ans[m][0]=0;
           h[0]=0;
           for (int j=1;j<=a[b[i][1]][0];j++) {h[0]++;h[h[0]]=a[b[i][1]][j];}
           for (int j=1;j<=a[b[i][2]][0];j++) {h[0]++;h[h[0]]=a[b[i][2]][j];}
           sort(h+1,h+1+h[0]);
           
           for (int j=1;j<h[0];j++)
            if (h[j]==h[j+1]) {ans[m][0]++;ans[m][ans[m][0]]=h[j];f[h[j]]=true;}
        }}
    
    int i=1;
    while (m<n)
    {
          if (ans[i][0]>1)
          {
            m++;
            ans[m][0]=1;
            ans[m][1]=ans[i][ans[i][0]];
            ans[i][0]--;
          }
          i++;
    }
        
    for (int i=1;i<=m;i++)
    {
        cout<<ans[i][0];
        for (int j=1;j<=ans[i][0];j++) cout<<" "<<ans[i][j];
        cout<<endl;
    }
    return 0;
}
