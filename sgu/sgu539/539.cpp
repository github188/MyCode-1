#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<map>
using namespace std;

int a[1000];
int n;

bool is0()
{
    for (int i=1;i<n;i++)
    if (a[i]<a[i-1]) return false;
    printf("0\n");
    return true;
}

bool is1(int o)
{
    int b[1000],ans[2000],c[1000];ans[0]=0;
    bool use[1000];
    for (int i=0;i<n;i++) {c[i]=b[i]=a[i];use[i]=true;}
    sort(b,b+n);
    for (int i=0;i<n;i++)
    if ((a[i]!=b[i])&&(use[i]))
    {
        bool ok=false;
        for (int j=0;j<n;j++)
        if ((a[i]==b[j])&&(a[j]==b[i]))
        {
            ok=true;
            ans[++ans[0]]=i;
            ans[++ans[0]]=j;
            int k=a[i];a[i]=a[j];a[j]=k;
            use[i]=use[j]=false;
            break;
        }
        if (!ok) {for (int i=0;i<n;i++) a[i]=c[i];return false;}
    }

    if (o!=0) printf("1\n");
    printf("%d",ans[0]/2);
    for (int i=1;i<=ans[0];i++) printf(" %d",ans[i]+1);
    printf("\n");
    return true;
}

int b[1000],c[1000],ans[2][2000];
bool use[1000];
int d[2000];

void is2()
{
    for (int i=0;i<n;i++) {b[i]=a[i];use[i]=false;}use[n]=false;
    sort(b,b+n);

    for (int i=0;i<n;i++)
     for (int j=0;j<n;j++)
      if ((a[i]==b[j])&&(!use[j+1]))
      {
          c[i+1]=j+1;use[j+1]=true;
          break;
      }

    d[0]=0;ans[0][0]=ans[1][0]=0;
    for (int i=1;i<=n;i++)
    if (use[i])
    {
        d[0]=0;
        int k=i;int uu=0;
        do
        {
            use[k]=false;
            d[++d[0]]=k;
            k=c[k];
            uu++;
            if (uu>n) break;
        } while (k!=i);
        if (d[0]==1) continue;
        if (d[0]==2)
        {
            ans[0][++ans[0][0]]=d[1];
            ans[0][++ans[0][0]]=d[2];
            int l=a[d[1]-1];a[d[1]-1]=a[d[2]-1];a[d[2]-1]=l;
            continue;
        }

        int u=d[1],v=1,u1=c[u];
        map<int,int> map1,map2;
        map1.clear();
        map2.clear();
        for (int i=1;i<=d[0];i++)
        {
            map1.insert(pair<int,int>(c[d[i]],i));
            map2.insert(pair<int,int>(d[i],i));
        }
        while (v+2<=d[0])
        {
            int j=1,k=1;
            map<int,int>::iterator it;
            it=map1.find(u);
            j=it->second;
            it=map2.find(u1);
            k=it->second;

            v+=2;
            ans[0][++ans[0][0]]=d[j];
            ans[0][++ans[0][0]]=d[k];
            u=d[j];
            u1=c[d[k]];
            int l=d[j];d[j]=d[k];d[k]=l;
            l=a[d[j]-1];a[d[j]-1]=a[d[k]-1];a[d[k]-1]=l;
        }
    }

    printf("2\n");
    printf("%d",ans[0][0]/2);
    for (int i=1;i<=ans[0][0];i++) printf(" %d",ans[0][i]);
    printf("\n");
    is1(0);
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    if (!is0()) if (!is1(1)) is2();
    return 0;
}
