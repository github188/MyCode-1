#include<stdio.h>

int a[100001][10],b[100001];
bool use[100001];
int n,m;

int main()
{
    scanf("%d %d",&n,&m);
    for (int i=2;i<=n;i++)
    if (a[i][0]==0)
    {
        b[i]=0;
        int j=0;
        while (j+i<=n)
        {
            j+=i;
            a[j][0]++;
            a[j][a[j][0]]=i;
        }
    }

    for (int i=0;i<m;i++)
    {
        char c;int k;
        scanf("%c",&c);
        scanf("%c %d",&c,&k);
        if (c=='+')
        {
            if (use[k]) {printf("Already on\n");continue;}bool check=true;
            for (int j=1;j<=a[k][0];j++)
            if (b[a[k][j]]!=0)
            {
                printf("Conflict with %d\n",b[a[k][j]]);check=false;
                break;
            }
            if (!check) continue;
            printf("Success\n");use[k]=true;
            for (int j=1;j<=a[k][0];j++)
            {
                b[a[k][j]]=k;
            }
        } else
        {
            if (!use[k]) {printf("Already off\n");continue;}
            for (int j=1;j<=a[k][0];j++)
            {
                b[a[k][j]]=0;
            }
            printf("Success\n");use[k]=false;
        }
    }

    return 0;
}
