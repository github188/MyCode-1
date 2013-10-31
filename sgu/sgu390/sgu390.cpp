#include<iostream>
#include<stdio.h>
using namespace std;

struct node
{
    long long x;
    int y;
} f[19][165][1001];
long long l,r;
int k;
int a[20],b[20];
long long t[19];

int main()
{
    bool isOne=false;
    long long maxl=1000;
    long long ten=10;
    maxl=maxl*maxl*maxl;
    maxl=maxl*maxl;
    cin>>l>>r>>k;
    if (r==maxl) {r--;isOne=true;}
    if (r<l)
    {
        if (k==1) {printf("1\n");} else {printf("0\n");}
        return 0;
    }
    t[0]=1;
    for (int i=1;i<19;i++) t[i]=t[i-1]*ten;

    long long ans=0;
    for (int i=0;i<19;i++)
      for (int j=0;j<=162;j++)
        for (int h=0;h<k;h++) f[i][j][h].x=-1;
    for (int i=0;i<=162;i++)
     for (int j=0;j<k;j++)
    if (i+j<k)
    {
        f[0][i][j].x=0;
        f[0][i][j].y=i+j;
    } else
    {
        f[0][i][j].x=1;
        f[0][i][j].y=0;
    }
    for (int i=1;i<19;i++)
     for (int j=0;j<=162-i*9;j++)
      for (int h=0;h<k;h++)
      {
          long long tmp=0;
          int res=h;
          for (int l=0;l<10;l++)
          if (f[i-1][j+l][res].x==-1) {tmp=-1;break;}
          else
          {
              tmp+=f[i-1][j+l][res].x;
              res=f[i-1][j+l][res].y;
          }

          if (tmp!=-1)
          {
              f[i][j][h].x=tmp;
              f[i][j][h].y=res;
          }
      }

    a[0]=b[0]=0;
    long long ll=l,num=l;
    int sum=0;
    while (ll>0) {a[++a[0]]=ll%ten;ll/=ten;sum+=a[a[0]];}
    int h=0;
    int res=0;
    while (true)
    {
        if (num+t[h]>r) break;
        ans+=f[h][sum][res].x;
        res=f[h][sum][res].y;
        if (((num/t[h])%ten)==9)
        {
            num+=t[h];
            h++;
            sum=0;
            long long tmp=num;
            while (tmp>0)
            {
                sum+=tmp%ten;
                tmp/=ten;
            }
        } else
        {
            num+=t[h];
            sum++;
        }
        if (num+t[h]>r) break;
    }
    h--;

    while (h>=0)
    {
        if (num+t[h]>r) {h--;continue;}
        ans+=f[h][sum][res].x;
        res=f[h][sum][res].y;
        num+=t[h];
        sum++;
    }
    ans+=f[0][sum][res].x;
    res=f[0][sum][res].y;
    if (isOne)
    {
        res++;
        if (res>=k) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
