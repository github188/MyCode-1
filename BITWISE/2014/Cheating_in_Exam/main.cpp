#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
char r[200001];
int n,k;
int C[2000001],wa[200001],wb[200001],wv[200001],suff[200001],H[200001];
int *x=wa,*y=wb,*t;
int cmp(int *c,int a,int b,int h)
{
    return c[a]==c[b]&&c[a+h]==c[b+h];
}
void CreatSuff(int len,int m)
{
         int p,h,i;
         for(i=0;i<m;i++)C[i]=0;
         for(i=0;i<len;i++) C[x[i]=r[i]]++;
         for(i=1;i<m;i++)C[i]+=C[i-1];
         for(i=len-1;i>=0;i--)suff[--C[x[i]]]=i;
         for(h=1,p=1;p<len;h<<=1,m=p)
         {
             for(p=0,i=len-h;i<len;i++)y[p++]=i;
             for(i=0;i<len;i++)
               if(suff[i]>=h)y[p++]=suff[i]-h;
             for(i=0;i<len;i++)wv[i]=x[y[i]];
             for(i=0;i<m;i++)C[i]=0;
             for(i=0;i<len;i++)C[wv[i]]++;
             for(i=1;i<m;i++)C[i]+=C[i-1];
             for(i=len-1;i>=0;i--)suff[--C[wv[i]]]=y[i];
             t=x;x=y;y=t;x[suff[0]]=0;
             for(p=1,i=1;i<len;i++)x[suff[i]]=cmp(y,suff[i-1],suff[i],h) ? p-1 : p++ ;
         }

}
void CalHeight()
{
      int k,p;
      for(k=0,p=0;p<=n;p++)
      {
              if(x[p]==0)H[x[p]]=0;
              else
              {
                     for(int i=suff[x[p]-1];r[p+k]==r[i+k];k++);
                         H[x[p]]=k;
                     if(k>0)
                         k--;
              }
      }
}
int pos;
int Check(int Middle)
{
      int s=1;
      for(int i=2;i<=n;i++)
      {
              if(H[i]>=Middle)
              {
                    s++;
                	if(s==k) {pos=i;return 1;}
              }
              else
                 s=1;
      }
      return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
               gets(r);n=strlen(r);scanf("%d",&k);
               r[n]=0;
               CreatSuff(n+1,2000001);
               CalHeight();
               int Min=1,Max=n,Middle;
               while(Min<=Max)
               {
                    Middle=(Min+Max)/2;
                    if(Check(Middle))
                        Min=Middle+1;
                    else
                        Max=Middle-1;
               }
               Min--;
               for (int i=0;i<Min;i++) printf("%c",r[suff[pos]+i]);printf("\n");
    return 0;
}
