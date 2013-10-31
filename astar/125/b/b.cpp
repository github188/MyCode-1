#include<stdio.h>
#include<string.h>
char w[2][100000];
int n,k;
int a[2][100000],q[2][300000][2],qt[2];

int main()
{
    scanf("%d%d",&n,&k);
    gets(w[0]);
    gets(w[0]);
    gets(w[1]);
    for (int i=0;i<n;i++) a[0][i]=a[1][i]=-1;
    a[0][0]=0;
    qt[0]=1;
    q[0][0][0]=0;
    q[0][0][1]=0;
    int l=0,t=0;
    bool check=false;
    while ((qt[l]!=0)&&(!check))
    {
        qt[l^1]=0;
        for (int i=0;i<qt[l];i++)
        {
            int pos=q[l][i][0],h=q[l][i][1];
            if ((h+1>=n)||(h+k>=n)) {check=true;break;}
            if ((w[pos][h+1]=='-')&&(a[pos][h+1]==-1))
            {
                a[pos][h+1]=0;
                q[l^1][qt[l^1]][0]=pos;
                q[l^1][qt[l^1]][1]=h+1;
                qt[l^1]++;
            }
            if ((w[pos^1][h+k]=='-')&&(a[pos^1][h+k]==-1))
            {
                a[pos^1][h+k]=0;
                q[l^1][qt[l^1]][0]=pos^1;
                q[l^1][qt[l^1]][1]=h+k;
                qt[l^1]++;
            }
            if ((w[pos][h-1]=='-')&&(a[pos][h-1]==-1)&&(h-1>t))
            {
                a[pos][h-1]=0;
                q[l^1][qt[l^1]][0]=pos;
                q[l^1][qt[l^1]][1]=h-1;
                qt[l^1]++;
            }
        }
        t++;
        l^=1;
    }
    if (!check) {printf("NO\n");} else {printf("YES\n");}
    return 0;
}
