#include<stdio.h>
#include<string.h>
int n,m,ans;
int a[10000],b[50][2],f[13][2],ans_l[13][20],tmp_l[13][20],tmp_u[13],set_u[13][2],g[13];
char c[20];
bool use[13][13];

bool check(int o,int p,int q,int r)
{
    if ((o&g[r])>0)return false;
    for (int i=0;i<q;i++)
    {
        int x=(set_u[i][0]&o),y=(set_u[i][1]&o);
        if (((x&p)>0)&&((x^p)>0)) return false;
        if (((y&p)>0)&&((y^p)>0)) return false;
        //if (((z&p)>0)&&((z^p)>0)) return false;
    }
    return true;
}

void dfs(int o,int p)
{
    if (o>=n)
    {
        ans=p;
        for (int i=0;i<p;i++)
        for (int j=0;j<=tmp_l[i][0];j++) ans_l[i][j]=tmp_l[i][j];
        return;
    }

    for (int i=0;i<p;i++)
    {
        int x=set_u[i][0],y=set_u[i][1];
        set_u[i][0]|=f[o][0];
        set_u[i][1]|=f[o][1];
        if (check(tmp_u[i]|(1<<o),(1<<o),p,o))
        {
            tmp_l[i][0]++;
            tmp_l[i][tmp_l[i][0]]=o;
            tmp_u[i]|=(1<<o);
            dfs(o+1,p);
            tmp_l[i][0]--;
            tmp_u[i]^=(1<<o);
        }
        set_u[i][0]=x;
        set_u[i][1]=y;
    }

    if (p+1<ans)
    {
        tmp_l[p][0]=1;
        tmp_l[p][1]=o;
        tmp_u[p]=(1<<o);
        set_u[p][0]=f[o][0];
        set_u[p][1]=f[o][1];
        dfs(o+1,p+1);
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) c[i]=0;
    for (int i=0;i<(1<<n);i++) a[i]=100;a[0]=0;
    int tot=0;
    char s[10];gets(s);
    for (int i=0;i<m;i++)
    {
        gets(s);int tmp=-1;
        for (int j=0;j<tot;j++)
        if (c[j]==s[0]) {tmp=j;break;}
        if (tmp==-1)
        {
            c[tot]=s[0];
            tmp=tot;
            tot++;
        }
        b[i][0]=s[0]-'a';

        tmp=-1;
        for (int j=0;j<tot;j++)
        if (c[j]==s[1]) {tmp=j;break;}
        if (tmp==-1)
        {
            c[tot]=s[1];
            tmp=tot;
            tot++;
        }
        b[i][1]=s[1]-'a';
    }
    for (int i=0;i<13;i++)
    {
        c[i]='a'+i;
        //tot++;
    }

    memset(use,false,sizeof(use));
    for (int i=0;i<m;i++)
    {
        int x=b[i][0],y=b[i][1];
        for (int j=0;j<m;j++)
        {
            if ((b[j][0]==x)&&(b[j][1]!=y)) use[b[j][1]][y]=use[y][b[j][1]]=true;
            if ((b[j][1]==y)&&(b[j][0]!=x)) use[b[j][0]][x]=use[x][b[j][0]]=true;
        }
        f[x][1]+=(1<<y);
        f[y][0]+=(1<<x);
    }

    ans=n;
    for (int i=0;i<n;i++)
    {
        ans_l[i][0]=1;
        ans_l[i][1]=i;
        g[i]=0;
        for (int j=0;j<n;j++) if (use[i][j]) g[i]+=(1<<j);
    }
    dfs(0,0);

    printf("%d\n",ans);
    for (int i=0;i<ans;i++)
    {
        for (int j=1;j<=ans_l[i][0];j++) printf("%c",c[ans_l[i][j]]);
        printf("\n");
    }
    return 0;
}
