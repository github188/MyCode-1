#include<stdio.h>
#include<string.h>
int mod=1000000007;
int c[1001][1001],eight[1001],two[1001],f[1001][1001],a[1001];
char s1[1001],s2[1001];

bool isL(char s[])
{
    int ln=0,len=strlen(s);
    for (int i=0;i<len;i++)
    if ((s[i]=='4')||(s[i]=='7')) ln++;
    for (int i=1;i<=a[0];i++) if (a[i]==ln) return true;
    return false;
}

int work(char s[])
{
    int ln=0,len=strlen(s),ans=0;
    for (int i=0;i<len;i++)
    {
      for (int no=0;no<s[i]-'0';no++)
      {
          int l=ln;
          if ((no==4)||(no==7)) l++;
          for (int j=1;j<=a[0];j++)
          if (a[j]-l>len-i-1) {break;}
          else
          {
              if (a[j]-l>=0) ans=(ans+f[len-i-1][a[j]-l])%mod;
          }
      }
      if ((s[i]=='4')||(s[i]=='7')) ln++;
    }
    if (isL(s)) ans++;ans%=mod;
    return ans;
}

int main()
{
    eight[0]=two[0]=1;c[0][0]=1;
    for (int i=1;i<=1000;i++)
    {
        c[i][0]=1;
        two[i]=(two[i-1]*2)%mod;
        long long u=eight[i-1],v=8,mm=mod;u=(u*v)%mm;
        eight[i]=u;
    }
    for (int i=1;i<=1000;i++)
     for (int j=1;j<=i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    for (int i=0;i<=1000;i++)
      for (int j=0;j<=i;j++)
      {
          long long u=eight[i-j],v=c[i][j],w=two[j],mm=mod;
          u=(u*v)%mm;
          u=(u*w)%mm;
          f[i][j]=u;
      }

    a[0]=0;
    for (int i=1;i<=1000;i++)
    {
        int k=i,j=0;
        bool check=true;
        while (k!=0)
        {
            if (((k%10)!=4)&&((k%10)!=7)) {check=false;}
            j++;k/=10;
        }
        if (check)
        {
            a[0]++;
            a[a[0]]=i;
        }
    }
    int tt;scanf("%d",&tt);gets(s1);
    while (tt>0)
    {
        tt--;
        scanf("%s %s",&s1,&s2);
        int u=work(s1),v=work(s2);
        v-=u;
        if (v<0) v+=mod;
        if (isL(s1)) v++;
        v%=mod;
        printf("%d\n",v);
    }

    return 0;
}
