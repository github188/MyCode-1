#include<stdio.h>

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int tt;scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        int first[4][4],second[4][4];
        int c1,c2;
        scanf("%d",&c1);
        for (int i=0;i<4;i++)
            for (int j=0;j<4;j++) scanf("%d",&first[i][j]);
        scanf("%d",&c2);
        for (int i=0;i<4;i++)
            for (int j=0;j<4;j++) scanf("%d",&second[i][j]);
        int num=0,ans=0;c1--;c2--;
        for (int k=0;k<4;k++)
            for (int l=0;l<4;l++)
                if (first[c1][k]==second[c2][l]) {num++;ans=first[c1][k];}
        printf("Case #%d: ",t);
        if (num==1) printf("%d\n",ans);
        else if (num==0) printf("Volunteer cheated!\n"); else printf("Bad magician!\n");
    }
    return 0;
}
