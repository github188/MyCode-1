#include<stdio.h>
#include<string.h>
char s[500][500];
int ul[500][500],rd[500][500];
int n,m;

inline int max(int o,int p)
{
    return (o>p?o:p);
}

int main()
{
    freopen("aaaaaa.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tt;scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        scanf("%d%d",&n,&m);gets(s[0]);
        for (int i=0;i<n;i++) gets(s[i]);
        memset(ul,0,sizeof(ul));
        memset(rd,0,sizeof(rd));
        ul[0][0]=1;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                if (s[i][j]!='#')
                {
                    if ((i>0)&&(ul[i-1][j]>0)) ul[i][j]=max(ul[i-1][j]+1,ul[i][j]);
                    if ((j>0)&&(ul[i][j-1]>0)) ul[i][j]=max(ul[i][j-1]+1,ul[i][j]);
                }
        for (int i=n-1;i>=0;i--)
            for (int j=m-1;j>=0;j--)
                if (s[i][j]!='#')
                {
                    rd[i][j]=1;
                    if ((i<n-1)&&(rd[i+1][j]>0)) rd[i][j]=max(rd[i+1][j]+1,rd[i][j]);
                    if ((j<m-1)&&(rd[i][j+1]>0)) rd[i][j]=max(rd[i][j+1]+1,rd[i][j]);
                }
        int ans=rd[0][0];
        for (int i=1;i<n;i++)
            for (int j=0;j<m-1;j++)
            if ((s[i][j]!='#')&&(s[i][j+1]!='#'))
            {
                int a=0,b=0,c=0;
                if (i<n) a=rd[i+1][j];b=1;
                while ((j+b<m)&&(s[i][j+b]=='.'))
                {
                    b++;
                    if (ul[i-1][j+b-1]==0) continue;
                    c=ul[i-1][j+b-1];
                    ans=max(ans,a+b+c);
                }
            }
        for (int j=1;j<m;j++)
            for (int i=1;i<n;i++)
            if ((s[i][j]!='#')&&(s[i-1][j]!='#')&&(ul[i][j-1]>0))
            {
                int a=0,b=0,c=0;
                a=ul[i][j-1];b=1;
                while ((i-b>=0)&&(s[i-b][j]=='.'))
                {
                    b++;
                    if (j+1<m) c=rd[i-b+1][j+1]; else c=0;
                    ans=max(ans,a+b+c);
                }
            }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
