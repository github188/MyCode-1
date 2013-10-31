#include<stdio.h>
#include<math.h>
#include<map>
#include<string.h>
#define N 5000
using namespace std;
int f[20][2];
int n,t,x,y,k,ax,ay,bx,by;
long long mod=1000000007;
double eps=1e-10;
//long long C[N][N];
#define maxn 100010
#define MOD 1000000007
#define LL long long

using namespace std;

int a[maxn];
map<int,int> p;
LL g[maxn];
int ff[2000];

bool islucky(int p) {
    while (p>0) {
        if (p % 10!=7 && p % 10!=4) return false;
        p/=10;
    }
    return true;
}

LL pow(int a,int b) {
    LL ans=1,tmp=a;
    for (int i=0;i<=30;++i) {
        if ((b >> i) & 1) ans=(ans*tmp) % MOD;
        tmp=(tmp*tmp) % MOD;
    }
    return ans % MOD;
}

int c(int n,int k) {
    LL ans=g[n];
    ans=(ans*pow(g[k],MOD-2)) % MOD;
    ans=(ans*pow(g[n-k],MOD-2)) % MOD;
    return ans;
}

int CC(int n,int k)
{
    //freopen("c.in","r",stdin);
    int cnt=0;
    p.clear();
    g[0]=1;
    for (int i=1;i<=n;++i)
        g[i]=g[i-1]*(LL)i % MOD;
    int ans=c(n,k);
  return ans;
}
bool check(int o)
{
    int num=0;
    while (o>0)
    {
        if (o&1) num++;
        o>>=1;
    }
    return ((num&1)==1);
}

bool checkint(double u)
{
    double v=(int)u;
    if ((fabs(u-v)>eps)&&(fabs(u-(v+1))>eps)) return false;
    if (u<0) return false;
    return true;
}

bool calc(int x,int y)
{
    double matrix[2][3];
    matrix[0][0]=ax;
    matrix[0][1]=bx;
    matrix[1][0]=ay;
    matrix[1][1]=by;
    matrix[0][2]=x;
    matrix[1][2]=y;
    bool use[2];
    use[0]=use[1]=false;
    for (int i=0;i<2;i++)
    {
        bool check=false;
        for (int j=0;j<2;j++)
        if ((fabs(matrix[i][j])>eps)&&(!use[j]))
        {
            use[j]=true;
            double tmp=matrix[j][i];
            for (int k=0;k<3;k++) matrix[j][k]/=tmp;
            for (int k=0;k<2;k++)
            if ((fabs(matrix[k][j])>eps)&&(k!=j))
            {
                double tmp=matrix[k][i];
                matrix[k][0]-=matrix[j][0]*tmp;
                matrix[k][1]-=matrix[j][1]*tmp;
                matrix[k][2]-=matrix[j][2]*tmp;
            }
            check=true;
            break;
        }
        if (!check) return false;
    }

    if (fabs(matrix[0][0])<eps)
    {
        double tmp=matrix[0][0];matrix[0][0]=matrix[1][0];matrix[1][0]=tmp;
        tmp=matrix[0][1];matrix[0][1]=matrix[1][1];matrix[1][1]=tmp;
        tmp=matrix[0][2];matrix[0][2]=matrix[1][2];matrix[1][2]=tmp;
    }
    if ((!checkint(matrix[0][0]))||
       (!checkint(matrix[0][2]))||
       (!checkint(matrix[1][1]))||
       (!checkint(matrix[1][2]))) return false;
    return true;
}

int calc1(int x,int y)
{
    double matrix[2][3];
    matrix[0][0]=ax;
    matrix[0][1]=bx;
    matrix[1][0]=ay;
    matrix[1][1]=by;
    matrix[0][2]=x;
    matrix[1][2]=y;
    bool use[2];
    use[0]=use[1]=false;
    for (int i=0;i<2;i++)
    {
        bool check=false;
        for (int j=0;j<2;j++)
        if ((fabs(matrix[i][j])>eps)&&(!use[j]))
        {
            use[j]=true;
            double tmp=matrix[j][i];
            for (int k=0;k<3;k++) matrix[j][k]/=tmp;
            for (int k=0;k<2;k++)
            if ((fabs(matrix[k][j])>eps)&&(k!=j))
            {
                double tmp=matrix[k][i];
                matrix[k][0]-=matrix[j][0]*tmp;
                matrix[k][1]-=matrix[j][1]*tmp;
                matrix[k][2]-=matrix[j][2]*tmp;
            }
            check=true;
            break;
        }
        if (!check) return 0;
    }

    if (fabs(matrix[0][0])<eps)
    {
        double tmp=matrix[0][0];matrix[0][0]=matrix[1][0];matrix[1][0]=tmp;
        tmp=matrix[0][1];matrix[0][1]=matrix[1][1];matrix[1][1]=tmp;
        tmp=matrix[0][2];matrix[0][2]=matrix[1][2];matrix[1][2]=tmp;
    }
    if ((!checkint(matrix[0][0]))||
       (!checkint(matrix[0][2]))||
       (!checkint(matrix[1][1]))||
       (!checkint(matrix[1][2]))) return 0;
    int u=(int)matrix[0][2];
    if (fabs(matrix[0][2]-u)>eps) u++;
    int v=(int)matrix[1][2];
    if (fabs(matrix[1][2]-v)>eps) v++;
    int ans=CC(u+v,u);

    return ans;
}

int work(int o)
{
    int ans=0,size=0;
    int g[20][2],l[20];
    for (int i=0;i<20;i++) l[i]=0;
    g[0][0]=g[0][1]=0;
    g[1][0]=x;g[1][1]=y;
    size=2;
    int k=0;
    while (o>0)
    {
        if (o&1)
        {
            g[size][0]=f[k][0];
            g[size][1]=f[k][1];
            size++;
        }
        k++;
        o>>=1;
    }
    int h[20][20];
    for (int i=0;i<size;i++)
     for (int j=0;j<size;j++)
      {
          h[i][j]=0;
          if ((i!=j)&&(calc(g[j][0]-g[i][0],g[j][1]-g[i][1]))) {h[i][j]=1;l[j]++;}
      }
    int stack[20];
    int u=0,ui=0;
    long long ans1=1;
    do
    {
        if (u==0) {for (int i=0;i<size;i++) if (l[i]==0) stack[u++]=i;ui=stack[0];}
        if (u!=1) return 0;
        u--;
        if (ui!=stack[0])
        {
            ans1*=calc1(g[stack[0]][0]-g[ui][0],g[stack[0]][1]-g[ui][1])%mod;
            ui=stack[0];
            for (int i=0;i<size;i++)
            if (h[ui][i]==1)
            {
                l[i]--;
                if (l[i]==0)
                stack[u++]=i;
            }
        } else
        {
            for (int i=0;i<size;i++)
            if (h[ui][i]==1)
            {
                l[i]--;
                if (l[i]==0)
                stack[u++]=i;
            }
        }
    } while (u>0);

    ans=ans1;
    return ans;
}

int main()
{/*
    C[0][0]=1;
    for (int i=1;i<N;i++)
      for (int j=0;j<=i;j++)
      {
          C[i][j]=C[i-1][j];
          if (j>0) {C[i][j]+=C[i-1][j-1];C[i][j]%=mod;}
      }*/

    scanf("%d",&t);
    while (t>0)
    {
        t--;
        scanf("%d%d%d",&x,&y,&k);
        scanf("%d%d%d%d",&ax,&ay,&bx,&by);
        for (int i=0;i<k;i++) scanf("%d%d",&f[i][0],&f[i][1]);

        long long ans=work(0);
        if (ans!=0)
        {
           if (ax*by==ay*bx) {printf("-1\n");continue;}
           for (int i=1;i<(1<<k);i++)
           {
            long long tmp=work(i);
            if (check(i)) tmp=-tmp;
            ans+=tmp;
            if (ans<0) ans+=mod;
            if (ans>=mod) ans%=mod;
           }
        }
        printf("%d\n",ans);
    }
    return 0;
}
