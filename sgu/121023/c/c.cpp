#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
long long ans;
int n;
int tot[2],a[2][600][3];
bool com[600][600];

bool in(int l,int r,int o)
{
    if (l>r) {int k=l;l=r;r=k;}
    if ((l<=o)&&(o<=r)) return true;return false;
}

void work(int o)
{
    int p=(o^1);
    for (int i=0;i<tot[o];i++)
     for (int j=0;j<tot[p];j++)
      if (in(a[o][i][1],a[o][i][2],a[p][j][0])&in(a[p][j][1],a[p][j][2],a[o][i][0])) com[i][j]=true;

    for (int i=0;i<tot[o];i++)
     for (int j=i+1;j<tot[o];j++)
     {
         long long m=0;
         for (int k=0;k<tot[p];k++)
          if (com[i][k]&com[j][k]) m++;
         if (m>1) {m=m*(m-1)/2;ans+=m;}
     }
}

int main()
{
    scanf("%d",&n);tot[0]=tot[1]=0;
    for (int i=0;i<n;i++)
    {
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if (x1==x2)
        {
            a[0][tot[0]][0]=x1;
            a[0][tot[0]][1]=y1;
            a[0][tot[0]][2]=y2;
            tot[0]++;
        } else
        {
            a[1][tot[1]][0]=y1;
            a[1][tot[1]][1]=x1;
            a[1][tot[1]][2]=x2;
            tot[1]++;
        }
    }
    ans=0;
    if (tot[0]<tot[1]) {work(0);} else {work(1);}
    cout<<ans<<endl;

    return 0;
}
