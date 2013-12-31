#include<stdio.h>
struct node
{
    int x,y,z,v;
} tr[600000];
int n=4,ans=0,root;

void update(int x)
{
    if (tr[x].z<0)
    {
        if (tr[tr[x].x].v+tr[tr[x].y].v+1>ans) ans=tr[tr[x].x].v+tr[tr[x].y].v+1;
        if (tr[tr[x].x].v>tr[tr[x].y].v) {int tmp=tr[x].x;tr[x].x=tr[x].y;tr[x].y=tmp;}
        if (tr[tr[x].y].v-tr[tr[x].x].v>1)
    }
}

int main()
{
    tr[1].x=2;tr[1].y=3;tr[1].z=4;tr[1].v=2;
    tr[2].x=tr[2].y=0;tr[2].z=-1;tr[2].v=1;
    tr[3].x=tr[3].y=0;tr[3].z=-1;tr[3].v=1;
    tr[4].x=tr[4].y=0;tr[4].z=-1;tr[4].v=1;
    int q=0;
    scanf("%d",&q);
    while (q--)
    {
        int y;scanf("%d",&y);
        tr[y].x=n+1;tr[y].y=n+2;tr[y].v=2;
        tr[n+1].x=tr[n+1].y=0;tr[n+1].z=-y;tr[n+1].v=1;
        tr[n+2].x=tr[n+2].y=0;tr[n+2].z=-y;tr[n+2].v=1;
        ans=3;
        update(y);
        printf("%d\n",ans);
    }
    return
}
