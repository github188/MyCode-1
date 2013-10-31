#include<stdio.h>
#include<iostream>
using namespace std;
int a[100],b[2000000];
long long p[500000][20];
int n;
long long base,mod;

int maxp(int s,int t)
{
    if (p[s][0]>p[t][0]) {return s;}
    if (p[t][0]>p[s][0]) {return t;}
    for (int i=p[s][0];i>0;i--) 
    {
        if (p[s][i]>p[t][i]) {return s;}
        if (p[t][i]>p[s][i]) {return t;}
    }
    return s;
}

void mul(int k,int m)
{
     p[m][0]=p[k][0];
     long long u=b[m];
     for (int i=1;i<=p[k][0];i++) {p[m][i]=p[k][i]*u;}
     p[m][p[m][0]+1]=0;
     for (int i=1;i<=p[m][0];i++)
     {
         p[m][i+1]+=p[m][i]/base;
         p[m][i]=p[m][i]%base;
     }
     while (p[m][p[m][0]+1]>0)
     {
           p[m][0]++;
           p[m][p[m][0]+1]=p[m][p[m][0]]/base;
           p[m][p[m][0]]=p[m][p[m][0]]%base;
     }
}

int main()
{
    a[0]=1;
    for (int i=1;i<=15;i++) {a[i]=a[i-1]*2;}
    int tt;tt=1;
    mod=1000000007;
    base=1000000000;
    while (tt>0)
    {         
          scanf("%d",&n);
          if (n==0) {break;}
          for (int i=1;i<a[n];i++) {scanf("%d",&b[i]);}
          for (int i=a[n]-1;i>0;i--)
          if (i*2>a[n]-1) {p[i][0]=1;p[i][1]=b[i];} else
          {
                     p[i][0]=0;   
                     int k=maxp(i*2,i*2+1);
                     mul(k,i);
          }
          
          long long ans;ans=0;
          for (int i=p[1][0];i>0;i--)
          {
              ans=ans*base+p[1][i];
              ans=ans%mod;
          }
          cout<<ans<<endl;
    }
    return 0;
}
