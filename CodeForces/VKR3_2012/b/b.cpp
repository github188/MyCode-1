#include<stdio.h>
int a[1000001],b[1000001],sa[1000001],sb[1000001];
int la,lb,l,r;
bool use,use1;

int max(int o,int p)
{
    if (o>p) return o;return p;
}

bool check(int ha,int ta)
{
    int k=ta;
    ta++;
    if (ta>la) ta=1;
    if (ta==ha) return false;
    if (b[sa[ta]]==0) return false;
    if (b[sa[ta]]>b[sa[ha]]) if (use) return false;
    if (b[sa[ta]]<b[sa[k]])
    {
        if (b[sa[ta]]>b[sa[ha]]) return false;
        if (b[sa[k]]<b[sa[ha]]) return false;
        use=true;
    }
    return true;
}

int main()
{
    scanf("%d%d",&la,&lb);
    for (int i=1;i<=la;i++)
    {
        scanf("%d",&sa[i]);
        a[sa[i]]=i;
    }
    for (int i=1;i<=lb;i++)
    {
        scanf("%d",&sb[i]);
        b[sb[i]]=i;
    }
    int ans=0;
    int ha,ta;
    ha=ta=1;
    use=false;
    use1=false;
    while (ha<=la)
    {
        //init(ha,ta);
        if (b[sa[ha]]!=0) {
        while (check(ha,ta))
        {
            ta++;
            if (ta>la) ta=1;
        }
        if (ta>=ha) {ans=max(ans,ta-ha+1);} else {ans=max(ans,la-ha+ta+1);}}
        ha++;
        if (ta==ha-1) ta=ha;
        if ((ha!=1)&&(b[sa[ha]]<b[sa[ha-1]])) use=false;
    }
    printf("%d\n",ans);
    return 0;
}
