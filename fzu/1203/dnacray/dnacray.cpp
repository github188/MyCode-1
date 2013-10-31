#include<stdio.h>
#include<math.h>
int m,na,nb,nc,up,down;
float ya,yb,yc,upmin,downmin;
float a[1310],b[1310],c[1310],ans[1310];
float dp[1310][1310][2];
int s[1310][1310][2];

inline float dis(float x1,float y1,float x2,float y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
    freopen("input3.008","r",stdin);
    freopen("output3.008","w",stdout);
    scanf("%d%d%d",&na,&nb,&nc);
    scanf("%f%f%f",&ya,&yb,&yc);
    for (int i=1;i<=na;i++) scanf("%f",&a[i]);
    for (int i=1;i<=nb;i++) scanf("%f",&b[i]);
    for (int i=1;i<=nc;i++) scanf("%f",&c[i]);

    for (int i=1;i<=nb;i++)
    {
        upmin=1e9;
        downmin=1e9;
        for (int j=1;j<=na-1;j++)
            if (dis(a[j],ya,b[i],yb)+dis(a[j+1],ya,b[i],yb)<upmin)
                upmin=dis(a[j],ya,b[i],yb)+dis(a[j+1],ya,b[i],yb),up=j;
        for (int j=1;j<=nc-1;j++)
            if (dis(c[j],yc,b[i],yb)+dis(c[j+1],yc,b[i],yb)<downmin)
            downmin=dis(c[j],yc,b[i],yb)+dis(c[j+1],yc,b[i],yb),down=j;
        s[i][1][0]=up;
        dp[i][1][0]=upmin;
        s[i][1][1]=down;
        dp[i][1][1]=downmin;
    }

    s[1][1][0]=1;
    dp[1][1][0]=dis(a[1],ya,b[1],yb)+dis(c[1],yc,b[1],yb);
    s[1][1][1]=1;
    dp[1][1][1]=dis(a[1],ya,b[1],yb)+dis(c[1],yc,b[1],yb);
    s[nb][1][0]=na;
    dp[nb][1][0]=dis(a[na],ya,b[nb],yb)+dis(c[nc],yc,b[nb],yb);
    s[nb][1][1]=nc;
    dp[nb][1][1]=dis(a[na],ya,b[nb],yb)+dis(c[nc],yc,b[nb],yb);

    for (int i=2;i<=nb;i++)
    {
        dp[i][i][0]=dis(a[1],ya,b[1],yb)+dis(c[1],yc,b[i],yb)+b[i]-b[1];
        dp[i][i][1]=dis(a[1],ya,b[i],yb)+dis(c[1],yc,b[1],yb)+b[i]-b[1];
        s[i][i][0]=1;
        s[i][i][1]=1;
        for (int j=i+1;j<=nb-1;j++)
        {
            int h=j-i+1;
            dp[j][i][0]=1e9;
            for (int k=s[j-1][i][0];k<=s[j][i-1][0];k++)
            {
                if (dis(a[k],ya,b[h],yb)+dis(a[k+1],ya,b[j],yb)+b[j]-b[h]-a[k+1]+a[k]<dp[j][i][0])
                {
                    dp[j][i][0]=dis(a[k],ya,b[h],yb)+dis(a[k+1],ya,b[j],yb)+b[j]-b[h]-a[k+1]+a[k];
                    s[j][i][0]=k;
                }
            }
            dp[j][i][1]=1e9;
            for (int k=s[j-1][i][1];k<=s[j][i-1][1];k++)
            {
                if (dis(c[k],yc,b[h],yb)+dis(c[k+1],yc,b[j],yb)+b[j]-b[h]-c[k+1]+c[k]<dp[j][i][1])
                {
                    dp[j][i][1]=dis(c[k],yc,b[h],yb)+dis(c[k+1],yc,b[j],yb)+b[j]-b[h]-c[k+1]+c[k];
                    s[j][i][1]=k;
                }
            }
        }

        s[nb][i][0]=na;
        s[nb][i][1]=nc;
        dp[nb][i][0]=dis(a[na],ya,b[nb],yb)+dis(c[nc],yc,b[nb-i+1],yb)+b[nb]-b[nb-i+1];
        dp[nb][i][1]=dis(a[na],ya,b[nb-i+1],yb)+dis(c[nc],yc,b[nb],yb)+b[nb]-b[nb-i+1];
    }

    for (int i=1;i<=nb;i++)
    {
        ans[i]=1e10;
        if (i!=nb)
            for (int j=1;j<=i;j++)
            {
                if (ans[i-j]+dp[i][j][0]<ans[i]) ans[i]=ans[i-j]+dp[i][j][0];
                if (ans[i-j]+dp[i][j][1]<ans[i]) ans[i]=ans[i-j]+dp[i][j][1];
            }
        else
          for (int j=1;j<=i-1;j++)
          {
              if (ans[i-j]+dp[i][j][0]<ans[i]) ans[i]=ans[i-j]+dp[i][j][0];
              if (ans[i-j]+dp[i][j][1]<ans[i]) ans[i]=ans[i-j]+dp[i][j][1];
          }
    }

    if (nb<=1)
    {
        if (nb==0) printf("%.2f\n",dis(a[1],ya,c[1],yc)+dis(a[na],ya,c[nc],yc)
                                  +c[nc]-c[1]+a[na]-a[1]);
        else
        {
            ans[1]=dis(a[1],ya,b[1],yb)+dis(c[1],yc,b[1],yb)+dis(a[na],ya,c[nc],yc)+a[na]-a[1]+c[nc]-c[1];
            if (dis(a[na],ya,b[1],yb)+dis(c[nc],yc,b[1],yb)+dis(a[1],ya,c[1],yc)+a[na]-a[1]+c[nc]-c[1]<ans[1])
              ans[1]=dis(a[na],ya,b[1],yb)+dis(c[nc],yc,b[1],yb)+dis(a[1],ya,c[1],yc)+a[na]-a[1]+c[nc]-c[1];
            printf("%.2f\n",ans[1]);
        }
    }
    else printf("%.2f\n",ans[nb]+a[na]-a[1]+c[nc]-c[1]);
}
