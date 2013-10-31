#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<iostream>
using namespace std;

struct pt
{
    int x,y;
};
long long ans;
int n,ul,dl,ct,dt;
pt a[200000],b[200000],ql[200000],qr[200000],c[200000],d[200000];

inline bool cmp1(pt a,pt b)
{
    if (a.x<b.x) {return true;}
    return false;
}

inline bool cmp2(pt a,pt b)
{
    if ((a.y<b.y)||((a.y==b.y)&&(a.x<b.x))) {return true;}
    return false;
}

inline bool cmp3(pt a,pt b)
{
    if (a.y>b.y) {return true;}
    return false;
}

long long deal()
{
    long long ans;
    int tl,tr;
    tl=tr=-1;
    int l,r,up;
    l=ct;
    r=dt;
    ans=0;
    while (r>=0)
    {
        while ((tr>=0)&&(qr[tr].x>d[dt-r].x)) {tr--;}
        if (tr<0) {up=dl+1;} else {up=qr[tr].y-1;}
        tr++;qr[tr]=d[dt-r];

        while ((l>=0)&&(c[ct-l].y>=d[dt-r].y))
        {
                while ((tl>=0)&&(ql[tl].x<=c[ct-l].x)) {tl--;}
                tl++;ql[tl]=c[ct-l];
                l--;
        }
        if ((tl>=0)&&(ql[tl].y<=up))
        {
            int l,r;
            l=0;r=tl;
            while (l<r)
            {
                int mid=((l+r)>>1);
                if (ql[mid].y<=up) {r=mid;} else {l=mid+1;}
            }
            long long uu=tl-l+1;
            ans+=uu;
    if (ans<0)
    {
        int o=0;
    }
            if (ql[tl].y==qr[tr].y) {ans--;}
        }
        r--;
    }
    return ans;
}

void work(int l,int r)
{
    if (l==r) {return;}
    int mid=((l+r)>>1);
    work(l,mid);
    work(mid+1,r);

    int ul,ur;
    int ll,rr;
    ll=0;rr=n-1;
    while (ll!=rr)
    {
        int mid=((ll+rr)>>1);
        if (a[mid].x>=l) {rr=mid;} else {ll=mid+1;}
    }
    ul=ll;
    ll=0;rr=n-1;
    while (ll!=rr)
    {
        int mid=((ll+rr)>>1)+1;
        if (a[mid].x<=r) {ll=mid;} else {rr=mid-1;}
    }
    ur=ll;

    sort(a+ul,a+ur+1,cmp3);
    ct=dt=-1;
    for (int i=ul;i<=ur;i++)
    if (a[i].x<=mid)
    {
        if (ct==-1)
        {
            ct++;
            c[ct]=a[i];
        } else
        if (a[i].y!=c[ct].y)
        {
            ct++;
            c[ct]=a[i];
        } else
        {
            if (a[i].x>c[ct].x) {c[ct]=a[i];}
        }
    } else
    {
        if (dt==-1)
        {
            dt++;
            d[dt]=a[i];
        } else
        if (a[i].y!=d[dt].y)
        {
            dt++;
            d[dt]=a[i];
        } else
        {
            if (a[i].x<d[dt].x) {d[dt]=a[i];}
        }
    }
    sort(a+ul,a+ur+1,cmp1);

    if ((ct<0)||(dt<0)) {return;}
    ans+=deal();
    if (ans<0)
    {
        int o=0;
    }

    int dl2;
    dl2=(ct>>1);
    for (int i=0;i<=dl2;i++)
    {
        pt k=c[i];c[i]=c[ct-i];c[ct-i]=k;
        c[i].y=dl-c[i].y;
        if (i!=ct-i) c[ct-i].y=dl-c[ct-i].y;
    }
    dl2=(dt>>1);
    for (int i=0;i<=dl2;i++)
    {
        pt k=d[i];d[i]=d[dt-i];d[dt-i]=k;
        d[i].y=dl-d[i].y;
        if (i!=dt-i) d[dt-i].y=dl-d[dt-i].y;
    }
    /*
    for (int i=0;i<=ct;i++)
    {
        c[i].y=dl-c[i].y;
    }
    for (int i=0;i<=dt;i++)
    {
        d[i].y=dl-d[i].y;
    }
    sort(c,c+ct+1,cmp3);
    sort(d,d+dt+1,cmp3);*/

    ans+=deal();
    if (ans<0)
    {
        int o=0;
    }
}

int main()
{
    //freopen("1.txt","r",stdin);
    scanf("%d",&n);
    for (int i=0;i<n;i++) {scanf("%d%d",&a[i].x,&a[i].y);b[i]=a[i];}
/*
    sort(a,a+n,cmp2);
    int uu=0;
    for (int i=1;i<n;i++) if ((a[i].x==a[i-1].x)&&(a[i].y==a[i-1].y)) {uu++;}
    printf("%d\n",uu);
*/
    sort(b,b+n,cmp1);
    sort(a,a+n,cmp1);
    b[0].y=0;
    for (int i=1;i<n;i++)
    if (b[i].x==b[i-1].x) {b[i].y=b[i-1].y;ans++;} else {b[i].y=b[i-1].y+1;}
    for (int i=0;i<n;i++)
    {
        a[i].x=b[i].y;
        b[i]=a[i];
    }
    ul=a[n-1].x;

    sort(b,b+n,cmp2);
    sort(a,a+n,cmp2);
    b[0].x=0;
    for (int i=1;i<n;i++)
    if (b[i].y==b[i-1].y) {b[i].x=b[i-1].x;ans++;} else {b[i].x=b[i-1].x+1;}
    for (int i=0;i<n;i++) {a[i].y=b[i].x;}
    dl=a[n-1].y;
    sort(a,a+n,cmp1);

    work(0,ul);
    cout<<ans<<endl;
    return 0;
}
