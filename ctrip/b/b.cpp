#include<stdio.h>
#include<string.h>
#include<math.h>
bool f[801][801];
int a[40];
struct node
{
    int x,y;
} g[650000];

int main()
{
    while (true)
    {
        int n;scanf("%d",&n);
        if (n==0) break;int len=0;
        for (int i=0;i<n;i++) {scanf("%d",&a[i]);len+=a[i];}
        memset(f,false,sizeof(f));
        f[0][0]=true;
        int m=1;
        g[0].x=0;g[0].y=0;
        for (int i=0;i<n;i++)
        {
            int k=m-1;
            while (k>0)
            {
                int x=g[k].x+a[i],y=g[k].y;
                if ((x<=800)&&(y<=800)&&(!f[x][y]))
                {
                    g[m].x=x;g[m].y=y;m++;
                    f[x][y]=true;
                }
                x=g[k].x,y=g[k].y+a[i];
                if ((x<=800)&&(y<=800)&&(!f[x][y]))
                {
                    g[m].x=x;g[m].y=y;m++;
                    f[x][y]=true;
                }
                k--;
            }
        }
        double ans=-1;
        for (int i=0;i<=800;i++)
            for (int j=0;j<=800;j++)
                if (f[i][j])
                {
                    double x=i,y=j,z=len-i-j;
                    double p=(x+y+z)/2.0;
                    if ((p<=x)||(p<=y)||(p<=z)) continue;
                    double area=sqrt(p*(p-x)*(p-y)*(p-z));
                    if (area>ans) ans=area;
                }
        if (ans<0) printf("-1\n");
        else printf("%d\n",(int)(ans*100.0));
    }
    return 0;
}
