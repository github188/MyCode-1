#include<stdio.h>
int v[1001],e[4001][4],d[1001][3];
int tot,n,m,s,dd,tt;
bool use[1001][3];

int min(int o,int p)
{
    if (o<p) return o; return p;
}

int main()
{
    scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        scanf("%d%d%d%d",&n,&m,&s,&dd);
        for (int i=1;i<=n;i++) {v[i]=0;d[i][0]=d[i][1]=d[i][2]=-1;use[i][0]=use[i][1]=use[i][2]=false;}tot=0;
        for (int i=0;i<m;i++)
        {
            int x,y,a,b;
            scanf("%d%d%d%d",&x,&y,&a,&b);
            tot++;
            e[tot][0]=y;
            e[tot][1]=a;
            e[tot][2]=b;
            e[tot][3]=v[x];
            v[x]=tot;
            tot++;
            e[tot][0]=x;
            e[tot][1]=a;
            e[tot][2]=b;
            e[tot][3]=v[y];
            v[y]=tot;
        }
        d[s][0]=0;
        while (true)
        {
            int tmp=-1,x=0,y=0;
            for (int i=1;i<=n;i++)
             for (int j=0;j<3;j++)
              if ((!use[i][j])&&(d[i][j]!=-1)&&((tmp==-1)||(tmp>d[i][j])))
              {
                  tmp=d[i][j];x=i;y=j;
              }
            if (tmp==-1) break;
            int j=v[x];
            use[x][y]=true;
            while (j!=0)
            {
                int k=e[j][0];
                if (y==0)
                {
                    if ((d[k][y]==-1)||(d[k][y]>tmp+e[j][1]+e[j][2])) d[k][y]=tmp+e[j][1]+e[j][2];
                    if ((d[k][1]==-1)||(d[k][1]>tmp+min(e[j][1],e[j][2])/2)) d[k][1]=tmp+min(e[j][1],e[j][2])/2;
                } else
                if (y==1)
                {
                    if ((d[k][y]==-1)||(d[k][y]>tmp+e[j][1])) d[k][y]=tmp+e[j][1];
                    if ((d[k][2]==-1)||(d[k][2]>tmp+min(e[j][1]/3,e[j][2]/3))) d[k][2]=tmp+min(e[j][1],e[j][2])/3;
                } else
                {
                    if (d[k][2]==-1) d[k][2]=tmp+min(e[j][1],e[j][2]);
                    d[k][2]=min(d[k][2],tmp+min(e[j][1],e[j][2]));
                }
                j=e[j][3];
            }
        }
        int u=d[dd][0];
        if ((u==-1)||((d[dd][1]!=-1)&&(d[dd][1]<u))) u=d[dd][1];
        if ((u==-1)||((d[dd][2]!=-1)&&(d[dd][2]<u))) u=d[dd][2];
        printf("%d\n",u);
    }
    return 0;
}
