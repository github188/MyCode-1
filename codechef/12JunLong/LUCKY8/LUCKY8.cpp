#include<iostream>
using namespace std;
int a[20],b[20];
long long ten=10;

int max(int o,int p)
{
    if (o>p) return o;return p;
}

int work(int o,int l4,int l7,bool up,bool down)
{
    if (o==0) return l4*l7;
    int u,d;
    u=b[o];if (up) u=9;
    d=a[o];if (down) d=0;
    if ((d<4)&&(7<u))
    {
        if ((l4+o>=l7)&&(l7+o>=l4))
        {
            int k=l4+l7+o;
            return (k/2)*(k-k/2);
        }
        if (l4<l7) {l4+=o;} else {l7+=o;}
        return l4*l7;
    }
    int ans=0;bool check=false;int kk=0;
    if (d+1<u) ans=work(o-1,l4,l7,true,true);
    if ((d<4)&&(u>4)) {ans=max(ans,work(o-1,l4+1,l7,true,true));kk++;}
    if ((d<7)&&(u>7)) {ans=max(ans,work(o-1,l4,l7+1,true,true));kk++;}
    if (u==d)
    {
        if (u==4) {ans=max(ans,work(o-1,l4+1,l7,up,down));}
        else if (u==7) {ans=max(ans,work(o-1,l4,l7+1,up,down));}
        else {ans=max(ans,work(o-1,l4,l7,up,down));}
        check=true;
    }
    if (kk==2) check=true;
    if (!check)
    {
        if (d==4) {ans=max(ans,work(o-1,l4+1,l7,true,down));}
        else if (d==7) {ans=max(ans,work(o-1,l4,l7+1,true,down));}
        else if (d+1==u) {ans=max(ans,work(o-1,l4,l7,true,down));}

        if (u==4) {ans=max(ans,work(o-1,l4+1,l7,up,true));}
        else if (u==7) {ans=max(ans,work(o-1,l4,l7+1,up,true));}
        else if (d+1==u) {ans=max(ans,work(o-1,l4,l7,up,true));}
    }
    return ans;
}

int main()
{
    int tt;
    cin>>tt;
    while (tt>0)
    {
        tt--;
        long long l,r,zero;zero=0;
        cin>>l>>r;
        for (int i=0;i<20;i++) a[i]=b[i]=0;
        while (l>zero)
        {
            long long u=(l%ten);
            a[++a[0]]=u;
            l/=ten;
        }
        while (r>zero)
        {
            long long u=(r%ten);
            b[++b[0]]=u;
            r/=ten;
        }
        cout<<work(b[0],0,0,false,false)<<endl;
    }
    return 0;
}
