#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
char s[200000],t[200000];
int a[200000],b[200000];
int n,m;
vector<int> c[300];
void work(int a[])
{
    for (int i=0;i<300;i++) c[i].clear();
    for (int i=0;i<m;i++) c[t[i]].push_back(i);
    int k=0;
    for (int i=0;i<n;i++)
    {
        if ((c[s[i]].size()==0)||(k<c[s[i]][0]))
        {
            a[i]=-1;
            return;
        }
        int u=c[s[i]].size()-1;
        if (c[s[i]][u]<k)
        {
            a[i]=c[s[i]][u]+1;
            continue;
        }
        int l=0,r=u;
        while (l<r)
        {
            int mid=((l+r)>>1);
            if (c[s[i]][mid+1]<=k) {l=mid+1;} else {r=mid;}
        }

        a[i]=c[s[i]][l]+1;
        if (c[s[i]][l]==k) k++;
    }
}

int main()
{
    gets(s);gets(t);
    n=strlen(s),m=strlen(t);
    work(a);
    for (int i=0;i<m/2;i++)
    {
        char tmp=t[i];t[i]=t[m-i-1];t[m-i-1]=tmp;
    }
    for (int i=0;i<n/2;i++)
    {
        char tmp=s[i];s[i]=s[n-i-1];s[n-i-1]=tmp;
    }
    work(b);

    for (int i=0;i<n/2;i++)
    {
        int tmp=b[i];b[i]=b[n-i-1];b[n-i-1]=tmp;
    }
    bool check=true;
    for (int i=0;i<n;i++)
    if ((a[i]+b[i]-1<m)||(a[i]==-1)||(b[i]==-1)) {check=false;break;}
    if (check) {printf("YES\n");} else {printf("NO\n");}

    return 0;
}
