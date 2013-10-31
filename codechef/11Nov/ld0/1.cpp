#include<map>
#include<stdio.h>
#include<iostream>
using namespace std;
int a[11000],xx[11000],yy[11000];
map<int,int> box;
int pos,num;
long long seg,len;

int find(int o)
{
    if (a[0]==0) return 0;
    int l=1,r=a[0];
    if (o<=a[l]) return 0;
    if (o>a[r]) {return r;}
    while (l<r)
    {
        int mid=(l+r)/2;
        if (a[mid+1]>=o) {r=mid;} else {l=mid+1;}
    }
    return l;
}

long long work(long long o)
{
    long long ans=0;
    if (a[0]==0) return 0;
    long long u=a[1];
    if (o<u) return 0;

    long long pos1=pos-1;
    if (o<=pos1)
    {
        int oo=o;
        int po=find(oo);
        if (a[po+1]==oo) po++;
        return po;
    }

    long long u1=(o-pos1)/len,v=(o-pos1)%len;
    ans+=u1*seg;
    int vv=pos+v-1;
    int po=find(vv);
    if (a[po+1]==vv) po++;
    long long sum=po;ans+=sum;

    return ans;
}

int main()
{
    int tt,s1,s2,x,y,z,c,p;
    scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        a[0]=0;
        scanf("%d%d%d%d%d%d%d",&s1,&s2,&x,&y,&z,&p,&c);
        if (s1==c) {a[0]++;a[a[0]]=1;}
        if (s2==c) {a[0]++;a[a[0]]=2;}

        xx[0]=yy[0]=0;
        for (int i=1;i<p;i++)
        {
            xx[i]=xx[i-1]+x;
            if (xx[i]>=p) xx[i]-=p;
            yy[i]=yy[i-1]+y;
            if (yy[i]>=p) yy[i]-=p;
        }
        box.clear();
        num=3;pos=1;

        while (true)
        {
            map<int,int>::iterator pt=box.find((s1<<14)+s2);
            if (pt!=box.end())
            {
                num--;
                pos=pt->second;
                break;
            }
            int tmp=xx[s2]+yy[s1];
            if (tmp>=p) tmp-=p;
            tmp+=z;
            if (tmp>=p) tmp-=p;
            if (tmp==c)
            {
                a[0]++;
                a[a[0]]=num;
            }
            box.insert(pair<int,int>(((s1<<14)+s2),num));
            s1=s2;s2=tmp;
            num++;
        }
        seg=a[0]-find(pos);
        len=num-pos+1;

        int q;
        scanf("%d",&q);
        while (q>0)
        {
            q--;
            long long l,r,one;one=1;
            cin>>l>>r;
            long long ans=work(r)-work(l-one);
            cout<<ans<<endl;
        }

    }
    return 0;
}
