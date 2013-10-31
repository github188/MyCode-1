#include<stdio.h>
#include<string.h>

char c[700][700],ch[1500][1500];
int a[1500][1500],b[1500][1500],c1[1500][1500],d[1500][1500];
int n,m;

struct sq
{
    int lx,ly,rx,ry;
};

inline int min(int o,int p)
{
    if (o<p) {return o;}
    return p;
}

sq work(int len)
{
    int o=(len&1);
    for (int i=o;i<n-len;i+=2)
    {
        c1[i][m-1]=0;
        if (b[i][m-1]>len) {c1[i][m-1]=1;}
        for (int j=m-2;j>=0;j--)
        if (b[i][j]>len) {c1[i][j]=c1[i][j+1]+1;} else {c1[i][j]=0;}
    }

    for (int j=o;j<m-len;j+=2)
    {
        d[n-1][j]=0;
        if (a[n-1][j]>len) {d[n-1][j]=1;}
        for (int i=n-2;i>=0;i--)
        if (a[i][j]>len) {d[i][j]=d[i+1][j]+1;} else {d[i][j]=0;}
    }

    sq ans;
    int uu=(len<<1)+1;
    ans.lx=ans.ly=ans.rx=ans.ry=-1;
    for (int i=0;i<n-len-len;i+=2)
     for (int j=0;j<m-len-len;j+=2)
      if ((c1[i+len][j]>=uu)&&(d[i][j+len]>=uu))
      {
          ans.lx=(i>>1);
          ans.ly=(j>>1);
          ans.rx=ans.lx+len-1;
          ans.ry=ans.ly+len-1;
          return ans;
      }
    return ans;
}

int main()
{
    scanf("%d%d",&n,&m);gets(c[0]);
    for (int i=0;i<n;i++) {gets(c[i]);}
    n=n*2+1;m=m*2+1;
    for (int i=0;i<n;i++)
    if ((i&1)==0)
    {
        for (int j=0;j<m;j++) ch[i][j]='#';
    } else
    {
        for (int j=0;j<m;j++)
        if ((j&1)==0) {ch[i][j]='#';} else {ch[i][j]=c[(i>>1)][(j>>1)];}

    }
    for (int i=0;i<n;i++)
    {
        int j=0,k=0;
        while (j<m)
        {
            while ((j>=k)&&(j+k<m)&&(ch[i][j-k]==ch[i][j+k])) k++;
            a[i][j]=k;
            int l=1;
            while ((l<a[i][j])&&(a[i][j-l]!=a[i][j]-l))
            {
                a[i][j+l]=min(a[i][j-l],a[i][j]-l);
                l++;
            }
            j+=l;
            k-=l;if (k<0) {k=0;}
        }
    }

    for (int j=0;j<m;j++)
    {
        int i=0,k=0;
        while (i<n)
        {
            while ((i>=k)&&(i+k<n)&&(ch[i-k][j]==ch[i+k][j])) k++;
            b[i][j]=k;
            int l=1;
            while ((l<b[i][j])&&(b[i-l][j]!=b[i][j]-l))
            {
                b[i+l][j]=min(b[i-l][j],b[i][j]-l);
                l++;
            }
            i+=l;
            k-=l;if (k<0) {k=0;}
        }
    }

    int l=0,r=min(n/2,m/2);
    int l1=1,r1=min(n/2,m/2);
    if ((r&1)==1) {r=r/2;r1=r1/2;} else {r1=r1/2;r=r/2-1;}
    sq ans,ans1;
    ans.lx=ans.ly=ans.rx=ans.ry=0;
    ans1.lx=ans1.ly=ans1.rx=ans1.ry=0;
    while (l!=r)
    {
        int mid=((l+r)>>1)+1;
        sq tmp=work((mid<<1)+1);
        if (tmp.lx>=0)
        {
            ans=tmp;
            l=mid;
        } else {r=mid-1;}
    }

    while (l1<r1)
    {
        int mid=((l1+r1)>>1)+1;
        sq tmp=work((mid<<1));
        if (tmp.lx>=0)
        {
            ans1=tmp;
            l1=mid;
        } else {r1=mid-1;}
    }
    if (r1==0) {l1=0;}
    l=l*2+1;
    if (l1*2>l) {l=l1*2;}
    sq tmp=work(l);
    ans=tmp;

    ans.lx++;
    ans.ly++;
    ans.rx++;
    ans.ry++;
    printf("%d %d %d %d\n",ans.lx,ans.ly,ans.rx,ans.ry);

    return 0;
}
