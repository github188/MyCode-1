#include<stdio.h>
#include<string.h>
double f[101][101];
int g[101][101];
int n,m;
char s[500];

int main()
{
    scanf("%d",&m);
    for (int t=0;t<m;t++)
    {
        scanf("%d",&n);gets(s);
        for (int j=1;j<=n;j++)
         for (int k=1;k<=n;k++) f[j][k]=300;
         
        for (int i=1;i<=n;i++)
        {
            g[i][0]=0;
            gets(s);
            int len=strlen(s);
            int l=0;
            while (l<len)
            {
                  int num=0;
                  while ((l<len)&&(s[l]!=' ')) {num=num*10+s[l]-'0';l++;}
                  l++;
                  f[num][i]=f[i][num]=1;
            }
        }
        
        for (int i=1;i<=n;i++) {f[i][i]=0;}
        for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
          for (int k=1;k<=n;k++)
           if (f[j][k]>f[j][i]+f[i][k]) {f[j][k]=f[k][j]=f[j][i]+f[i][k];}
           
        int ans1,ans2;ans2=100000000;
        for (int i=1;i<=n;i++)
        {
            int sum=0;
            for (int j=1;j<=n;j++) {sum+=f[i][j];}
            if (sum<ans2) {ans1=i;ans2=sum;}
        }
        double nn,nnn,ans;
        nn=n;nnn=ans2;
        ans=nnn/nn;
        printf("%d %.6f\n",ans1,ans);
    }
    
    return 0;
}
