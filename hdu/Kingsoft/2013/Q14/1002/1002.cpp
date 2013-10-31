#include<stdio.h>
long long x0,y0,z0,x1,y1,z1,x2,y2,z2,lx,rx,ly,ry,lz,rz;
long long a,b,c,d,ans;

bool check()
{
    if ((x1-x0)*(y2-y0)!=(y1-y0)*(x2-x0)) return false;
    if ((x1-x0)*(z2-z0)!=(z1-z0)*(x2-x0)) return false;
    if ((y1-y0)*(z2-z0)!=(z1-z0)*(y2-y0)) return false;
    return true;
}

long long gcd(long long o,long long p)
{
    if (p>o) {long long q=o;o=p;p=q;}
    if (p==0) return o;return gcd(p,o%p);
}

long long exGcd(long long a, long long b, long long &x, long long &y)
{
if(b == 0)
{
x = 1;
y = 0;
return a;
}
long long r = exGcd(b, a % b, x, y);
long long t = x;
x = y;
y = t ¨C a / b * y;
return r;
}

inline void judge(long long x)
{
    if ((b==0)&&(c==0))
    {
        if (a*x+d==0) ans+=(ry-ly)*(rz-lz);
        return;
    }
    long long u=-(a*x+d);
    if (b==0)
    {
        if ((u%c)==0) ans++;
        return;
    }
    if (c==0)
    {
        if ((u%b)==0) ans++;
        return;
    }
    long long g=gcd(b,c);
}

int main()
{
    while (scanf("%d%d%d%d%d%d%d%d%d%d",&x0,&y0,&z0,&x1,&y1,&z1,&x2,&y2,&z2,&lx,&rx,&ly,&ry,&lz,&rz)!=EOF)
    {
        if (check())
        {
            printf("-1\n");
            continue;
        }
        a=(y1-y0)*(z2-z0)-(z1-z0)*(y2-y0);
        b=(z1-z0)*(x2-x0)-(x1-x0)*(z2-z0);
        c=(x1-x0)*(y2-y0)-(y1-y0)*(x2-x0);
        d=-x0*a-y0*b-z0*c;
        ans=0;
        for (long long i=lx;i<=rx;i++) judge(i);
        printf("%I64d\n",ans);
    }
    return 0;
}
