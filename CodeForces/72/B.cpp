#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<stdio.h>
using namespace std;

int a[100000],b[100000],c[100000][2];
int n,m;
long long k,sum;

int main()
{
    cin>>n>>k;sum=0;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];long long aa=a[i];
        sum+=aa;
    }
    if (sum<=k)
    {
               if (sum<k) {printf("-1\n");}      
               return 0;
    }
    
    sort(b,b+n);
    m=0;
    c[0][0]=b[0];c[0][1]=0;
    for (int i=1;i<n;i++)
    if (b[i]!=b[i-1])
    {
       m++;
       c[m][0]=b[i];
       c[m][1]=i;
    }
    
    int pre=0;
    for (int i=0;i<=m;i++)
    {
        long long u,v,duc;
        v=c[i][0]-pre;
        u=n-c[i][1];duc=u*v;
        if (duc<=k) {k-=duc;}
        else
        {
            int h=-1;
            for (int j=0;j<n;j++)
            if (a[j]>=c[i][0])
            {
               h++;
               a[h]=a[j];
               b[h]=j;
            }
            long long s,t;
            s=k/u;
            t=k%u;
            int tt,ss;tt=t;ss=s;
            for (int j=tt;j<=h;j++)
            {
                if (j!=tt) {printf(" ");}
                printf("%d",b[j]+1);
            }
            
            for (int j=0;j<tt;j++)
            if ((ss+1!=v)||(a[j]!=c[i][0]))
            {
                printf(" %d",b[j]+1);
            }
            printf("\n");
            break;
        }
        
        pre=c[i][0];
    }
    
    return 0;
}
