#include<stdio.h>

int a[100][100];
bool row[100][100],col[100][100];
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) scanf("%d",&a[i][j]);
    for (int i=0;i<n;i++)
    {
        int k=100000000;
        for (int j=0;j<m;j++) if (a[i][j]<k) k=a[i][j];
        for (int j=0;j<m;j++) if (a[i][j]==k) row[i][j]=true;
    }

    for (int j=0;j<m;j++)
    {
        int k=0;
        for (int i=0;i<n;i++) if (a[i][j]>k) k=a[i][j];
        for (int i=0;i<n;i++) if (a[i][j]==k) col[i][j]=true;
    }

    int ans=0;
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) if (row[i][j]&col[i][j]) ans=a[i][j];
    if (ans==0) {printf("GUESS\n");} else printf("%d\n",ans);
    return 0;
}
