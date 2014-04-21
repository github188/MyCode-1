#include<stdio.h>
#include<math.h>
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point{double x,y;};
struct line{point a,b;};
char s[50][50];
double a[50][2];
int n,m,tot;
int f[50],d[10000][100];

double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

bool dots_inline(point p1,point p2,point p3){
	return zero(xmult(p1,p2,p3));
}
bool dot_online_in(point p,point l1,point l2){
	return zero(xmult(p,l1,l2))&&(l1.x-p.x)*(l2.x-p.x)<eps&&(l1.y-p.y)*(l2.y-p.y)<eps;
}
bool same_side(point p1,point p2,point l1,point l2){
	return xmult(l1,p1,l2)*xmult(l1,p2,l2)>eps;
}


bool intersect_in(point u1,point u2,point v1,point v2){
	if (!dots_inline(u1,u2,v1)||!dots_inline(u1,u2,v2))
		return !same_side(u1,u2,v1,v2)&&!same_side(v1,v2,u1,u2);
	return dot_online_in(u1,v1,v2)||dot_online_in(u2,v1,v2)||dot_online_in(v1,u1,u2)||dot_online_in(v2,u1,u2);
}

bool crossline(int x1,int x2,int y1,int y2)
{
    point u1,u2,v1,v2;
    u1.x=a[x1][0];u1.y=a[x1][1];
    u2.x=a[x2][0];u2.y=a[x2][1];
    v1.x=a[y1][0];v1.y=a[y1][1];
    v2.x=a[y2][0];v2.y=a[y2][1];
    return intersect_in(u1,u2,v1,v2);
}

bool check(int o,int p,int m)
{
    for (int i=2;i<d[m][0];i++)
    {
        if (d[m][i]==p) return false;
        if ((crossline(o,p,d[m][i],d[m][i-1]))&&((p!=d[m][1])||((p==d[m][1])&&(i!=2)))) return false;
    }
    return true;
}

void dfs(int o)
{
    int p=-1,q=-1;
    for (int i=0;i<n;i++)
        if ((s[o][i]=='Y')&&(check(o,i,m)))
        {
            if (f[i]>p) p=f[i],q=i;
        }
    if (p>=0){
    d[m][++d[m][0]]=q;
    s[o][q]=s[q][o]='N';
    f[o]--;f[q]--;tot--;
    if (q==d[m][1]) return;
    dfs(q);}
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%lf%lf",&a[i][0],&a[i][1]);
    tot=0;
    for (int i=0;i<n;i++)
    {
        scanf("%s",s[i]);
        for (int j=0;j<n;j++)
            if (s[i][j]=='Y') f[i]++;
        tot+=f[i];
    }
    tot/=2;m=0;
    while (tot>0)
    {
        int u=n,v=-1;
        for (int i=n-1;i>=0;i--)
            if ((f[i]>0)&&(f[i]<u)) u=f[i],v=i;
        if (v<0) break;
        d[m][0]=1;d[m][1]=v;
        dfs(v);
        m++;
    }
    printf("%d\n",m);
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<=d[i][0];j++)
        {
            if (j==0) printf("%d",d[i][j]-1); else printf("%d",d[i][j]);
            if (j!=d[i][0]) printf(" "); else printf("\n");
        }
    }
    return 0;
}
