#include<stdio.h>
#include<string.h>
int f[55][60000];

int main()
{
    for (int i=0;i<55000;i++) {f[0][i]=(i&1);}
    f[1][0]=1;
    for (int i=1;i<=50;i++)
    {
        int tmp=0;
        if (f[i][0]==0) tmp=1;
        if ((i>0)&&(f[i-1][2]==0)) tmp=1;
        f[i+1][0]=tmp;
     for (int j=1;j<55000;j++)
     {
         int tmp=0;
         if ((j==1)&&(f[i+1][0]==1)) tmp=1;
         if (j>1) {
         if (f[i-1][j]==0) tmp=1;
         if ((j>1)&&(f[i][j-1]==0)) tmp=1;
         if ((j+1<=55000)&&(f[i-1][j+1]==0)) tmp=1;
         if ((j+3<=55000)&&(i>1)&&(f[i-2][j+3]==0)) tmp=1;}
         f[i][j]=tmp;
     }
    }

    int tt;
    scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        int n;
        scanf("%d",&n);
        int a,b;
        a=b=0;
        for (int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            if (x==1) {a++;} else {b+=x;}
        }
        if (a<n) b+=n-a-1;
        printf("Case #%d: ",t);
        if (f[a][b]) printf("Alice\n"); else {printf("Bob\n");}
    }
    return 0;
}
