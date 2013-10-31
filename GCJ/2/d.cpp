#include<stdio.h>
#include<string.h>
char ch[10000];
int n,m,tt;
int f[100][100],d[1000],st[1000],g[1000];

int main()
{
    freopen("D-small-practice.in","r",stdin);
    freopen("D-small-practice.out","w",stdout);
    scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        scanf("%d%d",&n,&m);gets(ch);
        int len;gets(ch);
        for (int i=0;i<n;i++) {g[i]=-1;d[i]=-1;for (int j=0;j<n;j++) {f[i][j]=-1;}}
        int i=0;len=strlen(ch);
        while (i<len)
        {
              while ((i<len)&&(ch[i]==' ')) {i++;}
              int x,y;x=y=0;
              while ((i<len)&&(ch[i]!=',')) {x=x*10+ch[i]-'0';i++;}i++;
              while ((i<len)&&(ch[i]!=' ')) {y=y*10+ch[i]-'0';i++;}
              f[x][y]=f[y][x]=1;
        }
        d[0]=0;
        st[0]=1;int h=1;st[1]=0;g[0]=0;
        for (int i=0;i<n;i++) if (f[i][0]>=0) {g[0]++;}
        while (h<=st[0])
        {
              for (int i=0;i<n;i++)
              if ((f[i][st[h]]>=0)&&(d[i]<0))
              {
                 st[0]++;
                 st[st[0]]=i;
                 d[i]=d[st[h]]+1;
              }
              h++;
        }
        for (int i=0;i<n;i++)
         for (int j=0;j<n;j++)
          if (d[j]==i)
           for (int k=0;k<n;k++)
            if ((f[j][k]>=0)&&(d[k]==d[j]+1))
            {
               int sum=0;
               for (int l=0;l<n;l++)
                if ((f[l][k]>=0)&&(d[l]==d[k]+1)) {sum++;}
                if (g[j]+sum>g[k]) {g[k]=g[j]+sum;}
            }
        printf("Case #%d: %d ",t,d[1]-1);
        int ans=0;
        for (int i=0;i<n;i++)
        if ((f[1][i])&&(d[1]-1==d[i])&&(g[i]>ans)) {ans=g[i];}
        printf("%d\n",ans-d[1]+1);
    }
    return 0;
}
