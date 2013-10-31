#include<stdio.h>
#include<string.h>
int s[10000];
int f[10][10];
int a,b,n;

int main()
{
    int tt,t=0;scanf("%d",&tt);
    while (tt--)
    {
        printf("Case #%d: ",++t);
        scanf("%d%d%d",&a,&b,&n);
        memset(s,0,sizeof(s));
        for (int i=0;i<10;i++)
          for (int j=0;j<10;j++) f[i][j]=-1;
        s[0]=a;s[1]=b;int m=2;
        while (f[a][b]==-1)
        {
            f[a][b]=m-2;
            int sum=a+b;
            if (sum>9) {s[m++]=1;sum-=10;}
            s[m++]=sum;
            a=s[m-2];b=s[m-1];
        }
        int u=f[a][b],v=m-2-u;
        if (n<=m) printf("%d\n",s[n-1]);
        else printf("%d\n",s[(n-1-f[a][b])%v+f[a][b]]);
    }
    return 0;
}
