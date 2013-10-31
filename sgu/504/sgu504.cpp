#include<stdio.h>
#include<string.h>

struct sq
{
    int lx,ly,rx,ry;
};
long long a[800][800],b[800][800];
char ch[800][800];
int n,m;
long long mod;
long long mul=30029;
int a1[800][800],b1[800][800];

int min(int o,int p)
{
    if (o<p) {return o;}return p;
}

sq work(int len)
{
    sq ans;
    long long k=1;
    for (int i=1;i<len;i++) {k=(k*mul)%mod;}
    for (int i=0;i<n;i++)
    {
        a[i][0]=0;
        for (int j=0;j<len;j++) {a[i][0]=(a[i][0]*mul+(long long)(ch[i][j]-'a'+13))%mod;}
        for (int j=1;j<=m-len;j++)
        {
            long long c=ch[i][j-1]-'a'+13;
            a[i][j]=a[i][j-1]-(c*k)%mod;
            if (a[i][j]<0) {a[i][j]+=mod;}
            a[i][j]=(a[i][j]*mul+(long long)(ch[i][j+len-1]-'a'+13))%mod;
        }
        long long tmp=0;
        for (int j=m-1;j>=m-len;j--) {tmp=(tmp*mul+(long long)(ch[i][j]-'a'+13))%mod;}
        if (a[i][m-len]!=tmp) {a[i][m-len]=-1;}
        for (int j=m-len-1;j>=0;j--)
        {
            long long c=ch[i][j+len]-'a'+13;
            tmp=tmp-(c*k)%mod;
            if (tmp<0) {tmp+=mod;}
            tmp=(tmp*mul+(long long)(ch[i][j]-'a'+13))%mod;
            if (tmp!=a[i][j]) {a[i][j]=-1;}
        }
    }

    for (int j=0;j<m;j++)
    {
        b[0][j]=0;
        for (int i=0;i<len;i++) {b[0][j]=(b[0][j]*mul+(long long)(ch[i][j]-'a'+13))%mod;}
        for (int i=1;i<=n-len;i++)
        {
            long long c=ch[i-1][j]-'a'+13;
            b[i][j]=b[i-1][j]-(c*k)%mod;
            if (b[i][j]<0) {b[i][j]+=mod;}
            b[i][j]=(b[i][j]*mul+(long long)(ch[i+len-1][j]-'a'+13))%mod;
        }
        long long tmp=0;
        for (int i=n-1;i>=n-len;i--) {tmp=(tmp*mul+(long long)(ch[i][j]-'a'+13))%mod;}
        if (b[n-len][j]!=tmp) {b[n-len][j]=-1;}
        for (int i=n-len-1;i>=0;i--)
        {
            long long c=ch[i+len][j]-'a'+13;
            tmp=tmp-(c*k)%mod;
            if (tmp<0) {tmp+=mod;}
            tmp=(tmp*mul+(long long)(ch[i][j]-'a'+13))%mod;
            if (tmp!=b[i][j]) {b[i][j]=-1;}
        }
    }

    long long po=-1;
    for (int i=0;i<=n-len;i++)
    {
        a1[i][m-1]=0;
        if (b[i][m-1]!=po) {a1[i][m-1]=1;}
        for (int j=m-2;j>=0;j--)
        {
            a1[i][j]=a1[i][j+1]+1;
            if (b[i][j]==po) {a1[i][j]=0;}
        }
    }

    for (int j=0;j<=m-len;j++)
    {
        b1[n-1][j]=0;
        if (a[n-1][j]!=po) {b1[n-1][j]=1;}
        for (int i=n-2;i>=0;i--)
        {
            b1[i][j]=b1[i+1][j]+1;
            if (a[i][j]==po) {b1[i][j]=0;}
        }
    }


    ans.lx=ans.ly=ans.rx=ans.ry=-1;
    for (int i=0;i<=n-len;i++)
     for (int j=0;j<=m-len;j++)
      if ((a1[i][j]>=len)&&(b1[i][j]>=len))
      {
          ans.lx=i;
          ans.ly=j;
          ans.rx=i+len-1;
          ans.ry=j+len-1;
          return ans;
      }
    return ans;
}

int main()
{
    mod=1;long long kk=2;
    mod*=kk;kk=3;
    mod*=kk;kk=5;
    mod*=kk;kk=7;
    mod*=kk;kk=11;
    mod*=kk;kk=13;
    mod*=kk;kk=17;
    mod*=kk;kk=19;
    mod*=kk;kk=23;
    mod*=kk;kk=29;
    mod*=kk;kk=31;
    mod*=kk;kk=37;
    mod*=kk;kk=1;
    mod--;
    scanf("%d%d",&n,&m);gets(ch[0]);
    for (int i=0;i<n;i++) {gets(ch[i]);}
    int l,r;l=1;r=min(n,m);

    sq ans;
    ans.lx=ans.ly=ans.rx=ans.ry=0;
    while (l!=r)
    {
        int mid=(l+r)/2+1;
        sq tmp=work(mid);
        if (tmp.lx>=0)
        {
            ans=tmp;
            l=mid;
        } else
        {
            r=mid-1;
        }
    }

    ans.lx++;
    ans.ly++;
    ans.rx++;
    ans.ry++;
    printf("%d %d %d %d\n",ans.lx,ans.ly,ans.rx,ans.ry);

    return 0;
}
