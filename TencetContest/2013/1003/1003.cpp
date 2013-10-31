#include<string.h>
#include<stdio.h>
#include<map>
#include<iostream>
using namespace std;
char s[10001];
string st;
int a[2][201][201],d[201];
int n,t;
bool used[201];

long long min(long long o,long long p) {long long u=(o<p?o:p); if (u>=(long long )1e9) u=-1;return u;}

int dij(int a[][201],int s,int t)
{
    memset(used,false,sizeof(used));
    for (int i=1;i<=n;i++) d[i]=1e9;
    d[s]=0;
    while (true)
    {
        int len=1e9,p=-1;
        for (int i=1;i<=n;i++)
        if ((!used[i])&&(d[i]<len)) {p=i;len=d[i];}
        if (p<0) break;
        used[p]=true;
        for (int i=1;i<=n;i++)
        if ((a[p][i]>0)&&(d[i]>1+d[p])) d[i]=1+d[p];
    }
    return d[t];
}

string itos(int o)
{
    string s;s.clear();
    while (o>0)
    {
        char c=o%10+'0';o/=10;
        string us="";us+=c;
        s=us+s;
    }
    return s;
}


int stoi(string s)
{
    int ans=0;
    int l=0;
    while (l<s.length())
    {
        ans=ans*10+s[l]-'0';l++;
    }
    return ans;
}

int main()
{
    int tt;scanf("%d",&tt);
    while (tt--)
    {
        int d1,d2;
        scanf("%d%d",&n,&t);
        int tot=0;
        memset(a,0,sizeof(a));
        while (t--)
        {
            int k;scanf("%s%d",s,&k);int last=-1,h=0;
            while (h<strlen(s))
            {
                int l=0;st.clear();
                while ((h<strlen(s))&&(s[h]!='+')) st+=s[h++];
                h++;
                int u=0;
                u=stoi(st);
                if (last>0) a[k][last][u]=1;
                last=u;
            }
        }
        scanf("%d%d",&d1,&d2);
        int A,B;scanf("%d%d",&A,&B);
        printf("%d\n",min((long long)dij(a[0],A,B)*(long long)d1,(long long)dij(a[1],A,B)*(long long)d2));
    }
    return 0;
}
