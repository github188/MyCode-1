#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

int a[11000],xx[11000],yy[11000],f[21000],b[11000];
int pos,num,tmp;
long long seg,len,seg1,len1;
    int tt,s1,s2,x,y,z,c,p;

int find(int o)
{
    if (a[0]==0) return 0;
    int l=1,r=a[0];
    if (o<a[l]) return 0;
    if (o>=a[r]) return r;
    int mid;
    while (l<r)
    {
        mid=((l+r)>>1);
        if (a[mid+1]>o) {r=mid;} else {l=mid+1;}
    }
    return l;
}

int find1(int o)
{
    if (b[0]==0) return 0;
    int l=1,r=b[0];
    if (o<b[l]) return 0;
    if (o>=b[r]) return r;
    int mid;
    while (l<r)
    {
        mid=((l+r)>>1);
        if (b[mid+1]>o) {r=mid;} else {l=mid+1;}
    }
    return l;
}


long long work(long long o)
{
    long long ans=0;
    if (a[0]==0) return 0;
    long long u=a[1];
    if (o<u) return 0;

    long long u1=o/len,v=o%len;
    ans=u1*seg;
    int vv=v;
    int po=find(vv);
    long long pp=po;
    ans+=pp;

    return ans;
}

long long work1(long long o)
{
    long long ans=0;
    if (b[0]==0) return 0;
    long long u=b[1];
    if (o<u) return 0;

    long long u1=o/len1,v=o%len1;
    ans=u1*seg1;
    int vv=v;
    int po=find1(vv);
    long long pp=po;
    ans+=pp;

    return ans;
}

inline int min(int o,int p)
{
if (o<p) return o;return p;
}

long long sum1(long long o)
{
    long long ans,p,one;
    one=2;
    p=o/one;
    ans=work1(p);
    if (o%one>0) p++;
    ans+=work(p);
    return ans;
}

long long sum2(long long o)
{
    long long ans=0;
    if (o>=1)
    {
        ans--;
        if (s1==c) ans++;
    }
    if (o>0) ans+=work(o);

    return ans;
}

int main()
{

    scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        a[0]=0;
        scanf("%d%d%d%d%d%d%d",&s1,&s2,&x,&y,&z,&p,&c);
        if (s1==c) {a[0]++;a[a[0]]=1;}
        if (s2==c) {a[0]++;a[a[0]]=2;}

        if ((x==0)&&(y==0))
        {
            long long u=a[0];
            long long v=0;if (z==c) v=1;
            int q;
            scanf("%d",&q);
            while (q>0)
            {
               q--;
               long long l,r,ul,ur;ul=ur=0;
               //scanf("%lld%lld",&l,&r);
               cin>>l>>r;
               long long ans=0;l--;
               if (l>=1)
               {
                   if (s1==c) ul++;
               }
               if (l>=2)
               {
                   if (s2==c) ul++;
               }
               if (l>2)
               {
                   l-=2;
                   ul+=l*v;
               }
               if (r>=1)
               {
                   if (s1==c) ur++;
               }
               if (r>=2)
               {
                   if (s2==c) ur++;
               }
               if (r>2)
               {
                   r-=2;
                   ur+=r*v;
               }
               ans=ur-ul;


               //printf("%lld\n",ans);
               cout<<ans<<endl;
            }
            continue;
        }

        xx[0]=yy[0]=0;
        for (int i=1;i<p;i++)
        {
            xx[i]=xx[i-1]+x;
            if (xx[i]>=p) xx[i]-=p;
            yy[i]=yy[i-1]+y;
            if (yy[i]>=p) yy[i]-=p;
        }
        int p2=p+p-2;bool use=true;
        for (int i=0;i<=p2;i++)
        {
            f[i]=i+z;
            while (f[i]>=p) f[i]-=p;
            if (f[i]==c) use=false;
        }

        if (use)
        {
            int q;
            scanf("%d",&q);
            while (q>0)
            {
               q--;
               long long l,r;
               scanf("%lld%lld",&l,&r);
               int u=0;if (a[0]==1) u=1;
               printf("%d\n",u);
            }
            continue;
        }
        if (x==0)
        {
            num=3;a[0]=0;
        int l=0,ul=p*p+p;
        int s;s=s2;
        //freopen("1.txt","w",stdout);

        while (true)
        {
            s=f[yy[s]];
            //printf("%d %d\n",j,s[l]);

            if (s==c)
            {
                a[0]++;
                a[a[0]]=num-1;
            }

            if (s==s2) break;
            num++;
        }

        if (a[a[0]]==num) a[0]--;num--;

        seg=a[0];
        len=num;

        int q;
        scanf("%d",&q);
        while (q>0)
        {
            q--;
            long long l,r;
            //scanf("%lld%lld",&l,&r);
            cin>>l>>r;
            long long ans=sum2(r)-sum2(l-1);
            //printf("%lld\n",ans);
            cout<<ans<<endl;
        }

        }

        if (y==0)
        {
            int num1=2,num2=2;
            int s;a[0]=b[0]=0;
            if (s1==c) {a[0]++;a[a[0]]=1;}
            if (s2==c) {b[0]++;b[b[0]]=2;}

            s=s1;
            while (true)
            {
                s=f[xx[s]];
                if (s==c)
                {
                    a[0]++;
                    a[a[0]]=num;
                }
                if (s==s1) break;
                num++;
            }
            if (a[a[0]]==num) a[0]--;num--;
            seg=a[0];
            len=num;

            s=s2;num=2;
            while (true)
            {
                s=f[xx[s]];
                if (s==c)
                {
                    b[0]++;
                    b[b[0]]=num;
                }
                if (s==s2) break;
                num++;
            }
            if (b[b[0]]==num) b[0]--;num--;
            seg1=a[0];
            len1=num;

        int q;
        scanf("%d",&q);
        while (q>0)
        {
            q--;
            long long l,r;
            //scanf("%lld%lld",&l,&r);
            cin>>l>>r;
            long long ans=sum1(r)-sum1(l-1);
            //printf("%lld\n",ans);
            cout<<ans<<endl;
        }

            continue;
        }

        num=3;
        int l=0,ul=p*p+p;
        int a1=s1,a2=s2;
        int s[2];s[0]=s1;s[1]=s2;
        //freopen("1.txt","w",stdout);

        while (true)
        {
            s[l]=f[xx[s[l^1]]+yy[s[l]]];
            //printf("%d %d\n",j,s[l]);

            if (s[l]==c)
            {
                a[0]++;
                a[a[0]]=num;
            }

            if ((s[l^1]==a1)&&(s[l]==a2)) break;
            l^=1;
            num++;
        }

        if (a[a[0]]==num) a[0]--;num--;
        if (a[a[0]]==num) a[0]--;num--;

        seg=a[0];
        len=num;

        int q;
        scanf("%d",&q);
        while (q>0)
        {
            q--;
            long long l,r;
            //scanf("%lld%lld",&l,&r);
            cin>>l>>r;
            long long ans=work(r)-work(l-1);
            //printf("%lld\n",ans);
            cout<<ans<<endl;
        }

    }
    return 0;
}
