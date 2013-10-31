#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
string s[62],suf[1300];
long long L,R,K;
int N,n,M,m;
int pos[62][20],pre[1300][10],num[20][1300],prefix[1300][1300];
bool isStr[1300];
long long val1[20][1300],val[20][1300],bn[20],ubn[20],all[20];

bool cmp(string a,string b) { return (a.length()>b.length()); }

inline int min(int o,int p) {return o<p?o:p;}

long long calc(long long o)
{
    int digit[20];
    digit[0]=0;

    if (o==0) return 0;
    long long ans=0,q=o,ten=10;
    int p=0;
    while (q>0)
    {
        p++;
        digit[++digit[0]]=q%ten;
        q/=ten;
    }
    ans=bn[p-1];
    bool check=false;
    for (int i=digit[0];i>0;i--)
    if (check)
    {
        for (int j=i;j>0;j--) ans+=all[j-1]*digit[j];
        ans++;
        return ans;
    } else
    {
       for (int j=0;j<digit[i];j++)
         if ((j>0)||(i!=digit[0]))
         {
          bool check=false;
          for (int k=0;k<n;k++)
          {
              if ((digit[0]-i+1>=s[k].length())&&(s[k][s[k].length()-1]==j+'0'))
              {
                  check=true;
                  for (int l=s[k].length()-2;l>=0;l--)
                  if (s[k][l]!=digit[i+s[k].length()-1-l]+'0') {check=false;break;}
              }
              if (check)
              {
                  if (i!=1) {ans+=all[i-1];} else {ans++;}
                  break;
              }
          }
          if (check) continue;
          for (int k=0;k<n;k++)
              {
                  for (int l=min(s[k].length()-2,digit[0]-i);l>=0;l--)
                  if ((s[k][l]==j+'0')&&(s[k].length()-1-l<=i-1))
                  {
                      bool check=true;
                      for (int h=l-1;h>=0;h--)
                      if (s[k][h]!=digit[i+l-h]+'0') {check=false;break;}
                      if (check) ans+=val[i-1][pos[k][s[k].length()-1-l]]+val1[i-1][pos[k][s[k].length()-1-l]];
                  }
              }
          ans+=bn[i-1];
         }
         for (int j=0;j<n;j++)
         if (digit[0]-i+1>=s[j].length())
         {
             check=true;
             for (int k=s[j].length()-1;k>=0;k--)
             if (s[j][k]!=digit[i+s[j].length()-1-k]+'0') {check=false;break;}
             if (check) break;
         }
    }
    if (check) ans++;
    return ans;
}

bool check_test(long long o,int p)
{
    string st="";
    long long ten=10;
    while (o>0)
    {
        char ch=o%ten+'0';
        st=ch+st;
        o/=ten;
    }
    if (st.length()>=s[p].length())
    {
        for (int i=0;i<=st.length()-s[p].length();i++)
         {
             bool check=true;
             for (int j=0;j<s[p].length();j++)
             if (s[p][j]!=st[i+j]) {check=false;break;}
             if (check) return true;
         }
    }
    return false;
}

int main()
{
    cin>>L>>R>>K>>N;
    n=0;
    all[0]=1;
    all[1]=10;
    for (int i=1;i<19;i++) all[i+1]=all[i]*all[1];
    for (int i=0;i<N;i++) cin>>s[i];
    sort(s,s+N,cmp);
    for (int i=0;i<N;i++)
    {
        bool check=true;
        for (int j=i+1;j<N;j++)
        {
            for (int k=0;k<=s[i].length()-s[j].length();k++)
            {
                check=false;
                for (int l=0;l<s[j].length();l++)
                if (s[i][k+l]!=s[j][l]) {check=true;break;}
                if (!check) break;
            }
            if (!check) break;
        }
        if (check) s[n++]=s[i];
    }

    M=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<s[i].length();j++)
        {
            string tmp="";
            for (int k=j;k<s[i].length();k++) tmp+=s[i][k];
            suf[M++]=tmp;
        }
    }
    sort(suf,suf+M);

    m=0;
    for (int i=0;i<M;i++)
    if ((i==0)||(suf[i]!=suf[i-1])) suf[m++]=suf[i];

    int one_dig[10];
    int u=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<s[i].length();j++)
        {
            string tmp="";
            for (int k=j;k<s[i].length();k++) tmp+=s[i][k];
            for (int k=0;k<m;k++) if (tmp==suf[k]) {pos[i][s[i].length()-j]=k;break;}
        }
    }

    for (int i=0;i<m;i++)
    {
     for (int j=0;j<10;j++) pre[i][j]=-1;
     if (suf[i].length()==1)
     {
         one_dig[u++]=suf[i][0]-'0';
     }
     for (int j=0;j<m;j++)
      if (suf[j].length()-1==suf[i].length())
      {
          int k=suf[j][0]-'0';
          if (pre[i][k]<0)
          {
              char ch='0'+k;
              string tmp=ch+suf[i];
              if (tmp==suf[j]) {pre[i][k]=j;} else {pre[i][k]=-1;}
          }
      }
    }
    for (int i=0;i<m;i++)
    {
        bool check=true;
        for (int j=0;j<10;j++) if (pre[i][j]!=-1) {check=false;break;}
        if (check) isStr[i]=true;
    }

    for (int i=0;i<m;i++)
    {
        int tmp=suf[i].length();
        num[tmp][++num[tmp][0]]=i;
    }

    for (int i=1;i<20;i++)
     for (int j=1;j<=num[i][0];j++)
     if (!isStr[num[i][j]])
     {
         int l=num[i][j];
         for (int k=0;k<10;k++)
         if (pre[l][k]<0)
         {
             string tmp=char('0'+k)+suf[l];
             bool check=false;
             for (int h=i;h>0;h--)
             {
                for (int v=1;v<=num[h][0];v++)
                {
                    int w=num[h][v];
                    check=true;
                    for (int t=0;t<h;t++) if (tmp[t]!=suf[w][t]) {check=false;break;}
                    if (check) {pre[l][k]=w;break;}
                }
              if (check) break;
             }
         }
     }

     for (int i=1;i<20;i++)
      for (int j=1;j<=num[i][0];j++)
      {
          int x=num[i][j];
          prefix[x][0]=0;
          for (int k=1;k<i;k++)
           for (int l=1;l<=num[k][0];l++)
           {
               int y=num[k][l];
               bool check=true;
               for (int h=0;h<k;h++) if (suf[x][h]!=suf[y][h]) {check=false;break;}
               if (check) {prefix[x][++prefix[x][0]]=y;break;}
           }
      }

    ubn[1]=10-num[1][0];
    long long ten=10;
    for (int i=1;i<=num[1][0];i++)
    if (isStr[num[1][i]]) {bn[1]++;}
    else {val[1][num[1][i]]=1;}
    for (int i=1;i<19;i++)
    {
     bn[i+1]=bn[i]*ten+bn[1]*(all[i]-bn[i]);
     ubn[i+1]=ubn[i]*(long long)(ten-num[1][0]);
     long long sum[10];
     for (int j=0;j<10;j++) sum[j]=0;
     for (int j=1;j<=i;j++)
      for (int k=1;k<=num[j][0];k++)
      if (val[i][num[j][k]]!=0)
       for (int l=0;l<10;l++)
        if (pre[num[j][k]][l]==-1)
        {
            ubn[i+1]+=val[i][num[j][k]];
            sum[l]+=val[i][num[j][k]];
        } else
        if (isStr[pre[num[j][k]][l]])
        {
            if (suf[pre[num[j][k]][l]].length()!=1) bn[i+1]+=val[i][num[j][k]];
        } else
        {
            val[i+1][pre[num[j][k]][l]]+=val[i][num[j][k]];
        }
      for (int j=1;j<=num[1][0];j++) if (!isStr[num[1][j]]) val[i+1][num[1][j]]+=ubn[i]+sum[suf[num[1][j]][0]-'0'];

      for (int j=19;j>0;j--)
       for (int k=1;k<=num[j][0];k++)
        for (int l=1;l<=prefix[num[j][k]][0];l++)
        {
            int y=prefix[num[j][k]][l];
            val1[i+1][y]+=val[i+1][num[j][k]];
        }
    }
    long long one=1,two=2;
    //cout<<calc(99)<<endl;
    //cout<<calc(100)<<endl;

    if (calc(R)-calc(L-one)<K) {cout<<"no such number"<<endl;}
    else
    {
        long long dl=calc(L-one);
        long long l=L,r=R;
        while (l<r)
        {
            long long mid=(l+r)/two;
            long long ans=calc(mid)-dl;
            if (ans>=K) {r=mid;} else {l=mid+one;}
        }
        cout<<l<<endl;

        long long k=K;
        for (long long i=L;i<=R;i++)
        {
            for (int j=0;j<n;j++)
            if (check_test(i,j)) {k--;break;}
            if (k==0) {cout<<i<<endl;break;}
        }
    }

    return 0;
}
