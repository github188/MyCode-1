#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
struct node
{
    int l,r;
    int min,max;
} tr[5100000];
int tot=0;
string hash[500003];

inline int newnode()
{
    tot++;
    tr[tot].l=tr[tot].r=tr[tot].min=tr[tot].max=-1;
    return tot;
}

void ins(int o,int l,int r,int p)
{
    if ((tr[o].min<0)||(tr[o].min>p)) tr[o].min=p;
    if ((tr[o].max<0)||(tr[o].max<p)) tr[o].max=p;
    if (l==r) return;
    int mid=((l+r)>>1);
    if (p<=mid)
    {
        if (tr[o].l<0) tr[o].l=newnode();
        ins(tr[o].l,l,mid,p);
    }
    else
    {
        if (tr[o].r<0) tr[o].r=newnode();
        ins(tr[o].r,mid+1,r,p);
    }
}

int findl(int o,int l,int r,int p)
{
    if (l==r) return tr[o].min;
    int mid=((l+r)>>1);
    if (p<=mid) return findl(tr[o].l,l,mid,p);
    else if ((tr[o].r>=0)&&(tr[tr[o].r].min<p)) return findl(tr[o].r,mid+1,r,p);
         else return findl(tr[o].l,l,mid,p);
}

int findu(int o,int l,int r,int p)
{
    if (l==r) return tr[o].min;
    int mid=((l+r)>>1);
    if (p>mid) return findu(tr[o].r,mid+1,r,p);
    else if ((tr[o].l>=0)&&(tr[tr[o].l].max>p)) return findu(tr[o].l,l,mid,p);
         else return findu(tr[o].r,mid+1,r,p);
}

inline void upd(int l,int r,int x,int &ans1,int &ans2)
{
    int ll=hash[l].length(),rl=hash[r].length();
    int xl=0;
    while ((xl<ll)&&(xl<rl))
    {
        if (hash[l][xl]==hash[r][xl])
        {
            hash[x]+=hash[l][xl];
            ans1++;if (hash[x][xl]=='1') ans2++;xl++;
        } else
        if (xl<rl-1)
        {
            hash[x]+="1";
            ans1++;ans2++;return;
        } else
        {
            hash[x]+="0";ans1++;xl++;
        }
    }
    if (xl<ll)
    {
        while (xl<ll)
        {
            if (hash[l][xl]=='0')
            {
                hash[x]+="1";ans1++;ans2++;return;
            } else
            {
                hash[x]+="1";ans1++;ans2++;xl++;
            }
        }
        hash[x]+="1";ans1++;ans2++;return;
    } else
    if (xl<rl)
    {
        while (xl<rl)
        {
            if (hash[r][xl]=='1')
            {
                hash[x]+="01";ans1+=2;ans2++;return;
            } else
            {
                hash[x]+="0";ans1++;xl++;
            }
        }
    } else
    {
        hash[x]+="1";
        ans1++;ans2++;return;
    }
}
vector < int > rec;
int main()
{
    int tt;scanf("%d",&tt);int n=0;
    for (int t=1;t<=tt;t++)
    {
        tot=0;newnode();
        while (n--)
        {
            hash[rec[n]].clear();
            rec.pop_back();
            if (n==0) break;
        }
        scanf("%d",&n);
        hash[0]="0";
        hash[500002]="1";
        ins(1,0,500002,0);
        ins(1,0,500002,500002);
        int ans1=2,ans2=1;int nn=n;
        while (n--)
        {
            int x;scanf("%d",&x);
            int l=findl(1,0,500002,x);
            int r=findu(1,0,500002,x);
            ins(1,0,500002,x);
            upd(l,r,x,ans1,ans2);
            rec.push_back(x);
        }n=nn;
        printf("Case #%d: %d %d\n",t,ans1,ans2);
    }
    return 0;
}
