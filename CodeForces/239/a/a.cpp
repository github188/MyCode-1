#include<stdio.h>
int a[1001][2];

int gcd(int x,int y)
{
    if (x<y) {int z=x;x=y;y=z;}
    if (y==0) return x;
    return gcd(y,x%y);
}

int main()
{
    int x,y;scanf("%d%d",&x,&y);
    if (x>y) {int z=x;x=y;y=z;}
    int tmp=gcd(x,y);
    int x1=-1,y1=-1,x2=-1,y2=-1;
    for (int i=1;i<tmp;i++)
        for (int j=i+1;j<tmp;j++)
            if ((i*i+j*j==tmp*tmp))
                if (j*x/tmp!=i*y/tmp)
                {
                    x1=j*y/tmp;y1=i*y/tmp;
                    x2=i*x/tmp;y2=j*x/tmp;
                } else
                {
                    x1=i*y/tmp;y1=j*y/tmp;
                    x2=j*x/tmp;y2=i*x/tmp;
                }
    if (x1==-1) printf("NO\n"); else printf("YES\n0 0\n%d %d\n%d %d\n",x1,y1,-x2,y2);
    return 0;
}
