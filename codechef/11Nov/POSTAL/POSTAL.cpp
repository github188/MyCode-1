#include<stdio.h>
#include<string.h>

int stack[250000],num[500],a[500][500][3],dir[500];

int main()
{
    int tt;scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            num[i]=1;
            a[i][0][0]=0;
            scanf("%d",&a[i][0][1]);
        }
        int last=-1,top=-1;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i][0][2]);dir[i]=a[i][0][2];
            if ((a[i][0][2]==0)&&(last==1))
            {
                top++;
                stack[top]=i-1;
            }
            last=dir[i];
        }

        while (top>=0)
        {
            int x,y;
            x=stack[top];y=x+1;top--;
            dir[x]=0;dir[y]=1;
            if ((x!=0)&&(dir[x-1]==1)) {top++;stack[top]=x-1;}
            if ((y!=n-1)&&(dir[y+1]==0)) {top++;stack[top]=y;}
            int xt,yt,xp,yp,t;
            xt=a[x][num[x]-1][0];xp=a[x][num[x]-1][1];
            yt=a[y][num[y]-1][0];yp=a[y][num[y]-1][1];
            if (xt<yt) {xp+=yt-xt;xt=yt;}
            if (xt>yt) {yp-=xt-yt;yt=xt;}
            t=(yp-xp)/2;
            if (((yp-xp)&1)==1)
            {
                t++;
                xp=(xp+yp)/2;
                yp=xp+1;
            } else
            {
                xp=yp=(xp+yp)/2;
            }
            a[x][num[x]][0]=xt+t;a[x][num[x]][1]=xp;a[x][num[x]][2]=0;
            a[y][num[y]][0]=yt+t;a[y][num[y]][1]=yp;a[y][num[y]][2]=1;
            num[x]++;num[y]++;
        }

        int m;scanf("%d",&m);
        while (m>0)
        {
            m--;int x,y,z,p,d;
            scanf("%d%d",&x,&y);
            z=0;
            while ((z+1<num[x])&&(a[x][z+1][0]<=y)) z++;
            d=a[x][z][2];if (d==0) {d=-1;}
            p=a[x][z][1]+(y-a[x][z][0])*d;
            printf("%d %d\n",p,z);
        }
    }
    return 0;
}
