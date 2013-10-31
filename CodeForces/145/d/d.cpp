#include<stdio.h>
char s[100];
int b[100][2],ans[100];
int n,m,k;
bool a[101];

int min(int o,int p)
{
    return o<p?o:p;
}

int max(int o,int p)
{
    return o>p?o:p;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&m,&k);
    for (int i=0;i<k;i++) {int x;scanf("%d",&x);a[x]=true;}
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%s",s);
        int d;
        scanf("%d",&d);
        int x,y,z;x=y=z=0;
        while (d--)
        {
            int u;
            scanf("%d",&u);
            if (u==0) x++; else
            if (a[u]) y++; else z++;
        }
        b[i][0]=y+max(0,x-(m-k-z));
        b[i][1]=y+min(x,k-y);
    }

    int dl=0,ul=0;
    for (int i=0;i<n;i++) dl=dl>b[i][0]?dl:b[i][0];
    for (int i=0;i<n;i++) ul=ul>b[i][1]?ul:b[i][1];
    for (int j=dl;j<=ul;j++)
    {
        int u=0,v=0;
        for (int i=0;i<n;i++)
        {
            if ((b[i][0]>j)||(b[i][1]<j)) ans[i]|=1; else {u++;v=i;}
        }
        if (u==1) {ans[v]|=2;continue;}
        for (int i=0;i<n;i++)
        {
            if ((b[i][0]<=j)&&(b[i][1]>=j))
            {
                ans[i]|=2;
                if (b[i][0]<j) ans[i]|=1;
            }
        }
    }
    for (int i=0;i<n;i++)
    {
        if (ans[i]==1) printf("1\n"); else
        if (ans[i]==2) printf("0\n"); else printf("2\n");
    }
    return 0;
}
