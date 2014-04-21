#include<stdio.h>
#include<algorithm>
struct segment
{
    int x,y;
    bool operator<(segment b) const
    {
        return (x<b.x);
    }
} chef[500],child[500];

int main()
{
    int t;scanf("%d",&t);
    while (t--)
    {
        int n,k,p;
        scanf("%d%d%d",&n,&k,&p);
        for (int i=0;i<k;i++) scanf("%d%d",&chef[i].x,&chef[i].y);
        for (int i=0;i<p;i++) scanf("%d%d",&child[i].x,&child[i].y);
        std::sort(chef,chef+k);
        std::sort(child,child+p);
        int head_chef=0,head_child=0;
        bool ans=true;
        while ((head_chef<k)&&(chef[head_chef].x<child[head_child].x)) head_chef++;
        if (head_chef>=k) ans = false; else
        while (head_child<p)
        {
            if (chef[head_chef].x>child[head_child].x) {ans=false;break;}
            int l=child[head_child].x,r=child[head_child].y;
            if (r<l) r+=n;
            int chef_r=chef[head_chef].y;
            if (chef[head_chef].x>chef[head_chef].y) chef_r+=n;
            if (chef_r>r) {ans=false;break;}
            while (chef_r<r)
            {
                head_chef++;
                if (head_chef>=k) head_chef-=k;
                if (chef[head_chef].y<chef_r) chef_r=chef[head_chef].y+n;
                else chef_r=chef[head_chef].y;
            }
            if (chef_r!=r) {ans=false;break;}
            head_child++;
        }
        if (ans) printf("Yes\n"); else printf("No\n");
    }
    return 0;
}
