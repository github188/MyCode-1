#include<stdio.h>
#include<algorithm>
using namespace std;

struct blk
{
    int x,y;
} a[100][100];
int b[100][110],size[100],tot[100],pos[100],ans[100];
int n;

bool cmp(blk a,blk b) {return (a.x<b.x);}

void up(int i,int o)
{
    int p=o/2;
    if (p==0) return;
    if (((b[i][p]<0)||((b[i][p]!=-1)&&(a[b[i][p]][pos[b[i][p]]].x>a[b[i][o]][pos[b[i][o]]].x))))
    {
        int q=b[i][o];
        b[i][o]=b[i][p];
        b[i][p]=q;
        up(i,p);
    }
}

void down(int i,int o)
{
    int p=o*2;
    if (p>size[i]) return;
    if (p+1<=size[i])
    if ((b[i][p]==-1)||((b[i][p]!=-1)&&(p+1<=size[i])&&(b[i][p+1]!=-1)&&(a[b[i][p]][pos[b[i][p]]].x>a[b[i][p+1]][pos[b[i][p+1]]].x))) p++;
    if (b[i][p]==-1) return;
    if ((b[i][o]==-1)||((b[i][o]!=-1)&&(a[b[i][p]][pos[b[i][p]]].x<a[b[i][o]][pos[b[i][o]]].x)))
    {
        int q=b[i][o];
        b[i][o]=b[i][p];
        b[i][p]=q;
        down(i,p);
    }

}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) {scanf("%d",&a[i][j].x);a[i][j].y=j;}
    for (int i=0;i<n;i++) sort(a[i],a[i]+n,cmp);
    bool check=false;
    for (int i=0;i<n;i++)
    {
        pos[i]=0;
        b[a[i][0].y][++size[a[i][0].y]]=i;
        tot[a[i][0].y]++;
        up(a[i][0].y,size[a[i][0].y]);
    }
    while (true)
    {
        int k=-1,l=0;
        for (int i=0;i<n;i++)
        if ((tot[i]>1)&&((k==-1)||((b[i][1]>-1)&&(a[b[i][1]][pos[b[i][1]]].x<a[k][pos[k]].x))))
        {
            k=b[i][1];
            l=i;
        }
        if (k==-1) break;
        b[l][1]=-1;
        down(l,1);
        tot[l]--;
        pos[k]++;
        if (pos[k]>=n) {printf("-1\n");return 0;}
        int x=a[k][pos[k]].y;
        b[x][++size[x]]=k;
        tot[x]++;
        up(x,size[x]);
    }
    for (int i=0;i<n;i++) ans[b[i][1]]=i;
    for (int i=0;i<n-1;i++) printf("%d ",ans[i]+1);printf("%d\n",ans[n-1]+1);
    return 0;
}
