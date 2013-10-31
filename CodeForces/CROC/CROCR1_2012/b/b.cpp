#include<stdio.h>
#include<string.h>
struct st
{
    int x,y,z;
};
int maxm=2000000;
st heap[1000001];
char s[1000][1000];
int a[1000][1001],b[1000][1001],q[2][1001];
int n,m;
bool use[1000],u[1000];

int main()
{
    scanf("%d%d",&n,&m);
    gets(s[0]);
    for (int i=0;i<n;i++) gets(s[i]);
    bool check=false;
    for (int i=0;i<m;i++) if (s[0][i]=='#') check=true;
    if (!check) {printf("-1\n");return 0;}
    else if (n==1) {printf("1\n");return 0;}
    for (int i=0;i<n;i++)
     for (int j=0;j<m;j++)
      if (s[i][j]=='#')
      {
          a[i][0]++;
          a[i][a[i][0]]=j;
      }
    for (int i=0;i<m;i++)
     for (int j=0;j<n;j++)
      if (s[j][i]=='#')
      {
          b[i][0]++;
          b[i][b[i][0]]=j;
      }
    int ans=0,l=0;
    q[0][0]=1;q[0][1]=0;use[0]=true;
    while ((q[l][0]!=0)&&(!use[n-1]))
    {
        ans+=2;q[l^1][0]=0;
        for (int i=1;i<=q[l][0];i++)
        {
            int j=q[l][i];
            for (int h=1;h<=a[j][0];h++)
            if (!u[a[j][h]])
            {
                u[a[j][h]]=true;
                int f=a[j][h];
                for (int k=1;k<=b[f][0];k++)
                if (!use[b[f][k]])
                {
                    use[b[f][k]]=true;
                    q[l^1][0]++;
                    q[l^1][q[l^1][0]]=b[f][k];
                }
            }
        }
        l^=1;
    }
    if (use[n-1]) {printf("%d\n",ans);} else {printf("-1\n");}
    return 0;
}
