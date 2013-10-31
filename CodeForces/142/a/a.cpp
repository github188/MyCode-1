#include<stdio.h>
#include<string.h>
int a[100][10000][2];
int n,m;
char b[100][10000];

int main()
{
    scanf("%d%d",&n,&m);
    bool check=false;
    for (int i=0;i<n;i++)
    {
        check=true;
        int k=-1,l=-1;
        scanf("%s",b[i]);
        for (int j=0;j<m;j++)
        {
            if (b[i][j]=='1')
            {
                k=j;
                if (l==-1) l=j;
                check=false;
            }
        }
        if (check) break;
        a[i][k][0]=0;
        int tmp=k;
        do
        {
            int last=tmp+1;if (last==m) last=0;
            if (b[i][last]=='1') a[i][last][0]=0;
            else a[i][last][0]=a[i][tmp][0]+1;
            tmp=last;
        } while (tmp!=k);
        a[i][k][0]=0;

        a[i][l][1]=0;
        tmp=l;
        do
        {
            int last=tmp-1;if (last<0) last=m-1;
            if (b[i][last]=='1') a[i][last][1]=0;
            else a[i][last][1]=a[i][tmp][1]+1;
            tmp=last;
        } while (tmp!=l);
        a[i][l][1]=0;
    }
    if (check) {printf("-1\n");return 0;}
    int ans=-1;
    for (int i=0;i<m;i++)
    {
        int sum=0;
        for (int j=0;j<n;j++) sum+=a[j][i][0]<a[j][i][1]?a[j][i][0]:a[j][i][1];
        if ((ans==-1)||(sum<ans)) ans=sum;
    }
    printf("%d\n",ans);
    return 0;
}
